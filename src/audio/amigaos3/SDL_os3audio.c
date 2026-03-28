/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)

  Uses AHI device interface (CMD_WRITE) with double-buffered
  AHIRequest structures for gapless playback.

  Reference: docs/references/ahi-reference.md
  Pattern:   Device Interface Double-Buffering (Pattern 1)
*/

#include "../../SDL_internal.h"

#if SDL_AUDIO_DRIVER_AHI

#include "SDL_audio.h"
#include "SDL_timer.h"
#include "../SDL_audio_c.h"
#include "../SDL_sysaudio.h"
#include "SDL_os3audio.h"

#include <proto/exec.h>
#include <exec/memory.h>

#define OS3AHI_DRIVER_NAME "ahi"

/* ------------------------------------------------------------------
 * OS3AHI_DetectDevices
 *
 * AHI has a single default unit (AHI_DEFAULT_UNIT = 0) which the
 * user configures via AHI Preferences. We report it as the default
 * output device. OnlyHasDefaultOutputDevice is set to SDL_TRUE so
 * SDL2 core handles the single-device case.
 * ------------------------------------------------------------------ */
static void OS3AHI_DetectDevices(void)
{
    /* Nothing to enumerate -- OnlyHasDefaultOutputDevice handles it */
}

/* ------------------------------------------------------------------
 * OS3AHI_OpenDevice
 *
 * Opens ahi.device on AHI_DEFAULT_UNIT. Allocates two audio buffers
 * and two AHIRequest structures sharing a single MsgPort. Negotiates
 * the audio format: we prefer S16 big-endian (native 68k), falling
 * back to S8 if requested. Channels are limited to mono or stereo.
 * ------------------------------------------------------------------ */
static int OS3AHI_OpenDevice(_THIS, const char *devname)
{
    struct SDL_PrivateAudioData *hidden = NULL;
    SDL_AudioFormat test_format;
    ULONG ahi_type = AHIST_S16S;
    int found = 0;

    /* Allocate private data */
    hidden = (struct SDL_PrivateAudioData *)
        SDL_malloc(sizeof(struct SDL_PrivateAudioData));
    if (!hidden) {
        return SDL_OutOfMemory();
    }
    SDL_memset(hidden, 0, sizeof(struct SDL_PrivateAudioData));
    _this->hidden = hidden;

    /* Clamp channels to 1 or 2 (AHI supports mono and stereo) */
    if (_this->spec.channels > 2) {
        _this->spec.channels = 2;
    }
    if (_this->spec.channels < 1) {
        _this->spec.channels = 1;
    }

    /* Negotiate audio format: find one AHI can handle.
     * AHI supports signed 8-bit and signed 16-bit (big-endian on 68k).
     * On 68k, AUDIO_S16SYS == AUDIO_S16MSB. */
    for (test_format = SDL_FirstAudioFormat(_this->spec.format);
         test_format && !found;
         test_format = SDL_NextAudioFormat()) {
        switch (test_format) {
        case AUDIO_S16MSB:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
            found = 1;
            break;
        case AUDIO_S16LSB:
            /* AHI native is big-endian; let SDL2 convert from little-endian.
             * Tell SDL2 we want S16MSB. */
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
            test_format = AUDIO_S16MSB;
            found = 1;
            break;
        case AUDIO_S8:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S8S : AHIST_M8S;
            found = 1;
            break;
        default:
            break;
        }
    }

    if (!found) {
        /* Fall back to S16 big-endian stereo -- SDL2 will convert */
        test_format = AUDIO_S16MSB;
        ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
    }

    _this->spec.format = test_format;

    /* Let SDL2 calculate silence value and buffer size */
    SDL_CalculateAudioSpec(&_this->spec);

    hidden->ahi_type = ahi_type;
    hidden->ahi_freq = (ULONG)_this->spec.freq;
    hidden->bufsize  = (ULONG)_this->spec.size;
    hidden->current  = 0;
    hidden->playing  = SDL_FALSE;

    /* Create the message port for I/O completion signals */
    hidden->port = CreateMsgPort();
    if (!hidden->port) {
        return SDL_SetError("AHI: Failed to create MsgPort");
    }

    /* Create primary AHIRequest via CreateIORequest */
    hidden->req[0] = (struct AHIRequest *)
        CreateIORequest(hidden->port, sizeof(struct AHIRequest));
    if (!hidden->req[0]) {
        return SDL_SetError("AHI: Failed to create IORequest");
    }

    /* Set minimum AHI version before OpenDevice */
    hidden->req[0]->ahir_Version = 4;

    if (OpenDevice((CONST_STRPTR)AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)hidden->req[0], 0L) != 0) {
        /* OpenDevice failed -- delete the request and let CloseDevice handle
         * the rest. Mark req[0] as NULL so CloseDevice knows not to call
         * CloseDevice on it. */
        DeleteIORequest((struct IORequest *)hidden->req[0]);
        hidden->req[0] = NULL;
        return SDL_SetError("AHI: Failed to open ahi.device");
    }

    /* Create second AHIRequest by copying the first.
     * Both share the same MsgPort and device. req[1] is NOT created
     * via CreateIORequest -- it is a raw AllocMem copy. We must free
     * it with FreeMem, not DeleteIORequest. Only req[0] owns the
     * device (CloseDevice is called on req[0] only). */
    hidden->req[1] = (struct AHIRequest *)
        AllocMem(sizeof(struct AHIRequest), MEMF_PUBLIC | MEMF_CLEAR);
    if (!hidden->req[1]) {
        return SDL_SetError("AHI: Failed to allocate second request");
    }
    CopyMem(hidden->req[0], hidden->req[1], sizeof(struct AHIRequest));

    /* Allocate two audio buffers in public memory (AHI DMA requirement) */
    hidden->mixbuf[0] = (Uint8 *)AllocMem(hidden->bufsize,
                                           MEMF_PUBLIC | MEMF_CLEAR);
    hidden->mixbuf[1] = (Uint8 *)AllocMem(hidden->bufsize,
                                           MEMF_PUBLIC | MEMF_CLEAR);
    if (!hidden->mixbuf[0] || !hidden->mixbuf[1]) {
        return SDL_SetError("AHI: Failed to allocate audio buffers "
                            "(%lu bytes each)", (unsigned long)hidden->bufsize);
    }

    return 0; /* success */
}

