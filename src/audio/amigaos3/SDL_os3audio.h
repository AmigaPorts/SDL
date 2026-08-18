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

#ifndef SDL_os3audio_h_
#define SDL_os3audio_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <devices/ahi.h>
#ifdef WARPUP
#pragma pack(pop)
#endif

struct SDL_PrivateAudioData
{
    struct MsgPort *port;
    struct AHIRequest *req[2];
    struct AHIRequest *link;
    SDL_bool pending[2];
    SDL_bool device_open;
    int current;
    Uint8 *mixbuf[2];
    ULONG bufsize;
    ULONG ahi_type;
    ULONG ahi_freq;
    Uint32 last_capture_ticks;
};

#define _THIS SDL_AudioDevice *_this

extern AudioBootStrap OS3AHI_bootstrap;

#endif /* SDL_os3audio_h_ */
