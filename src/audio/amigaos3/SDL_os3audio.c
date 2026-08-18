/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

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

#if SDL_AUDIO_DRIVER_AHI

#include "SDL_audio.h"
#include "SDL_timer.h"
#include "../SDL_audio_c.h"
#include "../SDL_sysaudio.h"
#include "SDL_os3audio.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>
#include <exec/memory.h>
#ifdef WARPUP
#pragma pack(pop)
#endif

#define OS3AHI_DRIVER_NAME "ahi"
#define OS3AHI_RESTART_CAPTURE_THRESHOLD 500

static void OS3AHI_DetectDevices(void)
{
}

static void OS3AHI_FinishRequest(struct SDL_PrivateAudioData *hidden, int index, SDL_bool abort_request)
{
    struct IORequest *request;

    if (!hidden->pending[index] || !hidden->req[index]) {
        return;
    }

    request = (struct IORequest *)hidden->req[index];
    if (abort_request && !CheckIO(request)) {
        AbortIO(request);
    }
    WaitIO(request);
    hidden->pending[index] = SDL_FALSE;
}

static void OS3AHI_CloseAhiDevice(struct SDL_PrivateAudioData *hidden)
{
    if (hidden->req[1]) {
        OS3AHI_FinishRequest(hidden, 1, SDL_TRUE);
    }
    if (hidden->req[0]) {
        OS3AHI_FinishRequest(hidden, 0, SDL_TRUE);
    }

    hidden->link = NULL;
    if (hidden->device_open) {
        CloseDevice((struct IORequest *)hidden->req[0]);
        hidden->device_open = SDL_FALSE;
    }
    if (hidden->req[1]) {
        FreeVec(hidden->req[1]);
        hidden->req[1] = NULL;
    }
    if (hidden->req[0]) {
        DeleteIORequest((struct IORequest *)hidden->req[0]);
        hidden->req[0] = NULL;
    }
    if (hidden->port) {
        DeleteMsgPort(hidden->port);
        hidden->port = NULL;
    }
}

static int OS3AHI_OpenAhiDevice(struct SDL_PrivateAudioData *hidden)
{
    hidden->port = CreateMsgPort();
    if (!hidden->port) {
        return SDL_SetError("AHI: CreateMsgPort failed");
    }

    hidden->req[0] = (struct AHIRequest *)CreateIORequest(hidden->port, sizeof(struct AHIRequest));
    if (!hidden->req[0]) {
        OS3AHI_CloseAhiDevice(hidden);
        return SDL_SetError("AHI: CreateIORequest failed");
    }

    hidden->req[0]->ahir_Version = 4;
    if (OpenDevice((CONST_STRPTR)AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)hidden->req[0], 0) != 0) {
        OS3AHI_CloseAhiDevice(hidden);
        return SDL_SetError("AHI: OpenDevice failed");
    }
    hidden->device_open = SDL_TRUE;

    hidden->req[1] = (struct AHIRequest *)AllocVec(sizeof(struct AHIRequest), MEMF_PUBLIC);
    if (!hidden->req[1]) {
        OS3AHI_CloseAhiDevice(hidden);
        return SDL_SetError("AHI: second request allocation failed");
    }
    SDL_memcpy(hidden->req[1], hidden->req[0], sizeof(struct AHIRequest));

    hidden->current = 0;
    hidden->link = NULL;
    hidden->pending[0] = SDL_FALSE;
    hidden->pending[1] = SDL_FALSE;
    hidden->last_capture_ticks = 0;
    return 0;
}

