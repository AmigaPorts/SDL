/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)
  Header with per-device private data and AHI definitions.
*/

#ifndef SDL_os3audio_h_
#define SDL_os3audio_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#include <devices/ahi.h>

/* Per-device private data stored in _this->hidden */
struct SDL_PrivateAudioData {
    struct MsgPort    *port;
    struct AHIRequest *req[2];       /* double-buffer requests */
    int                current;      /* which buffer is being filled (0 or 1) */
    SDL_bool           playing;      /* TRUE after first SendIO */
    Uint8             *mixbuf[2];    /* audio buffers (MEMF_PUBLIC) */
    ULONG              bufsize;      /* buffer size in bytes */
    ULONG              ahi_type;     /* AHI sample type (AHIST_*) */
    ULONG              ahi_freq;     /* playback frequency in Hz */
};

/* Re-define _THIS for our backend (undef'd in SDL_sysaudio.h) */
#define _THIS SDL_AudioDevice *_this

extern AudioBootStrap OS3AHI_bootstrap;

#endif /* SDL_os3audio_h_ */
