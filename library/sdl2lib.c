/*
 * sdl2lib.c -- ROMTag, library init/cleanup, and the export table
 *
 * Part of SDL2.Library-Amiga-m68K.
 * Copyright (c) 2026 JennaScvl
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. See LICENCE.MD (zlib License) for the full terms.
 */

#include <exec/types.h>
#include <exec/libraries.h>
#include <proto/exec.h>
#include <libinit.h>

#include "sdl2version.h"

/*
 * A PROGRAM gets these from its startup (ncrt0.o), which opens the
 * libraries and fills them in before main runs. A shared library has no
 * startup, so it must do that work itself -- these are the globals
 * libnix's own stdio and formatting code expects to find.
 */
extern struct ExecBase *SysBase;
struct ExecBase *AbsExecBase = (struct ExecBase *)4L;
struct Library  *DOSBase;
struct Library  *UtilityBase;
struct Library  *LocaleBase;
struct Library  *WorkbenchBase;
extern struct Library *MathIeeeSingBasBase, *MathIeeeSingTransBase;
extern struct Library *MathIeeeDoubBasBase, *MathIeeeDoubTransBase;

/*
 * Version, name and the SDL2 release all come from sdl2version.h, which
 * build.sh generates by reading include/SDL_version.h -- so the library
 * version and the SDL it contains cannot drift apart.
 *
 * THE LIBRARY VERSION TRACKS SDL'S. AmigaOS gives a library a
 * version/revision PAIR, and the VERSION half is what OpenLibrary's
 * second argument tests with >=. SDL's major is always 2, so putting it
 * there would make the gate useless -- every release would satisfy it.
 *
 * SDL's MINOR goes in the version instead, and the patchlevel in the
 * revision. SDL 2.33.0 becomes "sdl2.library 33.0", and
 *
 *     SDL2Base = OpenLibrary("sdl2.library", 33);
 *
 * means what it looks like: "I need at least SDL 2.33". That stays
 * monotonic for the life of SDL2.
 *
 * For a finer check at runtime, SDL's own mechanism is exported:
 *
 *     SDL_version v;
 *     SDL2_GetVersion(&v);
 *
 * The ID string carries the full three-part SDL release, because the
 * first thing anyone debugging a port wants to know is which SDL is
 * actually inside. It begins "$VER: " so the AmigaDOS `version` command
 * finds it.
 */
const UWORD LibVersion  = SDL2LIB_VERSION;
const UWORD LibRevision = SDL2LIB_REVISION;
const char  LibName[]   = SDL2LIB_NAME;
const char  LibIdString[] =
    "$VER: " SDL2LIB_NAME " " SDL2LIB_VERSTRING
    " (SDL " SDL2LIB_SDLVER ") SDL2 for AmigaOS 3\r\n";

/*
 * libnix's C runtime is started by the PROGRAM startup module. A library
 * has none, and libinit.o does not stand in for it -- its only undefined
 * symbols are LibName/LibVersion/LibRevision/LibIdString and these two
 * hooks, so every libnix subsystem that needs starting is ours to start.
 *
 * __initmalloc is the one that bites. Read out of libnix's malloc.o:
 * malloc() begins "movea.l (__memsema),a0; jsr -564(a6)" -- it obtains a
 * semaphore whose ADDRESS lives in __memsema, and __initmalloc is what
 * AllocMems that semaphore and InitSemaphores it. Without it __memsema
 * is NULL (BSS is cleared, which the ProbeBSS export confirms on the
 * real machine), so malloc calls ObtainSemaphore(NULL).
 *
 * That does not crash. Verified against Kickstart 3.1: InitSemaphore
 * (F82E1C) sets ss_QueueCount to -1 precisely so ObtainSemaphore's
 * "addq.w #1,44(a0)" lands on zero and takes the uncontested path. At
 * address zero that word is exception vector 11, never zero, so it takes
 * the CONTESTED path instead: it queues a SemaphoreRequest and calls
 * Wait(SIGF_SINGLE) for a signal that nobody will ever send. The task
 * blocks forever, cannot be reaped, and pins this library open -- and on
 * the way it corrupts exception vectors 10 and 11, which are the Line-A
 * and Line-F vectors the trap trampoline depends on.
 *
 * No libnix header declares these, so they are declared here from the
 * object itself: both take no arguments and return nothing.
 */
