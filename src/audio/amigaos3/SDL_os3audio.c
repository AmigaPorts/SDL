/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)

  Device interface matching SDL 1.2 AmigaPorts pattern exactly:
  - OpenDevice(AHINAME, 0, req, NULL) -- unit 0, no flags
  - CMD_WRITE + SendIO double-buffered
  - CheckIO before WaitIO (non-blocking check)
  - ahir_Link chaining for gapless playback
  - playing counter: WaitIO only after 2nd buffer submitted

  Reference: AmigaPorts/libSDL12/audio/amigaos/SDL_ahiaudio.c
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
#pragma pop
#endif

#define OS3AHI_DRIVER_NAME "ahi"

static void OS3AHI_DetectDevices(void)
{
}

static int OS3AHI_OpenDevice(_THIS, const char *devname)
{
    struct SDL_PrivateAudioData *hidden = NULL;
    SDL_AudioFormat test_format;
    ULONG ahi_type = AHIST_S16S;
    int found = 0;

    (void)devname;

    hidden = (struct SDL_PrivateAudioData *)
        SDL_malloc(sizeof(struct SDL_PrivateAudioData));
    if (!hidden) return SDL_OutOfMemory();
    SDL_memset(hidden, 0, sizeof(struct SDL_PrivateAudioData));
    _this->hidden = hidden;

    if (_this->spec.channels > 2) _this->spec.channels = 2;
    if (_this->spec.channels < 1) _this->spec.channels = 1;

    for (test_format = SDL_FirstAudioFormat(_this->spec.format);
         test_format && !found;
         test_format = SDL_NextAudioFormat()) {
        switch (test_format) {
        case AUDIO_S16MSB:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
            found = 1; break;
        case AUDIO_S16LSB:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
            test_format = AUDIO_S16MSB;
            found = 1; break;
        case AUDIO_S8:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S8S : AHIST_M8S;
            found = 1; break;
        default: break;
        }
    }
    if (!found) {
        test_format = AUDIO_S16MSB;
        ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
    }
    _this->spec.format = test_format;
    SDL_CalculateAudioSpec(&_this->spec);

    hidden->ahi_type = ahi_type;
    hidden->ahi_freq = (ULONG)_this->spec.freq;
    hidden->bufsize  = (ULONG)_this->spec.size;
    hidden->current  = 0;
    hidden->playing  = 0;

    /* Create MsgPort -- matching SDL 1.2 exactly */
    hidden->port = CreateMsgPort();
    if (!hidden->port)
        return SDL_SetError("AHI: CreateMsgPort failed");

    /* Create primary AHIRequest */
    hidden->req[0] = (struct AHIRequest *)
        CreateIORequest(hidden->port, sizeof(struct AHIRequest));
    if (!hidden->req[0])
        return SDL_SetError("AHI: CreateIORequest failed");

    hidden->req[0]->ahir_Version = 4;

    /* OpenDevice -- unit 0, flags NULL, matching SDL 1.2.
       NO pr_WindowPtr suppression (SDL 1.2 doesn't do it). */
    if (OpenDevice((CONST_STRPTR)AHINAME, 0,
                   (struct IORequest *)hidden->req[0], NULL) != 0) {
        DeleteIORequest((struct IORequest *)hidden->req[0]);
        hidden->req[0] = NULL;
        return SDL_SetError("AHI: OpenDevice failed");
    }

    /* Allocate buffers */
    hidden->mixbuf[0] = (Uint8 *)AllocVec(hidden->bufsize, MEMF_PUBLIC);
    hidden->mixbuf[1] = (Uint8 *)AllocVec(hidden->bufsize, MEMF_PUBLIC);
    if (!hidden->mixbuf[0] || !hidden->mixbuf[1])
        return SDL_SetError("AHI: buffer alloc failed");

    /* Clone req[0] to req[1] -- matching SDL 1.2 (AllocVec + memcpy) */
    hidden->req[1] = (struct AHIRequest *)AllocVec(sizeof(struct AHIRequest),
                                                    MEMF_PUBLIC);
    if (!hidden->req[1])
        return SDL_SetError("AHI: req[1] alloc failed");

    SDL_memcpy(hidden->req[1], hidden->req[0], sizeof(struct AHIRequest));

    /* Clear buffers with silence */
    SDL_memset(hidden->mixbuf[0], _this->spec.silence, hidden->bufsize);
    SDL_memset(hidden->mixbuf[1], _this->spec.silence, hidden->bufsize);

    return 0;
}

/* WaitAudio: CheckIO before WaitIO -- matching SDL 1.2 exactly.
   Only block if the request hasn't completed yet. */
static void OS3AHI_WaitDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (!CheckIO((struct IORequest *)hidden->req[hidden->current])) {
        WaitIO((struct IORequest *)hidden->req[hidden->current]);
    }
}

