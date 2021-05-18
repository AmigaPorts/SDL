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

#ifndef _SDL_ahi_audio_h
#define _SDL_ahi_audio_h

#include "../SDL_sysaudio.h"

#include <devices/ahi.h>

/* Hidden "this" pointer for the audio functions */
#define _THIS   SDL_AudioDevice *this

typedef enum
{
	AMIAUD_CONVERT_NONE,
	AMIAUD_CONVERT_SWAP16,
	AMIAUD_CONVERT_SWAP32
} CONVTYPE;

struct SDL_PrivateAudioData
{
	struct MsgPort    ahiport;
	struct AHIRequest req[2];

	APTR  buffers[2];
	UBYTE convert;
	UBYTE current_buffer;
	UBYTE sample_format;
	UBYTE playing;

	UBYTE mixbuf[0];
};

#endif /* _SDL_ahi_audio_h */