extern void __initmalloc(void);
extern void __exitmalloc(void);

/*
 * Runs once when the library is constructed. Returning non-zero aborts
 * the load.
 *
 * SDL_Init is deliberately not called here: which subsystems a client
 * wants is the client's business, and initialising video at load time
 * would open a display for a program that only wanted sound.
 */
LONG __stdargs __UserLibInit(struct Library *libBase, REG(a4, APTR a4))
{
    (void)libBase;
    (void)a4;

    /* MUST be first: every OpenLibrary below goes through SysBase, and
     * libinit.o does not set it for us. */
    SysBase = *(struct ExecBase **)4L;

    /* MUST be second: SDL2 is built with HAVE_MALLOC, so every SDL
     * allocation is this heap, and OpenLibrary itself is downstream of
     * nothing else here. Before this call any malloc hangs the caller. */
    __initmalloc();

    /* dos.library is not optional: libnix's stdio is built on it, and
     * SDL2's rwops calls straight into that. utility.library follows the
     * same rule for its formatting helpers. */
    DOSBase = OpenLibrary("dos.library", 37);
    /* Deliberately NOT fatal while bringing this up: a non-zero return
     * aborts the load and OpenLibrary answers NULL with no other clue,
     * which is indistinguishable from exec never finding the ROMTag.
     * Fail loudly later instead of silently here. */
    UtilityBase = OpenLibrary("utility.library", 37);

    /* libnix's libm is a shim over these; SDL2 calls sin/cos/pow. */
    MathIeeeSingBasBase   = OpenLibrary("mathieeesingbas.library", 37);
    MathIeeeSingTransBase = OpenLibrary("mathieeesingtrans.library", 37);
    MathIeeeDoubBasBase   = OpenLibrary("mathieeedoubbas.library", 37);
    MathIeeeDoubTransBase = OpenLibrary("mathieeedoubtrans.library", 37);

    return 0;
}

/*
 * Runs at expunge, once the last client has closed. This is the single
 * well-defined moment to tear SDL down with no caller inside it -- the
 * entire reason for making this a library rather than linking it into
 * every binary.
 */
VOID __stdargs __UserLibCleanup(REG(a4, APTR a4))
{
    (void)a4;

    if (MathIeeeDoubTransBase) { CloseLibrary(MathIeeeDoubTransBase); MathIeeeDoubTransBase = NULL; }
    if (MathIeeeDoubBasBase)   { CloseLibrary(MathIeeeDoubBasBase);   MathIeeeDoubBasBase = NULL; }
    if (MathIeeeSingTransBase) { CloseLibrary(MathIeeeSingTransBase); MathIeeeSingTransBase = NULL; }
    if (MathIeeeSingBasBase)   { CloseLibrary(MathIeeeSingBasBase);   MathIeeeSingBasBase = NULL; }
    if (UtilityBase) { CloseLibrary(UtilityBase); UtilityBase = NULL; }
    if (DOSBase)     { CloseLibrary(DOSBase);     DOSBase = NULL; }

    /* LAST: __exitmalloc walks __memorylist, FreeMems every block the
     * library ever allocated and frees the semaphore itself. Nothing may
     * allocate or free after this point. Doing it here rather than
     * per-close is the point of being a library -- one heap, owned by
     * the library, torn down once when the final client has gone. */
    __exitmalloc();
}

/*
 * The export table is in sdl2table.c, generated by tools/genabi.py
 * from SDL's own dynapi list. It has to be one file: ADD2LIST entries
 * concatenate in statement order within an object, so splitting them
 * would make the ABI depend on the link line.
 */