/* ------------------------------------------------------------------
 * OS3AHI_WaitDevice
 *
 * Called AFTER PlayDevice. Wait for the request that was submitted
 * two iterations ago (the "other" buffer) to complete. On the first
 * call after playback starts, there is only one request in flight
 * and we wait for it. On steady state, we wait for the older of the
 * two alternating requests.
 *
 * SDL2 audio thread flow:
 *   GetDeviceBuf -> [fill buffer] -> PlayDevice -> WaitDevice
 *
 * After PlayDevice swaps current, the "current" index points to the
 * buffer that was just submitted. The OTHER buffer is the one from
 * the previous iteration that should be finishing now.
 * ------------------------------------------------------------------ */
static void OS3AHI_WaitDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (!hidden->playing) {
        return;
    }

    /* Wait for the request on the CURRENT slot (which was submitted
     * by PlayDevice and then current was swapped, so current now
     * points to the buffer we need to wait on from the previous
     * iteration). Actually -- PlayDevice does current ^= 1 AFTER
     * SendIO, so current points to the NEXT buffer to fill.
     * The request we need to wait on is req[current] because that
     * is the one that was submitted TWO iterations ago.
     *
     * On the first call, only one request is in flight (the one
     * submitted by PlayDevice). current was already swapped, so
     * req[current] was not yet submitted -- we need to wait on
     * req[current ^ 1] which is the one just sent.
     *
     * Simplification: WaitIO is safe to call on a request that
     * has already completed (it just returns immediately). We
     * always wait on req[current] which is the buffer slot we
     * are about to fill next. If it was in flight from a prior
     * iteration, we block until it finishes. If it was never
     * submitted or already finished, WaitIO returns immediately. */
    WaitIO((struct IORequest *)hidden->req[hidden->current]);
}

/* ------------------------------------------------------------------
 * OS3AHI_GetDeviceBuf
 *
 * Return a pointer to the buffer that SDL2 should fill with audio
 * data. This is the "current" buffer (the one NOT currently playing).
 * ------------------------------------------------------------------ */
static Uint8 *OS3AHI_GetDeviceBuf(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    return hidden->mixbuf[hidden->current];
}

/* ------------------------------------------------------------------
 * OS3AHI_PlayDevice
 *
 * Submit the just-filled buffer to AHI via CMD_WRITE + SendIO.
 * Uses ahir_Link to chain to the previous request for gapless
 * playback (double-buffering).
 * ------------------------------------------------------------------ */
