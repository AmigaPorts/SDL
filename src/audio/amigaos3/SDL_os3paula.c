/*
  SDL2 Audio Driver -- AmigaOS 3.x (Paula / audio.device)

  Native Paula DMA playback. Works on all Amigas (real hw + FS-UAE).
  8-bit signed mono, double-buffered via BeginIO/WaitIO.

  Paula DMA can ONLY read from CHIP RAM. All sample buffers are
  allocated with AllocMem(MEMF_CHIP).

  CRITICAL: On AmigaOS, MsgPort signals are task-relative (ADCD ch.22).
  CreateMsgPort() allocates a signal bit from the CALLING task. WaitIO()
  can only receive that signal in the same task. SDL2 runs audio in a
  separate Exec Task, so we defer MsgPort+OpenDevice to the first
  PlayDevice call (which runs in the audio thread).

  Reference: ADCD 2.1 devices chapter 2 (audio.device)
  Reference: ADCD 2.1 chapter 22 (Exec Signals)
*/

#include "../../SDL_internal.h"

#if SDL_AUDIO_DRIVER_PAULA

#include "SDL_audio.h"
#include "SDL_timer.h"
#include "../SDL_audio_c.h"
#include "../SDL_sysaudio.h"
#include "SDL_os3paula.h"
#include "SDL_os3debug.h"

#define _THIS SDL_AudioDevice *_this

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <graphics/gfxbase.h>
#include <devices/audio.h>
#include <exec/memory.h>
#ifdef WARPUP
#pragma pop
#endif

#define OS3PAULA_DRIVER_NAME "paula"

/* Channel allocation: any single channel for mono playback */
static UBYTE paula_channels[] = { 1, 2, 4, 8 };

static void OS3PAULA_DetectDevices(void)
{
}

/* Probe whether audio.device can be opened.
   Called from Init() in the main task context -- just open/close. */
static int OS3PAULA_Available(void)
{
    struct MsgPort *port = NULL;
    struct IOAudio *req = NULL;
    int ok = 0;
    struct Process *me;
    APTR oldwin;

    port = CreateMsgPort();
    if (!port) return 0;

    req = (struct IOAudio *)CreateIORequest(port, sizeof(struct IOAudio));
    if (!req) {
        DeleteMsgPort(port);
        return 0;
    }

    req->ioa_Request.io_Message.mn_Node.ln_Pri = 0;
    req->ioa_AllocKey = 0;
    req->ioa_Data = paula_channels;
    req->ioa_Length = sizeof(paula_channels);

    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    if (OpenDevice((CONST_STRPTR)AUDIONAME, 0L,
                   (struct IORequest *)req, 0L) == 0) {
        ok = 1;
        CloseDevice((struct IORequest *)req);
    }

    me->pr_WindowPtr = oldwin;
    DeleteIORequest((struct IORequest *)req);
    DeleteMsgPort(port);

    DLOG("Paula Available: %d", ok);
    return ok;
}

static ULONG OS3PAULA_GetClock(void)
{
    struct GfxBase *gfx;
    ULONG clk = 3579545L;

    gfx = (struct GfxBase *)OpenLibrary((CONST_STRPTR)"graphics.library", 0L);
    if (gfx) {
        if (gfx->DisplayFlags & PAL)
            clk = 3546895L;
        CloseLibrary((struct Library *)gfx);
    }
    return clk;
}

/* Open audio.device from the CURRENT task context.
   Called lazily from PlayDevice (which runs in the audio thread).
   This ensures MsgPort signal bits belong to the audio thread. */
static int OS3PAULA_LazyOpen(struct OS3PaulaData *data)
{
    struct Process *me;
    APTR oldwin;
    struct Task *task = FindTask(NULL);

    DLOG("LazyOpen: task=%p (%s)", (void *)task, task->tc_Node.ln_Name);

    data->port = CreateMsgPort();
    if (!data->port) {
        DLOG("LazyOpen: CreateMsgPort FAILED");
        return -1;
    }
    DLOG("LazyOpen: port=%p sigbit=%d sigtask=%p",
         (void *)data->port, (int)data->port->mp_SigBit,
         (void *)data->port->mp_SigTask);

    data->req[0] = (struct IOAudio *)
        CreateIORequest(data->port, sizeof(struct IOAudio));
    if (!data->req[0]) {
        DLOG("LazyOpen: CreateIORequest FAILED");
        return -1;
    }

    data->req[0]->ioa_Request.io_Message.mn_Node.ln_Pri = 0;
    data->req[0]->ioa_AllocKey = 0;
    data->req[0]->ioa_Data = paula_channels;
    data->req[0]->ioa_Length = sizeof(paula_channels);

    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    DLOG("LazyOpen: OpenDevice...");
    if (OpenDevice((CONST_STRPTR)AUDIONAME, 0L,
                   (struct IORequest *)data->req[0], 0L) != 0) {
        me->pr_WindowPtr = oldwin;
        DLOG("LazyOpen: OpenDevice FAILED");
        return -1;
    }

    me->pr_WindowPtr = oldwin;
    DLOG("LazyOpen: OpenDevice OK, AllocKey=%d Unit=%p",
         (int)data->req[0]->ioa_AllocKey,
         (void *)data->req[0]->ioa_Request.io_Unit);

    /* Clone req[0] to req[1] for double-buffering */
    data->req[1] = (struct IOAudio *)AllocVec(sizeof(struct IOAudio),
                                               MEMF_PUBLIC);
    if (!data->req[1]) {
        DLOG("LazyOpen: req[1] alloc FAILED");
        return -1;
    }

    SDL_memcpy(data->req[1], data->req[0], sizeof(struct IOAudio));

    /* Mark both requests as "replied" so CheckIO considers them done
       before their first real submission. Without this, CheckIO on an
       un-submitted request sees ln_Type != NT_REPLYMSG and returns
       "not done", causing WaitIO to hang forever. */
    data->req[0]->ioa_Request.io_Message.mn_Node.ln_Type = NT_REPLYMSG;
    data->req[1]->ioa_Request.io_Message.mn_Node.ln_Type = NT_REPLYMSG;

    data->dev_open = 1;
    DLOG("LazyOpen: SUCCESS");
    return 0;
}

