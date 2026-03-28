/*
  SDL2 Audio Driver -- AmigaOS 3.x (AHI)

  Uses AHI library interface (AHI_AllocAudio + PlayerFunc) for
  callback-driven audio. The PlayerFunc is called by AHI at interrupt
  level at a fixed rate; it swaps double-buffered sound slots and
  signals the SDL2 audio thread to refill the next buffer.

  This avoids the device interface (CMD_WRITE + WaitIO) which hangs
  on FS-UAE because audio drivers never signal I/O completion.

  Reference: docs/references/ahi-reference.md
*/

#include "../../SDL_internal.h"

#if SDL_AUDIO_DRIVER_AHI

#include <stdio.h>
#include "SDL_audio.h"
#include "SDL_timer.h"
#include "../SDL_audio_c.h"
#include "../SDL_sysaudio.h"
#include "SDL_os3audio.h"

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/ahi.h>
#include <exec/memory.h>
#include <utility/hooks.h>

/* AHI library base -- required by proto/ahi.h inlines */
struct Library *AHIBase = NULL;

#define OS3AHI_DRIVER_NAME "ahi"

/* ------------------------------------------------------------------
 * PlayerFunc -- called by AHI at interrupt level.
 *
 * Swaps the double-buffered sound slots: plays the buffer that was
 * just filled by the SDL2 audio thread, and signals the thread to
 * fill the next one.
 *
 * CRITICAL: This runs at INTERRUPT LEVEL. No allocation, no dos
 * calls, no Wait(). Only AHI_SetSound/SetVol/SetFreq and Signal().
 * ------------------------------------------------------------------ */
static ULONG OS3AHI_PlayerFunc(
    struct Hook *hook,
    struct AHIAudioCtrl *actrl,
    APTR msg)
{
    struct SDL_PrivateAudioData *hidden;

    (void)hook;
    (void)msg;
    hidden = (struct SDL_PrivateAudioData *)actrl->ahiac_UserData;

    /* Switch to the buffer that SDL2 just filled */
    AHI_SetSound(0, hidden->current, 0, 0, actrl, AHISF_IMM);

    /* Swap: the other buffer is now free for SDL2 to fill */
    hidden->current ^= 1;

    /* Signal the SDL2 audio thread to fill the next buffer.
       Signal() is safe from interrupt context (ADCD confirmed).
       signal_mask is set in ThreadInit by the audio thread. */
    if (hidden->audio_task && hidden->signal_mask) {
        Signal(hidden->audio_task, hidden->signal_mask);
    }

    return 0;
}

/* ------------------------------------------------------------------
 * OS3AHI_DetectDevices
 * ------------------------------------------------------------------ */
static void OS3AHI_DetectDevices(void)
{
    /* OnlyHasDefaultOutputDevice handles it */
}

/* ------------------------------------------------------------------
 * OS3AHI_OpenDevice
 * ------------------------------------------------------------------ */
