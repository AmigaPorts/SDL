/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2020 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#include "SDL_audio.h"
#include "../SDL_audio_c.h"
#include "SDL_ahi_audio.h"
#include "../../core/morphos/SDL_cpu.h"

#include <machine/endian.h>
#include <sys/param.h>

#include <dos/dos.h>
#include <exec/execbase.h>
#include <proto/exec.h>

static void
AHIAUD_WaitDevice(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;
	struct AHIRequest *req = &hidden->req[hidden->current_buffer];

	if (req->ahir_Std.io_Data)
	{
		WaitIO((struct IORequest *)req);

		req->ahir_Std.io_Data = NULL;

		GetMsg(&hidden->ahiport);
	}
}

static void
AHIAUD_PlayDevice(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;
	struct AHIRequest *req;
	ULONG current, current2;
	
	current = hidden->current_buffer;
	current2 = current ^ 1;
	req = &hidden->req[current];

	req->ahir_Std.io_Data    = hidden->buffers[current];
	req->ahir_Std.io_Length  = this->spec.size;
	req->ahir_Std.io_Offset  = 0;
	req->ahir_Frequency      = this->spec.freq;
	req->ahir_Volume         = 0x10000;
	req->ahir_Type           = hidden->sample_format;
	req->ahir_Position       = 0x8000;
	req->ahir_Link           = (hidden->playing ? &hidden->req[current2] : NULL);

	hidden->current_buffer = current2;
	hidden->playing = 1;
	
	switch (hidden->convert)
	{
		case AMIAUD_CONVERT_NONE  : break;
		case AMIAUD_CONVERT_SWAP16: AMIGA_Swap16(hidden->buffers[current], hidden->buffers[current], this->spec.size / 2); break;
		case AMIAUD_CONVERT_SWAP32: AMIGA_Swap32(hidden->buffers[current], hidden->buffers[current], this->spec.size / 2); break;
	}

	SendIO((struct IORequest *)req);
}

static Uint8 *
AHIAUD_GetDeviceBuf(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;
	return (Uint8 *) hidden->buffers[hidden->current_buffer];
}

/*static void
AHIAUD_WaitDone(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;
	int i;

	for (i = 0; i < 2; i++)
	{
		struct AHIRequest *req = &hidden->req[i];

		if (req->ahir_Std.io_Data)
		{
			WaitIO((struct IORequest *)req);
		}
	}
}*/

static void
AHIAUD_CloseDevice(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;

	this->hidden = NULL;

	CloseDevice((struct IORequest *)&hidden->req[0].ahir_Std);
	SDL_free(hidden);
}

static void
AHIAUD_ThreadInit(_THIS)
{
	struct SDL_PrivateAudioData *hidden = this->hidden;

	hidden->ahiport.mp_Node.ln_Pri = 60;
	hidden->ahiport.mp_Flags = PA_SIGNAL;
	hidden->ahiport.mp_SigBit = SIGBREAKB_CTRL_E;
	hidden->ahiport.mp_SigTask = SysBase->ThisTask;

	NEWLIST(&hidden->ahiport.mp_MsgList);

	bcopy(&hidden->req[0], &hidden->req[1], sizeof(hidden->req[1]));
}

static int
AHIAUD_OpenDevice(_THIS, void *handle, const char *devname, int iscapture)
{
	struct SDL_PrivateAudioData *hidden;
	SDL_AudioFormat test_format;
	int sample_format = -1;
	UBYTE convert = AMIAUD_CONVERT_NONE;

	if (iscapture)
		return SDL_SetError("Capture not supported.");
	
	if ((this->spec.format & 0xff) != 8) {
		 this->spec.format = AUDIO_S16MSB;
	}

	
	
	test_format = SDL_FirstAudioFormat(this->spec.format);
	
	while (sample_format < 0 && test_format)
	{
		convert = AMIAUD_CONVERT_NONE;
		switch (test_format)
		{
			case AUDIO_U8: 
			case AUDIO_S8: 			
				sample_format = this->spec.channels == 1 ? AHIST_M8S : AHIST_S8S; break; 	
			break;
			case AUDIO_S16LSB://	convert = AMIAUD_CONVERT_SWAP16;
			case AUDIO_S16MSB: sample_format = this->spec.channels == 1 ? AHIST_M16S : AHIST_S16S; break;

			case AUDIO_S32LSB://convert = AMIAUD_CONVERT_SWAP32;
			case AUDIO_S32MSB: sample_format = this->spec.channels == 1 ? AHIST_M32S : AHIST_S32S; break;

			default:
				D("[%s] unsupported SDL format 0x%ld\n", __FUNCTION__, test_format);
				test_format = SDL_NextAudioFormat();
				break;
		}
	}

	if (sample_format < 0)
		return SDL_SetError("Unsupported audio format");

	D("[%s] AHI sample format is %ld\n", __FUNCTION__, sample_format);

	if (this->spec.channels > 2)
		this->spec.channels = 2;

	if (this->spec.samples > 1024)
	{
		this->spec.samples = MAX(this->spec.freq / 20, 256);
		this->spec.samples = (this->spec.samples + 7) & ~7;
	}

	/* Update the fragment size as size in bytes */
	SDL_CalculateAudioSpec(&this->spec);

	hidden = (APTR)SDL_malloc(sizeof(*hidden) + this->spec.size * 2);

	if (hidden == NULL)
		return SDL_OutOfMemory();

	hidden->req[0].ahir_Std.io_Message.mn_ReplyPort = &hidden->ahiport;
	hidden->req[0].ahir_Std.io_Message.mn_Length = sizeof(struct AHIRequest);
	hidden->req[0].ahir_Std.io_Command = CMD_WRITE;
	hidden->req[0].ahir_Std.io_Data = NULL;
	hidden->req[0].ahir_Version = 6;

	hidden->buffers[0] = &hidden->mixbuf[0];
	hidden->buffers[1] = &hidden->mixbuf[this->spec.size];
	hidden->convert = convert;
	hidden->current_buffer = 0;
	hidden->sample_format = sample_format;
	hidden->playing = 0;

	this->hidden = hidden;
	
	if (OpenDevice(AHINAME, 0, (struct IORequest *)&hidden->req[0].ahir_Std, 0) != 0)
	{
		SDL_SetError("Unable to open ahi.device unit 0! Error code %d.\n", hidden->req[0].ahir_Std.io_Error);
		SDL_free(hidden);
		return -1;
	}
	return 0;
}

static int
AHIAUD_CaptureFromDevice(_THIS, void *buffer, int buflen)
{
	// TODO
	
	return 0;
}

static int
AHIAUD_Init(SDL_AudioDriverImpl * impl)
{
	/* Set the function pointers */
	impl->OpenDevice = AHIAUD_OpenDevice;
	impl->ThreadInit = AHIAUD_ThreadInit;
	impl->PlayDevice = AHIAUD_PlayDevice;
	impl->WaitDevice = AHIAUD_WaitDevice;
	//impl->WaitDone = AHIAUD_WaitDone;
	impl->CaptureFromDevice = AHIAUD_CaptureFromDevice;	
	impl->GetDeviceBuf = AHIAUD_GetDeviceBuf;
	impl->CloseDevice = AHIAUD_CloseDevice;

	impl->HasCaptureSupport = 0;
	impl->OnlyHasDefaultOutputDevice = 1;
	impl->OnlyHasDefaultCaptureDevice = 0;
	
	return 1;   /* this audio target is available. */
}

AudioBootStrap AHIAUD_bootstrap = {
    "ahi", "Amiga AHI audio driver", AHIAUD_Init, 0
};