static int OS3PAULA_OpenDevice(_THIS, const char *devname)
{
    struct OS3PaulaData *data = NULL;
    struct Task *task = FindTask(NULL);

    (void)devname;

    DLOG("OpenDevice: task=%p (%s)", (void *)task, task->tc_Node.ln_Name);

    data = (struct OS3PaulaData *)SDL_malloc(sizeof(struct OS3PaulaData));
    if (!data) return SDL_OutOfMemory();
    SDL_memset(data, 0, sizeof(struct OS3PaulaData));
    _this->hidden = (struct SDL_PrivateAudioData *)data;

    /* Paula: mono, 8-bit signed only. SDL2 converts from app format. */
    _this->spec.channels = 1;
    _this->spec.format = AUDIO_S8;

    if (_this->spec.freq > 22050) _this->spec.freq = 22050;
    if (_this->spec.freq < 4000) _this->spec.freq = 4000;

    SDL_CalculateAudioSpec(&_this->spec);

    data->clock = OS3PAULA_GetClock();
    data->period = (UWORD)(data->clock / (ULONG)_this->spec.freq);
    if (data->period < 124) data->period = 124;

    data->bufsize = (ULONG)_this->spec.size;
    if (data->bufsize & 1) data->bufsize++;

    DLOG("OpenDevice: freq=%d fmt=0x%x ch=%d samples=%d size=%lu period=%u",
         _this->spec.freq, (unsigned)_this->spec.format,
         (int)_this->spec.channels, (int)_this->spec.samples,
         (unsigned long)data->bufsize, (unsigned)data->period);

    /* Allocate CHIP RAM buffers now (safe from any task) */
    data->chipbuf[0] = (UBYTE *)AllocMem(data->bufsize,
                                          MEMF_CHIP | MEMF_CLEAR);
    data->chipbuf[1] = (UBYTE *)AllocMem(data->bufsize,
                                          MEMF_CHIP | MEMF_CLEAR);
    if (!data->chipbuf[0] || !data->chipbuf[1]) {
        DLOG("OpenDevice: CHIP RAM alloc FAILED (%lu bytes)",
             (unsigned long)data->bufsize);
        return SDL_SetError("Paula: CHIP RAM alloc failed (%lu bytes)",
                            (unsigned long)data->bufsize);
    }

    DLOG("OpenDevice: chipbuf[0]=%p chipbuf[1]=%p",
         (void *)data->chipbuf[0], (void *)data->chipbuf[1]);

    /* MsgPort + OpenDevice deferred to LazyOpen (audio thread context).
       See file header comment about task-relative signals. */
    data->dev_open = 0;
    data->current = 0;
    data->playing = 0;

    DLOG("OpenDevice: OK (device deferred to audio thread)");
    return 0;
}

static void OS3PAULA_WaitDevice(_THIS)
{
    struct OS3PaulaData *data = (struct OS3PaulaData *)_this->hidden;

    if (!data->dev_open || data->playing < 1)
        return;

    DLOG("WaitDevice: playing=%d cur=%d CheckIO...", data->playing, data->current);

    if (!CheckIO((struct IORequest *)data->req[data->current])) {
        DLOG("WaitDevice: not done, calling WaitIO...");
        WaitIO((struct IORequest *)data->req[data->current]);
        DLOG("WaitDevice: WaitIO returned");
    } else {
        DLOG("WaitDevice: already done");
    }
}

static Uint8 *OS3PAULA_GetDeviceBuf(_THIS)
{
    struct OS3PaulaData *data = (struct OS3PaulaData *)_this->hidden;
    return (Uint8 *)data->chipbuf[data->current];
}

