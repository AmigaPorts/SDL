/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2022 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_AMIGAOS4

#include "SDL_os4library.h"

#include "../../main/amigaos4/SDL_os4debug.h"
#include "../../thread/amigaos4/SDL_systhread_c.h"

#include <proto/exec.h>

// These symbols are required when libSDL2.so is loaded manually using elf.library (RebelSDL).
struct ExecIFace* IExec;
struct Interface* INewlib;
struct DOSIFace* IDOS;
struct ElfIFace* IElf;

static struct Library* NewlibBase;
static struct Library* DOSBase;
static struct Library* ElfBase;

static BOOL newlibOpened = FALSE;
static BOOL dosOpened = FALSE;
static BOOL elfOpened = FALSE;

static int initCount = 0;

// This is also called from SDL_InitSubSystem(), in case application is calling
// SDL_Quit() and then reinitializing something (for example testautomation)
void OS4_INIT(void)
{
    // IExec is required for dprintf!
    if (IExec) {
        dprintf("IExec %p\n", IExec);
    } else {
        IExec = ((struct ExecIFace *)((*(struct ExecBase **)4)->MainInterface));
        dprintf("IExec %p initialized\n", IExec);
    }

    if (initCount > 0) {
        dprintf("initCount %d - skip re-initialization\n", initCount);
        return;
    }

    if (IDOS) {
        dprintf("IDOS %p\n", IDOS);
    } else {
        DOSBase = OS4_OpenLibrary("dos.library", 53);

        if (DOSBase) {
            IDOS = (struct DOSIFace *)OS4_GetInterface(DOSBase);
            dprintf("IDOS %p initialized\n", IDOS);
            dosOpened = IDOS != NULL;
        }
    }

    if (INewlib) {
        dprintf("INewlib %p\n", INewlib);
    } else {
        NewlibBase = OS4_OpenLibrary("newlib.library", 53);

        if (NewlibBase) {
            INewlib = OS4_GetInterface(NewlibBase);
            dprintf("INewlib %p initialized\n", INewlib);
            newlibOpened = INewlib != NULL;
        }
    }

    if (IElf) {
        dprintf("IElf %p\n", IElf);
    } else {
        ElfBase = OS4_OpenLibrary("elf.library", 53);

        if (ElfBase) {
            IElf = (struct ElfIFace *)OS4_GetInterface(ElfBase);
            dprintf("IElf %p initialized\n", IElf);
            elfOpened = IElf != NULL;
        }
    }

    OS4_InitThreadSubSystem();

    initCount++;

    dprintf("initCount %d\n", initCount);
}

// It seems that destructor is not called when RebelSDL application closes. This is also
// called from SDL_Quit().
void OS4_QUIT(void)
{
    if (initCount < 1) {
        dprintf("initCount %d - skip quitting\n", initCount);
        return;
    }

    OS4_QuitThreadSubSystem();

    if (elfOpened) {
        OS4_DropInterface((struct Interface**)&IElf);
    }

    OS4_CloseLibrary(&ElfBase);

    if (newlibOpened) {
        OS4_DropInterface(&INewlib);
    }

    OS4_CloseLibrary(&NewlibBase);

    if (dosOpened) {
        OS4_DropInterface((struct Interface**)&IDOS);
    }

    OS4_CloseLibrary(&DOSBase);

    initCount--;

    dprintf("initCount %d\n", initCount);
}

struct Library *
OS4_OpenLibrary(STRPTR name, ULONG version)
{
    struct Library* lib = IExec->OpenLibrary(name, version);

    dprintf("Opening '%s' version %u %s (address %p)\n",
        name, version, lib ? "succeeded" : "FAILED", lib);

    return lib;
}

struct Interface *
OS4_GetInterface(struct Library * lib)
{
    struct Interface* interface = IExec->GetInterface(lib, "main", 1, NULL);

    dprintf("Getting interface for libbase %p %s (address %p)\n",
        lib, interface ? "succeeded" : "FAILED", interface);

    return interface;
}

void
OS4_DropInterface(struct Interface ** interface)
{
    if (interface && *interface) {
        dprintf("Dropping interface %p\n", *interface);
        IExec->DropInterface(*interface);
        *interface = NULL;
    }
}

void
OS4_CloseLibrary(struct Library ** library)
{
    if (library && *library) {
        dprintf("Closing library %p\n", *library);
        IExec->CloseLibrary(*library);
        *library = NULL;
    }
}

#endif