static int OS3AHI_OpenDevice(_THIS, const char *devname)
{
    struct SDL_PrivateAudioData *hidden = NULL;
    SDL_AudioFormat test_format;
    ULONG ahi_type = AHIST_S16S;
    int found = 0;
    ULONG err;
    Fixed player_freq;
    ULONG buffer_frames;
    struct AHISampleInfo si;
    struct Process *me;
    APTR oldwin;

    (void)devname;

    /* Allocate private data */
    hidden = (struct SDL_PrivateAudioData *)
        SDL_malloc(sizeof(struct SDL_PrivateAudioData));
    if (!hidden) {
        return SDL_OutOfMemory();
    }
    SDL_memset(hidden, 0, sizeof(struct SDL_PrivateAudioData));
    _this->hidden = hidden;

    /* Clamp channels to 1 or 2 */
    if (_this->spec.channels > 2) {
        _this->spec.channels = 2;
    }
    if (_this->spec.channels < 1) {
        _this->spec.channels = 1;
    }

    /* Negotiate audio format */
    for (test_format = SDL_FirstAudioFormat(_this->spec.format);
         test_format && !found;
         test_format = SDL_NextAudioFormat()) {
        switch (test_format) {
        case AUDIO_S16MSB:
            ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
            found = 1;
            break;
        case AUDIO_S16LSB:
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
        test_format = AUDIO_S16MSB;
        ahi_type = (_this->spec.channels >= 2) ? AHIST_S16S : AHIST_M16S;
    }

    _this->spec.format = test_format;
    SDL_CalculateAudioSpec(&_this->spec);

    hidden->ahi_type = ahi_type;
    hidden->ahi_freq = (ULONG)_this->spec.freq;
    hidden->bufsize  = (ULONG)_this->spec.size;
    hidden->current  = 0;

    /* Calculate frames per buffer for PlayerFreq */
    {
        int frame_size = (int)(_this->spec.channels *
                         (SDL_AUDIO_BITSIZE(_this->spec.format) / 8));
        if (frame_size <= 0) frame_size = 2;
        buffer_frames = hidden->bufsize / (ULONG)frame_size;
    }

    /* Signal allocation is deferred to ThreadInit (runs in audio thread).
       PlayerFunc signals the audio thread, so the signal must belong to
       that thread's task, not the main task. */
    hidden->signal_bit = -1;
    hidden->audio_task = NULL;

    /* Open ahi.device to get AHIBase for library functions.
       Use AHI_NO_UNIT since we use the library interface, not device I/O. */
    hidden->port = CreateMsgPort();
    if (!hidden->port) {
        return SDL_SetError("AHI: Failed to create MsgPort");
    }

    hidden->req = (struct AHIRequest *)
        CreateIORequest(hidden->port, sizeof(struct AHIRequest));
    if (!hidden->req) {
        return SDL_SetError("AHI: Failed to create IORequest");
    }

    hidden->req->ahir_Version = 4;

    /* Suppress requesters during OpenDevice */
    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    err = (ULONG)OpenDevice((CONST_STRPTR)AHINAME, AHI_NO_UNIT,
                            (struct IORequest *)hidden->req, 0L);
    me->pr_WindowPtr = oldwin;

    if (err != 0) {
        DeleteIORequest((struct IORequest *)hidden->req);
        hidden->req = NULL;
        return SDL_SetError("AHI: Failed to open ahi.device");
    }

    AHIBase = (struct Library *)hidden->req->ahir_Std.io_Device;

    /* Allocate two audio buffers in public memory */
    hidden->mixbuf[0] = (Uint8 *)AllocMem(hidden->bufsize,
                                           MEMF_PUBLIC | MEMF_CLEAR);
    hidden->mixbuf[1] = (Uint8 *)AllocMem(hidden->bufsize,
                                           MEMF_PUBLIC | MEMF_CLEAR);
    if (!hidden->mixbuf[0] || !hidden->mixbuf[1]) {
        return SDL_SetError("AHI: Failed to allocate audio buffers");
    }

    /* Set up the PlayerFunc hook */
    hidden->player_hook.h_Entry = (HOOKFUNC)OS3AHI_PlayerFunc;
    hidden->player_hook.h_Data  = hidden;

    /* Calculate PlayerFreq as Fixed (16.16):
       PlayerFreq = sample_rate / buffer_frames
       This determines how often PlayerFunc is called. */
    if (buffer_frames > 0) {
        player_freq = (Fixed)(((ULONG)_this->spec.freq << 16) / buffer_frames);
    } else {
        player_freq = (Fixed)(50UL << 16);  /* fallback: 50 Hz */
    }

    /* Allocate AHI audio with the library interface */
    hidden->actrl = AHI_AllocAudio(
        AHIA_AudioID,       AHI_DEFAULT_ID,
        AHIA_MixFreq,       (ULONG)_this->spec.freq,
        AHIA_Channels,      1UL,
        AHIA_Sounds,        2UL,
        AHIA_PlayerFunc,    (ULONG)&hidden->player_hook,
        AHIA_PlayerFreq,    player_freq,
        AHIA_MinPlayerFreq, player_freq,
        AHIA_MaxPlayerFreq, player_freq,
        AHIA_UserData,      (ULONG)hidden,
        TAG_DONE);

    if (!hidden->actrl) {
        return SDL_SetError("AHI: AHI_AllocAudio failed");
    }

    /* Load two dynamic sound slots for double-buffering */
    si.ahisi_Type    = ahi_type;
    si.ahisi_Length  = buffer_frames;

    si.ahisi_Address = hidden->mixbuf[0];
    err = AHI_LoadSound(0, AHIST_DYNAMICSAMPLE, &si, hidden->actrl);
    if (err != AHIE_OK) {
        return SDL_SetError("AHI: AHI_LoadSound(0) failed (%lu)",
                            (unsigned long)err);
    }

    si.ahisi_Address = hidden->mixbuf[1];
    err = AHI_LoadSound(1, AHIST_DYNAMICSAMPLE, &si, hidden->actrl);
    if (err != AHIE_OK) {
        return SDL_SetError("AHI: AHI_LoadSound(1) failed (%lu)",
                            (unsigned long)err);
    }

    /* Set volume and frequency on channel 0 */
    AHI_SetVol(0, 0x10000L, 0x8000L, hidden->actrl, AHISF_IMM);
    AHI_SetFreq(0, (ULONG)_this->spec.freq, hidden->actrl, AHISF_IMM);

    /* Start with sound 0 */
    AHI_SetSound(0, 0, 0, 0, hidden->actrl, AHISF_IMM);

    /* Playback is started in ThreadInit after signal allocation.
       PlayerFunc needs the signal to be allocated before it can fire. */

    return 0;
}

/* ------------------------------------------------------------------
 * OS3AHI_ThreadInit
 *
 * Called from the SDL2 audio thread. Allocate the signal here so it
 * belongs to this task (not the main task that called OpenDevice).
 * ------------------------------------------------------------------ */
static void OS3AHI_ThreadInit(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    ULONG err;

    hidden->audio_task = FindTask(NULL);
    hidden->signal_bit = AllocSignal(-1);
    if (hidden->signal_bit != -1) {
        hidden->signal_mask = 1UL << hidden->signal_bit;
    } else {
        hidden->signal_mask = 0;
    }

    /* Start playback NOW -- PlayerFunc needs signal_mask to be set
       before it fires. This runs in the audio thread context. */
    if (hidden->actrl && hidden->signal_mask) {
        err = AHI_ControlAudio(hidden->actrl,
                               AHIC_Play, TRUE,
                               TAG_DONE);
        if (err != AHIE_OK) {
            SDL_SetError("AHI: AHI_ControlAudio(Play) failed");
        }
    }
}

/* ------------------------------------------------------------------
 * OS3AHI_ThreadDeinit
 * ------------------------------------------------------------------ */
static void OS3AHI_ThreadDeinit(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (hidden->signal_bit != -1) {
        FreeSignal(hidden->signal_bit);
        hidden->signal_bit = -1;
    }
}

/* ------------------------------------------------------------------
 * OS3AHI_WaitDevice
 *
 * Wait for the PlayerFunc to signal that a buffer swap occurred.
 * ------------------------------------------------------------------ */
static void OS3AHI_WaitDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;

    if (hidden->signal_mask) {
        Wait(hidden->signal_mask);
    }
}