static int OS3AHI_OpenDevice(_THIS, const char *devname)
{
    struct SDL_PrivateAudioData *hidden;
    SDL_AudioFormat test_format;
    ULONG ahi_type = AHIST_S16S;
    int found = 0;

    (void)devname;

    hidden = (struct SDL_PrivateAudioData *)SDL_calloc(1, sizeof(*hidden));
    if (!hidden) {
        return SDL_OutOfMemory();
    }
    _this->hidden = hidden;

    if (_this->spec.channels > 2) {
        _this->spec.channels = 2;
    } else if (_this->spec.channels < 1) {
        _this->spec.channels = 1;
    }

    for (test_format = SDL_FirstAudioFormat(_this->spec.format);
         test_format && !found;
         test_format = SDL_NextAudioFormat()) {
        switch (test_format) {
        case AUDIO_S16MSB:
        case AUDIO_S16LSB:
            test_format = AUDIO_S16MSB;
            ahi_type = (_this->spec.channels == 2) ? AHIST_S16S : AHIST_M16S;
            found = 1;
            break;
        case AUDIO_S8:
        case AUDIO_U8:
            test_format = AUDIO_S8;
            ahi_type = (_this->spec.channels == 2) ? AHIST_S8S : AHIST_M8S;
            found = 1;
            break;
        default:
            break;
        }
    }
    if (!found) {
        test_format = AUDIO_S16MSB;
        ahi_type = (_this->spec.channels == 2) ? AHIST_S16S : AHIST_M16S;
    }

    _this->spec.format = test_format;
    SDL_CalculateAudioSpec(&_this->spec);

    hidden->ahi_type = ahi_type;
    hidden->ahi_freq = (ULONG)_this->spec.freq;
    hidden->bufsize = (ULONG)_this->spec.size;
    hidden->mixbuf[0] = (Uint8 *)AllocVec(hidden->bufsize, MEMF_PUBLIC);
    hidden->mixbuf[1] = (Uint8 *)AllocVec(hidden->bufsize, MEMF_PUBLIC);
    if (!hidden->mixbuf[0] || !hidden->mixbuf[1]) {
        if (hidden->mixbuf[0]) {
            FreeVec(hidden->mixbuf[0]);
        }
        if (hidden->mixbuf[1]) {
            FreeVec(hidden->mixbuf[1]);
        }
        SDL_free(hidden);
        _this->hidden = NULL;
        return SDL_OutOfMemory();
    }

    SDL_memset(hidden->mixbuf[0], _this->spec.silence, hidden->bufsize);
    SDL_memset(hidden->mixbuf[1], _this->spec.silence, hidden->bufsize);
    return 0;
}

static void OS3AHI_ThreadInit(_THIS)
{
    /* CreateMsgPort allocates a signal for the calling task, so AHI must be
       opened by the SDL audio thread that will wait on that signal. */
    OS3AHI_OpenAhiDevice(_this->hidden);
}

static void OS3AHI_ThreadDeinit(_THIS)
{
    OS3AHI_CloseAhiDevice(_this->hidden);
}

static void OS3AHI_WaitDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (hidden->device_open) {
        OS3AHI_FinishRequest(hidden, hidden->current, SDL_FALSE);
    }
}

static Uint8 *OS3AHI_GetDeviceBuf(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    return hidden->device_open ? hidden->mixbuf[hidden->current] : NULL;
}

static void OS3AHI_PlayDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    struct AHIRequest *request;
    int current;

    if (!hidden->device_open) {
        return;
    }

    current = hidden->current;
    OS3AHI_FinishRequest(hidden, current, SDL_FALSE);
    request = hidden->req[current];
    request->ahir_Std.io_Message.mn_Node.ln_Pri = 60;
    request->ahir_Std.io_Data = hidden->mixbuf[current];
    request->ahir_Std.io_Length = hidden->bufsize;
    request->ahir_Std.io_Offset = 0;
    request->ahir_Std.io_Command = CMD_WRITE;
    request->ahir_Frequency = hidden->ahi_freq;
    request->ahir_Volume = 0x10000L;
    request->ahir_Type = hidden->ahi_type;
    request->ahir_Position = 0x8000L;
    request->ahir_Link = hidden->link;

    SendIO((struct IORequest *)request);
    hidden->pending[current] = SDL_TRUE;
    hidden->link = request;
    hidden->current ^= 1;
}

static void OS3AHI_FillCaptureRequest(struct SDL_PrivateAudioData *hidden,
                                      Uint8 *buffer)
{
    struct AHIRequest *request = hidden->req[0];

    request->ahir_Std.io_Message.mn_Node.ln_Pri = 60;
    request->ahir_Std.io_Data = buffer;
    request->ahir_Std.io_Length = hidden->bufsize;
    request->ahir_Std.io_Offset = 0;
    request->ahir_Std.io_Command = CMD_READ;
    request->ahir_Frequency = hidden->ahi_freq;
    request->ahir_Volume = 0x10000L;
    request->ahir_Type = hidden->ahi_type;
    request->ahir_Position = 0x8000L;
    request->ahir_Link = NULL;
}

static void OS3AHI_FlushCapture(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    OS3AHI_FinishRequest(hidden, 0, SDL_TRUE);
    hidden->last_capture_ticks = 0;
}