static Uint8 *OS3AHI_GetDeviceBuf(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    return hidden->mixbuf[hidden->current];
}

/* PlayAudio: CMD_WRITE + SendIO -- matching SDL 1.2 exactly. */
static void OS3AHI_PlayDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    struct AHIRequest *req = hidden->req[hidden->current];

    /* Wait for THIS buffer's previous use to complete (if any).
       SDL 1.2: "if (playing > 1) WaitIO(req[current])" */
    if (hidden->playing > 1) {
        WaitIO((struct IORequest *)req);
    }

    req->ahir_Std.io_Message.mn_Node.ln_Pri = 60;
    req->ahir_Std.io_Data    = hidden->mixbuf[hidden->current];
    req->ahir_Std.io_Length  = hidden->bufsize;
    req->ahir_Std.io_Offset  = 0;
    req->ahir_Std.io_Command = CMD_WRITE;
    req->ahir_Frequency = hidden->ahi_freq;
    req->ahir_Volume    = 0x10000L;
    req->ahir_Type      = hidden->ahi_type;
    req->ahir_Position  = 0x8000L;
    req->ahir_Link      = (hidden->playing > 0)
                          ? hidden->req[hidden->current ^ 1]
                          : NULL;

    SendIO((struct IORequest *)req);
    hidden->current ^= 1;
    hidden->playing++;
}

static void OS3AHI_CloseDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (!hidden) return;

    if (hidden->req[0]) {
        if (hidden->req[1] && hidden->playing > 1) {
            AbortIO((struct IORequest *)hidden->req[1]);
            WaitIO((struct IORequest *)hidden->req[1]);
        }

        AbortIO((struct IORequest *)hidden->req[0]);
        WaitIO((struct IORequest *)hidden->req[0]);

        if (hidden->req[1] && hidden->playing > 1) {
            AbortIO((struct IORequest *)hidden->req[1]);
            WaitIO((struct IORequest *)hidden->req[1]);
        }

        CloseDevice((struct IORequest *)hidden->req[0]);

        if (hidden->req[1]) {
            FreeVec(hidden->req[1]);
            hidden->req[1] = NULL;
        }
        DeleteIORequest((struct IORequest *)hidden->req[0]);
        hidden->req[0] = NULL;
    }

    hidden->playing = 0;

    if (hidden->mixbuf[0]) { FreeVec(hidden->mixbuf[0]); hidden->mixbuf[0] = NULL; }
    if (hidden->mixbuf[1]) { FreeVec(hidden->mixbuf[1]); hidden->mixbuf[1] = NULL; }

    if (hidden->port) {
        DeleteMsgPort(hidden->port);
        hidden->port = NULL;
    }

    SDL_free(hidden);
    _this->hidden = NULL;
}

/* Probe whether ahi.device can be opened.
   If not, return SDL_FALSE so SDL2 falls through to Paula. */
static int OS3AHI_Available(void)
{
    struct MsgPort *p;
    struct AHIRequest *req;
    int ok = 0;
    struct Process *me;
    APTR oldwin;

    p = CreateMsgPort();
    if (!p) return 0;

    req = (struct AHIRequest *)CreateIORequest(p, sizeof(struct AHIRequest));
    if (!req) {
        DeleteMsgPort(p);
        return 0;
    }

    req->ahir_Version = 4;

    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    if (OpenDevice((CONST_STRPTR)AHINAME, 0,
                   (struct IORequest *)req, NULL) == 0) {
        ok = 1;
        CloseDevice((struct IORequest *)req);
    }

    me->pr_WindowPtr = oldwin;

    DeleteIORequest((struct IORequest *)req);
    DeleteMsgPort(p);
    return ok;
}

static SDL_bool OS3AHI_Init(SDL_AudioDriverImpl *impl)
{
    if (!OS3AHI_Available())
        return SDL_FALSE;

    impl->DetectDevices = OS3AHI_DetectDevices;
    impl->OpenDevice    = OS3AHI_OpenDevice;
    impl->PlayDevice    = OS3AHI_PlayDevice;
    impl->GetDeviceBuf  = OS3AHI_GetDeviceBuf;
    impl->WaitDevice    = OS3AHI_WaitDevice;
    impl->CloseDevice   = OS3AHI_CloseDevice;

    impl->OnlyHasDefaultOutputDevice = SDL_TRUE;
    impl->HasCaptureSupport = SDL_FALSE;
    impl->ProvidesOwnCallbackThread = SDL_FALSE;

    return SDL_TRUE;
}

AudioBootStrap OS3AHI_bootstrap = {
    OS3AHI_DRIVER_NAME, "AmigaOS AHI Audio",
    OS3AHI_Init, SDL_FALSE
};

#endif /* SDL_AUDIO_DRIVER_AHI */
