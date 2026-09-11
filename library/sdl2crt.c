/*
 * sdl2crt.c -- globals and stubs a shared library lacks
 *
 * Part of SDL2.Library-Amiga-m68K.
 * Copyright (c) 2026 JennaScvl
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. See LICENCE.MD (zlib License) for the full terms.
 */

#include <exec/types.h>
#include <exec/execbase.h>

/* libinit.o does not define this (init_shared.o did, but that variant is
 * base-relative and vlink cannot emit its DREL16 relocations for hunk
 * output). So we define it, and __UserLibInit fills it from absolute 4
 * before anything calls into exec. */
struct ExecBase *SysBase;

void          *_WBenchMsg;          /* no Workbench startup message   */
long           __SaveSP;
long           __a4_init;
int            __argc;
char         **__argv;
unsigned long  __commandlen;
char          *__commandline;
unsigned long  __stack = 16384;     /* libnix stack-check reference   */
void          *__stdiowin;
struct Library *IconBase;

/* Used by libnix's per-task data-segment support (libinitr). Empty
 * because init_shared.o gives ONE data segment to all callers. */
long __datadata_relocs[1];

/* Bracket libnix uses to walk export stubs; empty here. */
void *__export_stubs_start[1];
void *__export_stubs_end[1];

/*
 * libnix's libm is a thin layer over the mathieee*.library set, so their
 * bases must exist and be opened. sdl2lib.c's __UserLibInit opens them;
 * they live here beside the other startup-supplied globals.
 */
struct Library *MathIeeeSingBasBase;
struct Library *MathIeeeSingTransBase;
struct Library *MathIeeeDoubBasBase;
struct Library *MathIeeeDoubTransBase;

/*
 * Section bounds and the small-data base. A linker script normally
 * defines these; nothing in a library uses them for anything but bounds
 * checks, so zero is a truthful answer here.
 */
long _stext;
long _etext;
long SDA_BASE_;

/* A library must never terminate its caller. Reaching this is a bug, so
 * it must be findable rather than silent -- an Alert is visible where a
 * quiet hang is not. */
/*
 * Both spellings are needed: C's exit() becomes the linker symbol _exit
 * that libnix's stdio calls, while _exit() becomes __exit. libnix
 * references both.
 *
 * Neither may terminate the CALLER -- this is a library. They return
 * instead, which is wrong in the abstract but correct here: reaching
 * them means something inside SDL2 gave up, and a returning stub leaves
 * the caller alive to notice rather than taking the process down.
 */
void exit(int code)
{
    (void)code;
}

void _exit(int code)
{
    (void)code;
}

/*
 * libnix's auto-open library list. __initlibraries walks it at startup
 * and __exitlibraries at exit. Empty and NULL-terminated is the correct
 * answer here: sdl2.library opens the libraries it needs explicitly in
 * __UserLibInit, so there is nothing for libnix to open on its behalf.
 */
void *__LIB_LIST__[1] = { 0 };

/* ------------------------------------------------------------------
 * The three amiga.lib functions SDL2 uses.
 *
 * amiga.lib itself cannot be linked here: its members carry RELRELOC16
 * and DREL16 relocations, which vlink cannot emit for hunk output. All
 * three are legacy wrappers over things exec has provided directly
 * since V37, so implementing them is simpler than fighting the linker.
 * ------------------------------------------------------------------ */

#include <exec/io.h>
#include <exec/ports.h>
#include <proto/exec.h>

/*
 * BeginIO jumps to the device's own BEGINIO vector, which sits at the
 * fixed offset -30 from the device base with the request in a1 and the
 * device in a6. The vector is a JMP instruction, so its address is
 * called directly.
 */
void BeginIO(struct IORequest *io)
{
    void (*beginio)(register struct IORequest *__asm("a1"),
                    register struct Device  *__asm("a6"));

    if (!io || !io->io_Device)
        return;
    beginio = (void *)((UBYTE *)io->io_Device - 30);
    beginio(io, io->io_Device);
}

struct MsgPort *CreatePort(UBYTE *name, LONG pri)
{
    struct MsgPort *port = CreateMsgPort();

    if (port) {
        port->mp_Node.ln_Name = (char *)name;
        port->mp_Node.ln_Pri  = (BYTE)pri;
        if (name)
            AddPort(port);
    }
    return port;
}

void DeletePort(struct MsgPort *port)
{
    if (!port)
        return;
    if (port->mp_Node.ln_Name)
        RemPort(port);
    DeleteMsgPort(port);
}
