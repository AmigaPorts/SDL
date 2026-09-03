/*
 * sdl2probes.c -- diagnostic exports -- removable, not part of the API
 *
 * Part of SDL2.Library-Amiga-m68K.
 * Copyright (c) 2026 JennaScvl
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. See LICENCE.MD (zlib License) for the full terms.
 */

/*
 * These are not SDL2. They are bring-up instrumentation, kept because
 * each one answered a question that had otherwise cost a crash or a
 * hang to guess at:
 *
 *   Ping           the jump table itself works (returns value + 42)
 *   ProbeBSS       the library's BSS was cleared on load
 *   ProbeSpin/CAS  SDL2 atomics work, including the EMULATE_CAS path
 *   ProbeFindTask  exec calls work from library code
 *   ProbeSem       InitSemaphore/Obtain/Release work
 *   ProbeMalloc    libnix's heap is live -- this one found the missing
 *                  __initmalloc that hung every SDL2 call
 *   ProbeTLS*      SDL_GetErrBuf's TLS path works end to end
 *   ProbeWB        why the video driver chose a screen over a window
 *
 * They occupy the TAIL of the jump table deliberately. Deleting this
 * file, its ADD2LIST lines in sdl2lib.c, and its entries at the end of
 * sdl2_lib.fd truncates the table without renumbering any real export.
 */

#include "SDL.h"

/*
 * A health check that touches nothing. If this returns 42 through the
 * jump table but SDL2_Init crashes, the library machinery -- ROMTag,
 * MakeFunctions, the table, the register convention, the generated
 * inlines -- is all sound and the fault is inside SDL2 itself. If even
 * this crashes, the fault is in the machinery and SDL2 is irrelevant.
 *
 * One call answers a question that has cost several crashes to guess at.
 */
long SDL2_Ping(register long value __asm("d0"))
{
    return value + 42;
}

/*
 * BSS probe. These two are file-scope statics with no initialiser, so
 * they live in BSS and MUST read back as zero if the library's BSS was
 * cleared when it loaded.
 *
 * This matters because SDL_GetErrBuf guards its TLS setup with a static
 * SDL_SpinLock, and SDL_AtomicLock spins until that lock reads zero. An
 * uncleared BSS therefore hangs SDL2 forever on the very first call that
 * touches the error buffer -- with no crash and no output, which is
 * precisely what happens.
 */
static long probe_bss_a;
static long probe_bss_b;

long SDL2_ProbeBSS(register long which __asm("d0"))
{
    return which ? probe_bss_b : probe_bss_a;
}

/*
 * Atomic probes -- these exercise the exact machinery SDL_GetErrBuf uses
 * before it can do anything else.
 *
 * ProbeSpin uses a LOCAL lock, so it tests Forbid/Permit and the lock
 * logic without touching any of SDL2's globals. It cannot hang unless
 * the primitive itself is broken.
 *
 * ProbeCAS goes through SDL_AtomicCAS, which on this platform takes the
 * EMULATE_CAS path: it hashes the address into a static locks[32] array
 * in SDL2's own BSS and takes one of those. If THAT array is not zero,
 * SDL_AtomicLock spins forever -- and every SDL2 entry point reaches it,
 * which matches a hang on the first call regardless of which call it is.
 *
 * Returns are deliberately distinct so the log says which step failed.
 */
long SDL2_ProbeSpin(void)
{
    SDL_SpinLock lock = 0;

    if (!SDL_AtomicTryLock(&lock))
        return -1;              /* primitive refuses a free lock */
    SDL_AtomicUnlock(&lock);
    return 1;
}

long SDL2_ProbeCAS(void)
{
    SDL_atomic_t a;

    a.value = 5;
    if (!SDL_AtomicCAS(&a, 5, 7))
        return -1;              /* CAS failed on a value it should match */
    return a.value;             /* expect 7 */
}

/*
 * SDL_GetErrBuf hangs, and ProbeSpin/ProbeCAS have cleared the atomics.
 * What is left, in the order SDL_GetErrBuf reaches it:
 *
 *   SDL_AtomicLock(&tls_lock)   -- proven by ProbeSpin/ProbeCAS
 *   SDL_TLSCreate()             -- SDL_AtomicIncRef, same machinery
 *   SDL_TLSGet(id)              -- SDL_SYS_GetTLSData: FindTask,
 *                                  InitSemaphore, ObtainSemaphore
 *   realloc_func(...)           -- libnix malloc, INSIDE A LIBRARY
 *   SDL_TLSSet(...)             -- SDL_realloc + SDL_calloc + list insert
 *
 * The probes below walk exactly that, cheapest first, each one able to
 * hang on its own so the last line in the log names the step. A library
 * has no startup module, so libnix's heap is the step that differs most
 * from the program case and it is deliberately probed before any TLS
 * call, because every TLS call allocates.
 */

