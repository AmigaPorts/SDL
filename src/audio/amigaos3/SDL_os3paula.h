/*
  SDL2 Audio Driver -- AmigaOS 3.x (Paula / audio.device)

  Native Paula DMA playback via audio.device.
  8-bit signed mono only. All buffers in CHIP RAM.
*/

#ifndef SDL_os3paula_h_
#define SDL_os3paula_h_

#include "../../SDL_internal.h"
#include "../SDL_sysaudio.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <devices/audio.h>
#include <exec/memory.h>
#ifdef WARPUP
#pragma pop
#endif

/* Private data for the Paula audio backend.
   Allocated per-device in OpenDevice, freed in CloseDevice.
   NOTE: struct SDL_PrivateAudioData is already typedef'd by
   SDL_sysaudio.h, so the AHI and Paula backends cannot both
   define it in the same translation unit. Each .c file includes
   only its own header. */
struct OS3PaulaData {
    struct MsgPort  *port;
    struct IOAudio  *req[2];       /* double-buffered IO requests */
    UBYTE           *chipbuf[2];   /* sample buffers in CHIP RAM */
    ULONG            bufsize;      /* bytes per buffer */
    UWORD            period;       /* Paula period register value */
    int              current;      /* which buffer (0 or 1) */
    int              playing;      /* count of submitted requests */
    int              dev_open;     /* 1 after LazyOpen succeeds */
    ULONG            clock;        /* PAL=3546895, NTSC=3579545 */
};

extern AudioBootStrap OS3PAULA_bootstrap;

#endif /* SDL_os3paula_h_ */
