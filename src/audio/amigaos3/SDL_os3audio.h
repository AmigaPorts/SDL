/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)
  Device interface matching SDL 1.2 AmigaPorts pattern.
*/

#ifndef SDL_os3audio_h_
#define SDL_os3audio_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#include <devices/ahi.h>

struct SDL_PrivateAudioData {
    struct MsgPort    *port;
    struct AHIRequest *req[2];
    int                current;
    int                playing;     /* incremented each SendIO */
    Uint8             *mixbuf[2];
    ULONG              bufsize;
    ULONG              ahi_type;
    ULONG              ahi_freq;
};

#define _THIS SDL_AudioDevice *_this

extern AudioBootStrap OS3AHI_bootstrap;

#endif /* SDL_os3audio_h_ */
