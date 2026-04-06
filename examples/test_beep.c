/*
 * test_beep: Standalone audio.device test (no SDL).
 *
 * Opens audio.device, plays a 440 Hz square wave for ~1 second
 * via CMD_WRITE, then exits. Uses BeginIO per ADCD recommendation.
 *
 * If this hangs on FS-UAE, audio.device CMD_WRITE is broken in
 * the emulator and no SDL audio backend can work via audio.device.
 */

#include <stdio.h>
#include <string.h>
#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <devices/audio.h>
#include <exec/memory.h>
#include <graphics/gfxbase.h>
#ifdef WARPUP
#pragma pop
#endif

static const char *verstag = "$VER: test_beep 0.1 (28.03.2026)";
long __stack = 16384;

/* Channel allocation: try any single channel */
static UBYTE channels[] = { 1, 2, 4, 8 };

int main(int argc, char *argv[])
{
    struct MsgPort *port = NULL;
    struct IOAudio *req = NULL;
    BYTE *buf = NULL;
    struct Process *me;
    APTR oldwin;
    struct GfxBase *gfx;
    ULONG clock;
    UWORD period;
    int i;
    int bufsize = 256; /* small buffer, ~11ms at 22050 Hz */
    int cycles = 1;    /* single cycle -- does WaitIO still complete? */

    (void)argc;
    (void)argv;
    (void)verstag;

    printf("test_beep: audio.device direct test (no SDL)\n\n");
    fflush(stdout);

    /* Detect PAL/NTSC */
    gfx = (struct GfxBase *)OpenLibrary((CONST_STRPTR)"graphics.library", 0L);
    if (gfx) {
        clock = (gfx->DisplayFlags & PAL) ? 3546895L : 3579545L;
        printf("Clock: %lu (%s)\n", clock,
               (gfx->DisplayFlags & PAL) ? "PAL" : "NTSC");
        CloseLibrary((struct Library *)gfx);
    } else {
        clock = 3579545L;
        printf("Clock: %lu (default NTSC)\n", clock);
    }
    fflush(stdout);

    period = (UWORD)(clock / 22050L);
    printf("Period: %u (22050 Hz)\n", (unsigned)period);
    fflush(stdout);

    /* Allocate CHIP RAM buffer */
    buf = (BYTE *)AllocMem(bufsize, MEMF_CHIP | MEMF_CLEAR);
    if (!buf) {
        printf("FAIL: AllocMem CHIP RAM failed\n");
        return 10;
    }
    printf("CHIP buffer: %p (%d bytes)\n", (void *)buf, bufsize);
    fflush(stdout);

    /* Fill with square wave (440 Hz at 22050 Hz = ~50 samples per cycle) */
    for (i = 0; i < bufsize; i++) {
        buf[i] = (i % 50 < 25) ? 64 : -64;
    }

    /* Create MsgPort */
    port = CreateMsgPort();
    if (!port) {
        printf("FAIL: CreateMsgPort\n");
        FreeMem(buf, bufsize);
        return 10;
    }
    printf("MsgPort: OK\n");
    fflush(stdout);

    /* Create IOAudio */
    req = (struct IOAudio *)CreateIORequest(port, sizeof(struct IOAudio));
    if (!req) {
        printf("FAIL: CreateIORequest\n");
        DeleteMsgPort(port);
        FreeMem(buf, bufsize);
        return 10;
    }
    printf("IOAudio: OK\n");
    fflush(stdout);

    /* Set up channel allocation */
    req->ioa_Request.io_Message.mn_Node.ln_Pri = 0;
    req->ioa_AllocKey = 0;
    req->ioa_Data = channels;
    req->ioa_Length = sizeof(channels);

    /* Suppress requesters */
    me = (struct Process *)FindTask(NULL);
    oldwin = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1L;

    printf("Opening audio.device...\n");
    fflush(stdout);

    if (OpenDevice((CONST_STRPTR)AUDIONAME, 0L,
                   (struct IORequest *)req, 0L) != 0) {
        me->pr_WindowPtr = oldwin;
        printf("FAIL: OpenDevice audio.device\n");
        DeleteIORequest((struct IORequest *)req);
        DeleteMsgPort(port);
        FreeMem(buf, bufsize);
        return 10;
    }
    me->pr_WindowPtr = oldwin;

    printf("audio.device: OPEN (AllocKey=%d, Unit=%p)\n",
           (int)req->ioa_AllocKey, (void *)req->ioa_Request.io_Unit);
    fflush(stdout);

    /* Set up CMD_WRITE */
    req->ioa_Request.io_Command = CMD_WRITE;
    req->ioa_Request.io_Flags = ADIOF_PERVOL;
    req->ioa_Data = (UBYTE *)buf;
    req->ioa_Length = bufsize;
    req->ioa_Period = period;
    req->ioa_Volume = 64;
    req->ioa_Cycles = cycles;

    printf("Sending CMD_WRITE (cycles=%d, period=%u, len=%d)...\n",
           cycles, (unsigned)period, bufsize);
    fflush(stdout);

    /* Use BeginIO as ADCD recommends for audio.device */
    BeginIO((struct IORequest *)req);

    printf("BeginIO sent, waiting...\n");
    fflush(stdout);

    /* Wait for completion */
    WaitIO((struct IORequest *)req);

    printf("WaitIO returned! io_Error=%d\n",
           (int)req->ioa_Request.io_Error);
    fflush(stdout);

    /* Cleanup */
    CloseDevice((struct IORequest *)req);
    DeleteIORequest((struct IORequest *)req);
    DeleteMsgPort(port);
    FreeMem(buf, bufsize);

    printf("PASS: audio.device test complete\n");
    return 0;
}