static int OS3AHI_CaptureFromDevice(_THIS, void *buffer, int buflen)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    struct AHIRequest *request;
    Uint32 now;
    int completed;
    int copylen;

    if (!hidden->device_open) {
        return -1;
    }

    request = hidden->req[0];
    now = SDL_GetTicks();
    OS3AHI_FinishRequest(hidden, 0, SDL_FALSE);

    if (hidden->last_capture_ticks == 0 ||
        now - hidden->last_capture_ticks > OS3AHI_RESTART_CAPTURE_THRESHOLD) {
        OS3AHI_FillCaptureRequest(hidden, hidden->mixbuf[hidden->current]);
        DoIO((struct IORequest *)request);
        completed = hidden->current;

        OS3AHI_FillCaptureRequest(hidden, hidden->mixbuf[hidden->current ^ 1]);
        SendIO((struct IORequest *)request);
        hidden->pending[0] = SDL_TRUE;
    } else {
        OS3AHI_FillCaptureRequest(hidden, hidden->mixbuf[hidden->current]);
        SendIO((struct IORequest *)request);
        hidden->pending[0] = SDL_TRUE;
        completed = hidden->current ^ 1;
        hidden->current ^= 1;
    }

    copylen = (buflen < (int)hidden->bufsize) ? buflen : (int)hidden->bufsize;
    SDL_memcpy(buffer, hidden->mixbuf[completed], (size_t)copylen);
    hidden->last_capture_ticks = now;
    return copylen;
}

static void OS3AHI_CloseDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (!hidden) {
        return;
    }

    /* ThreadDeinit normally owns this cleanup. Keep this fallback for an
       audio-thread creation failure, before ThreadInit has run. */
    OS3AHI_CloseAhiDevice(hidden);
    if (hidden->mixbuf[0]) {
        FreeVec(hidden->mixbuf[0]);
    }
    if (hidden->mixbuf[1]) {
        FreeVec(hidden->mixbuf[1]);
    }
    SDL_free(hidden);
    _this->hidden = NULL;
}

static int OS3AHI_Available(void)
{
    struct MsgPort *port;
    struct AHIRequest *request;
    struct Process *process;
    APTR old_window;
    int available = 0;

    port = CreateMsgPort();
    if (!port) {
        return 0;
    }
    request = (struct AHIRequest *)CreateIORequest(port, sizeof(struct AHIRequest));
    if (!request) {
        DeleteMsgPort(port);
        return 0;
    }

    request->ahir_Version = 4;
    process = (struct Process *)FindTask(NULL);
    old_window = process->pr_WindowPtr;
    process->pr_WindowPtr = (APTR)-1L;
    if (OpenDevice((CONST_STRPTR)AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)request, 0) == 0) {
        available = 1;
        CloseDevice((struct IORequest *)request);
    }
    process->pr_WindowPtr = old_window;

    DeleteIORequest((struct IORequest *)request);
    DeleteMsgPort(port);
    return available;
}

static SDL_bool OS3AHI_Init(SDL_AudioDriverImpl *impl)
{
    if (!OS3AHI_Available()) {
        return SDL_FALSE;
    }

    impl->DetectDevices = OS3AHI_DetectDevices;
    impl->OpenDevice = OS3AHI_OpenDevice;
    impl->ThreadInit = OS3AHI_ThreadInit;
    impl->ThreadDeinit = OS3AHI_ThreadDeinit;
    impl->PlayDevice = OS3AHI_PlayDevice;
    impl->GetDeviceBuf = OS3AHI_GetDeviceBuf;
    impl->WaitDevice = OS3AHI_WaitDevice;
    impl->CaptureFromDevice = OS3AHI_CaptureFromDevice;
    impl->FlushCapture = OS3AHI_FlushCapture;
    impl->CloseDevice = OS3AHI_CloseDevice;

    impl->OnlyHasDefaultOutputDevice = SDL_TRUE;
    impl->OnlyHasDefaultCaptureDevice = SDL_TRUE;
    impl->HasCaptureSupport = SDL_TRUE;
    impl->ProvidesOwnCallbackThread = SDL_FALSE;
    return SDL_TRUE;
}

AudioBootStrap OS3AHI_bootstrap = {
    OS3AHI_DRIVER_NAME, "AmigaOS AHI Audio", OS3AHI_Init, SDL_FALSE
};

#endif /* SDL_AUDIO_DRIVER_AHI */