/* ------------------------------------------------------------------
 * OS3AHI_GetDeviceBuf
 * ------------------------------------------------------------------ */
static Uint8 *OS3AHI_GetDeviceBuf(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    /* Return the buffer that is NOT currently playing */
    return hidden->mixbuf[hidden->current];
}

/* ------------------------------------------------------------------
 * OS3AHI_PlayDevice
 *
 * Buffer was just filled by the SDL2 callback. Nothing to do here --
 * PlayerFunc handles the swap at interrupt time.
 * ------------------------------------------------------------------ */
static void OS3AHI_PlayDevice(_THIS)
{
    /* No-op: PlayerFunc swaps buffers and triggers next fill via Signal */
    (void)_this;
}

/* ------------------------------------------------------------------
 * OS3AHI_CloseDevice
 * ------------------------------------------------------------------ */
static void OS3AHI_CloseDevice(_THIS)
{
    struct SDL_PrivateAudioData *hidden = _this->hidden;
    int i;

    if (!hidden) {
        return;
    }

    /* Stop playback */
    if (hidden->actrl) {
        AHI_ControlAudio(hidden->actrl,
                         AHIC_Play, FALSE,
                         TAG_DONE);
        AHI_FreeAudio(hidden->actrl);
        hidden->actrl = NULL;
    }

    /* Signal is freed in ThreadDeinit (runs in audio thread context) */

    /* Close ahi.device */
    if (hidden->req) {
        CloseDevice((struct IORequest *)hidden->req);
        DeleteIORequest((struct IORequest *)hidden->req);
        hidden->req = NULL;
        AHIBase = NULL;
    }

    if (hidden->port) {
        DeleteMsgPort(hidden->port);
        hidden->port = NULL;
    }

    /* Free audio buffers */
    for (i = 0; i < 2; i++) {
        if (hidden->mixbuf[i]) {
            FreeMem(hidden->mixbuf[i], hidden->bufsize);
            hidden->mixbuf[i] = NULL;
        }
    }

    SDL_free(hidden);
    _this->hidden = NULL;
}

/* ------------------------------------------------------------------
 * OS3AHI_Init
 * ------------------------------------------------------------------ */
static SDL_bool OS3AHI_Init(SDL_AudioDriverImpl *impl)
{
    /* Skip OpenDevice probe -- just register callbacks.
       OS3AHI_OpenDevice will open ahi.device with AHI_NO_UNIT
       and fail gracefully if not available. */

    impl->DetectDevices  = OS3AHI_DetectDevices;
    impl->OpenDevice     = OS3AHI_OpenDevice;
    impl->ThreadInit     = OS3AHI_ThreadInit;
    impl->ThreadDeinit   = OS3AHI_ThreadDeinit;
    impl->PlayDevice     = OS3AHI_PlayDevice;
    impl->GetDeviceBuf   = OS3AHI_GetDeviceBuf;
    impl->WaitDevice     = OS3AHI_WaitDevice;
    impl->CloseDevice    = OS3AHI_CloseDevice;

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