static void OS3AHI_PlayDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    struct AHIRequest *req = hidden->req[hidden->current];
    int other = hidden->current ^ 1;

    /* Configure the I/O request for CMD_WRITE */
    req->ahir_Std.io_Command = CMD_WRITE;
    req->ahir_Std.io_Data    = hidden->mixbuf[hidden->current];
    req->ahir_Std.io_Length  = hidden->bufsize;
    req->ahir_Std.io_Offset  = 0;

    req->ahir_Type      = hidden->ahi_type;
    req->ahir_Frequency = hidden->ahi_freq;
    req->ahir_Volume    = 0x10000L;   /* full volume (Fixed 16.16) */
    req->ahir_Position  = 0x8000L;    /* center pan  (Fixed 16.16) */

    /* Link to previous request for gapless playback.
     * On the first buffer, there is no previous request. */
    req->ahir_Link = hidden->playing ? hidden->req[other] : NULL;

    SendIO((struct IORequest *)req);

    hidden->playing = SDL_TRUE;
    hidden->current = other;  /* swap: next GetDeviceBuf returns the other buffer */
}

/* ------------------------------------------------------------------
 * OS3AHI_CloseDevice
 *
 * Abort pending I/O, close ahi.device, free all resources.
 * Close order: AbortIO+WaitIO pending, CloseDevice, free req[1],
 * DeleteIORequest(req[0]), free buffers, DeleteMsgPort.
 * ------------------------------------------------------------------ */
static void OS3AHI_CloseDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    int i;

    if (!hidden) {
        return;
    }

    /* Abort and wait for any in-flight requests */
    if (hidden->playing) {
        for (i = 0; i < 2; i++) {
            if (hidden->req[i]) {
                AbortIO((struct IORequest *)hidden->req[i]);
                WaitIO((struct IORequest *)hidden->req[i]);
            }
        }
    }

    /* Close the device (only on req[0] which owns it) */
    if (hidden->req[0] && hidden->req[0]->ahir_Std.io_Device) {
        CloseDevice((struct IORequest *)hidden->req[0]);
    }

    /* Free the cloned request (allocated with AllocMem) */
    if (hidden->req[1]) {
        FreeMem(hidden->req[1], sizeof(struct AHIRequest));
        hidden->req[1] = NULL;
    }

    /* Free the primary request (allocated with CreateIORequest) */
    if (hidden->req[0]) {
        DeleteIORequest((struct IORequest *)hidden->req[0]);
        hidden->req[0] = NULL;
    }

    /* Free audio buffers */
    for (i = 0; i < 2; i++) {
        if (hidden->mixbuf[i]) {
            FreeMem(hidden->mixbuf[i], hidden->bufsize);
            hidden->mixbuf[i] = NULL;
        }
    }

    /* Delete the message port */
    if (hidden->port) {
        DeleteMsgPort(hidden->port);
        hidden->port = NULL;
    }

    SDL_free(hidden);
    _this->hidden = NULL;
}

/* ------------------------------------------------------------------
 * OS3AHI_Init
 *
 * Probe for ahi.device availability. If it can be opened and closed
 * successfully, register all the callback function pointers.
 * ------------------------------------------------------------------ */
static SDL_bool OS3AHI_Init(SDL_AudioDriverImpl *impl)
{
    struct MsgPort *probe_port = NULL;
    struct AHIRequest *probe_req = NULL;

    /* Probe: can we open ahi.device? */
    probe_port = CreateMsgPort();
    if (!probe_port) {
        return SDL_FALSE;
    }

    probe_req = (struct AHIRequest *)
        CreateIORequest(probe_port, sizeof(struct AHIRequest));
    if (!probe_req) {
        DeleteMsgPort(probe_port);
        return SDL_FALSE;
    }

    probe_req->ahir_Version = 4;

    if (OpenDevice((CONST_STRPTR)AHINAME, AHI_DEFAULT_UNIT,
                   (struct IORequest *)probe_req, 0L) != 0) {
        DeleteIORequest((struct IORequest *)probe_req);
        DeleteMsgPort(probe_port);
        return SDL_FALSE;
    }

    /* AHI is available -- close the probe and register callbacks */
    CloseDevice((struct IORequest *)probe_req);
    DeleteIORequest((struct IORequest *)probe_req);
    DeleteMsgPort(probe_port);

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
    OS3AHI_Init, SDL_FALSE /* not demand_only */
};

#endif /* SDL_AUDIO_DRIVER_AHI */