#include <proto/exec.h>
#include <exec/semaphores.h>

long SDL2_ProbeFindTask(void)
{
    return (long)FindTask(NULL);        /* non-zero: exec calls work here */
}

long SDL2_ProbeSem(void)
{
    struct SignalSemaphore s;

    InitSemaphore(&s);
    ObtainSemaphore(&s);                /* hangs here => semaphores unusable */
    ReleaseSemaphore(&s);
    return 1;
}

long SDL2_ProbeMalloc(void)
{
    volatile char *p = (volatile char *)SDL_malloc(64);

    if (!p)
        return -1;                      /* heap refuses: allocator not set up */
    p[0] = 0x5A;
    p[63] = 0xA5;
    if (p[0] != 0x5A || p[63] != (char)0xA5) {
        SDL_free((void *)p);
        return -2;                      /* memory not writable/readable */
    }
    SDL_free((void *)p);
    return 1;
}

long SDL2_ProbeTLSCreate(void)
{
    return (long)SDL_TLSCreate();       /* expect a non-zero id */
}

long SDL2_ProbeTLSGet(void)
{
    /* Slot 1 on a task that has never set TLS: the interesting part is
     * not the answer but that SDL_SYS_GetTLSData returns at all. */
    return (long)SDL_TLSGet(1);         /* expect 0 */
}

long SDL2_ProbeTLSSet(void)
{
    SDL_TLSID id = SDL_TLSCreate();

    if (!id)
        return -1;
    if (SDL_TLSSet(id, (void *)0x1234, NULL) != 0)
        return -2;                      /* the allocating path failed */
    return (long)SDL_TLSGet(id);        /* expect 0x1234 */
}

/*
 * Why the driver refused to use the Workbench screen.
 *
 * OS3_OpenWindowed only opens a real titled window when:
 *
 *     is_cyber = GetCyberMapAttr(wb_bitmap, CYBRMATTR_ISCYBERGFX);
 *     if (!is_cyber && GetBitMapAttr(wb_bitmap, BMA_DEPTH) >= 15)
 *         is_cyber = 1;
 *     if (is_cyber && w <= wb->Width && h <= wb->Height)
 *         use_wb = 1;
 *
 * Otherwise it falls through to OS3_OpenScreen -- its own screen with a
 * WFLG_BORDERLESS window, which is what we got. On a Picasso96 Workbench
 * that check should pass, and SDL 1.2 opens a normal window on the same
 * machine, so it is misfiring rather than correctly declining.
 *
 * This reports each input separately instead of guessing which one.
 * Note the fallback library open: the driver tries cybergraphics.library
 * v40 and falls back to Picasso96API.library, calling them "the same
 * API" -- they are not, and GetCyberMapAttr through the wrong one would
 * return nonsense. Entry 0/1 and ProbeWBName exist to check exactly that.
 *
 * Must be called AFTER SDL_Init(VIDEO): IntuitionBase is opened by the
 * driver's VideoInit, and LockPubScreen before that would dereference
 * NULL.
 */
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <intuition/screens.h>
#include <cybergraphx/cybergraphics.h>

long SDL2_ProbeWB(register long which __asm("d0"))
{
    struct Screen *scr;
    long result = -1;

    switch (which) {
    case 0: return (long)CyberGfxBase;
    case 1: return CyberGfxBase ? (long)CyberGfxBase->lib_Version : -1;
    default: break;
    }

    if (!IntuitionBase)
        return -2;                      /* SDL_Init(VIDEO) has not run */

    scr = LockPubScreen(NULL);
    if (!scr)
        return -3;                      /* no public screen at all */

    switch (which) {
    case 2: result = (long)scr->Width;  break;
    case 3: result = (long)scr->Height; break;
    case 4: result = (long)GetBitMapAttr(scr->RastPort.BitMap, BMA_DEPTH);
            break;
    case 5: result = CyberGfxBase
                   ? (long)GetCyberMapAttr(scr->RastPort.BitMap,
                                           CYBRMATTR_ISCYBERGFX)
                   : -1;
            break;
    default: break;
    }

    UnlockPubScreen(NULL, scr);
    return result;
}

const char *SDL2_ProbeWBName(void)
{
    return CyberGfxBase ? (const char *)CyberGfxBase->lib_Node.ln_Name
                        : "(CyberGfxBase is NULL -- AGA path)";
}
