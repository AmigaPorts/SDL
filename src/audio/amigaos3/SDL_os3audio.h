/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)
  Header with per-device private data and AHI definitions.
*/

#ifndef SDL_os3audio_h_
#define SDL_os3audio_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#include <exec/types.h>
#include <exec/io.h>
#include <exec/ports.h>

/*
 * Minimal AHI definitions for the device interface.
 * The full devices/ahi.h is not available in bebbo-gcc.
 * These are from the AHI V4 developer documentation.
 */

#ifndef DEVICES_AHI_H
#define DEVICES_AHI_H

#define AHINAME "ahi.device"

#define AHI_DEFAULT_UNIT  0U
#define AHI_NO_UNIT       255U

/* Sample format constants */
#define AHIST_M8S    0UL   /* Mono,   8-bit signed  */
#define AHIST_M16S   1UL   /* Mono,  16-bit signed  */
#define AHIST_S8S    2UL   /* Stereo, 8-bit signed  */
#define AHIST_S16S   3UL   /* Stereo,16-bit signed  */

/* The AHI I/O request structure (extends IOStdReq) */
struct AHIRequest {
    struct IOStdReq  ahir_Std;
    UWORD            ahir_Version;
    UWORD            ahir_Pad1;
    ULONG            ahir_Private[2];
    ULONG            ahir_Type;
    ULONG            ahir_Frequency;
    LONG             ahir_Volume;     /* Fixed 16.16: 0x10000 = full */
    LONG             ahir_Position;   /* Fixed 16.16: 0x8000 = center */
    struct AHIRequest *ahir_Link;
};

#endif /* DEVICES_AHI_H */

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
