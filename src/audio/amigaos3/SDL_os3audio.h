/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)
  Header: per-device private data.
*/

#ifndef SDL_os3audio_h_
#define SDL_os3audio_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#include <devices/ahi.h>
#include <utility/hooks.h>

/* Per-device private data stored in _this->hidden */
struct SDL_PrivateAudioData {
    struct MsgPort       *port;
    struct AHIRequest    *req;        /* for OpenDevice/CloseDevice only */
    struct AHIAudioCtrl  *actrl;     /* library interface audio control */
    struct Hook           player_hook; /* PlayerFunc hook */
    struct Task          *audio_task; /* SDL2 audio thread's task */
    BYTE                  signal_bit; /* signal for PlayerFunc -> thread */
    ULONG                 signal_mask; /* 1UL << signal_bit */
    int                   current;   /* which buffer PlayerFunc just switched to */
    Uint8                *mixbuf[2]; /* double-buffered audio data */
    ULONG                 bufsize;   /* buffer size in bytes */
    ULONG                 ahi_type;  /* AHI sample type (AHIST_*) */
    ULONG                 ahi_freq;  /* playback frequency in Hz */
};

/* Re-define _THIS for our backend */
#define _THIS SDL_AudioDevice *_this

extern AudioBootStrap OS3AHI_bootstrap;

#endif /* SDL_os3audio_h_ */