static void OS3PAULA_PlayDevice(_THIS)
{
    struct OS3PaulaData *data = (struct OS3PaulaData *)_this->hidden;
    struct IOAudio *req;

    /* Lazy-open audio.device in the audio thread context.
       MsgPort signal bits will belong to THIS task. */
    if (!data->dev_open) {
        if (OS3PAULA_LazyOpen(data) < 0) {
            DLOG("PlayDevice: LazyOpen FAILED, returning");
            return;
        }
    }

    req = data->req[data->current];

    if (data->playing > 1) {
        DLOG("PlayDevice: WaitIO on prev buf %d...", data->current);
        WaitIO((struct IORequest *)req);
        DLOG("PlayDevice: WaitIO returned");
    }

    req->ioa_Request.io_Command = CMD_WRITE;
    req->ioa_Request.io_Flags   = ADIOF_PERVOL;
    req->ioa_Data               = data->chipbuf[data->current];
    req->ioa_Length             = data->bufsize;
    req->ioa_Period             = data->period;
    req->ioa_Volume             = 64;
    req->ioa_Cycles             = 1;

    DLOG("PlayDevice: BeginIO cur=%d data=%p len=%lu cyc=%d",
         data->current, (void *)data->chipbuf[data->current],
         (unsigned long)data->bufsize, (int)req->ioa_Cycles);
    DLOG("PlayDevice: req=%p cmd=%d flags=0x%x unit=%p dev=%p",
         (void *)req, (int)req->ioa_Request.io_Command,
         (unsigned)req->ioa_Request.io_Flags,
         (void *)req->ioa_Request.io_Unit,
         (void *)req->ioa_Request.io_Device);

    BeginIO((struct IORequest *)req);

    DLOG("PlayDevice: BeginIO returned, io_Error=%d io_Flags=0x%x",
         (int)req->ioa_Request.io_Error,
         (unsigned)req->ioa_Request.io_Flags);

    data->current ^= 1;
    data->playing++;

    DLOG("PlayDevice: now cur=%d playing=%d", data->current, data->playing);
}

static void OS3PAULA_CloseDevice(_THIS)
{
    struct OS3PaulaData *data = (struct OS3PaulaData *)_this->hidden;

    if (!data) return;

    DLOG("CloseDevice: dev_open=%d playing=%d", data->dev_open, data->playing);

    if (data->dev_open && data->req[0]) {
        if (data->req[1] && data->playing > 1) {
            AbortIO((struct IORequest *)data->req[1]);
            WaitIO((struct IORequest *)data->req[1]);
        }

        if (data->playing > 0) {
            AbortIO((struct IORequest *)data->req[0]);
            WaitIO((struct IORequest *)data->req[0]);
        }

        if (data->req[1] && data->playing > 1) {
            AbortIO((struct IORequest *)data->req[1]);
            WaitIO((struct IORequest *)data->req[1]);
        }

        CloseDevice((struct IORequest *)data->req[0]);

        if (data->req[1]) {
            FreeVec(data->req[1]);
            data->req[1] = NULL;
        }
        DeleteIORequest((struct IORequest *)data->req[0]);
        data->req[0] = NULL;
    }

    data->playing = 0;

    if (data->chipbuf[0]) {
        FreeMem(data->chipbuf[0], data->bufsize);
        data->chipbuf[0] = NULL;
    }
    if (data->chipbuf[1]) {
        FreeMem(data->chipbuf[1], data->bufsize);
        data->chipbuf[1] = NULL;
    }

    if (data->port) {
        DeleteMsgPort(data->port);
        data->port = NULL;
    }

    SDL_free(data);
    _this->hidden = NULL;

    DLOG("CloseDevice: done");
}

static SDL_bool OS3PAULA_Init(SDL_AudioDriverImpl *impl)
{
    /* Lighthouse: confirm debug logging works */
    DLOG("=== Paula Init starting ===");

    if (!OS3PAULA_Available())
        return SDL_FALSE;

    impl->DetectDevices = OS3PAULA_DetectDevices;
    impl->OpenDevice    = OS3PAULA_OpenDevice;
    impl->PlayDevice    = OS3PAULA_PlayDevice;
    impl->GetDeviceBuf  = OS3PAULA_GetDeviceBuf;
    impl->WaitDevice    = OS3PAULA_WaitDevice;
    impl->CloseDevice   = OS3PAULA_CloseDevice;

    impl->OnlyHasDefaultOutputDevice = SDL_TRUE;
    impl->HasCaptureSupport = SDL_FALSE;
    impl->ProvidesOwnCallbackThread = SDL_FALSE;

    return SDL_TRUE;
}

AudioBootStrap OS3PAULA_bootstrap = {
    OS3PAULA_DRIVER_NAME, "AmigaOS Paula (audio.device)",
    OS3PAULA_Init, SDL_FALSE
};

#endif /* SDL_AUDIO_DRIVER_PAULA */
