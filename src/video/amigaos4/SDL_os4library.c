/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

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

#include <proto/exec.h>

// These symbols are required when libSDL2.so is loaded manually using elf.library (RebelSDL).
struct ExecIFace* IExec;
struct Interface* INewlib;

static struct Library* NewlibBase = NULL;

static BOOL newlibOpened = FALSE;

void _OS4_INIT(void) __attribute__((constructor));
void _OS4_EXIT(void) __attribute__((destructor));

void _OS4_INIT(void)
{
    if (IExec) {
        dprintf("IExec %p\n", IExec);
    } else {
        IExec = ((struct ExecIFace *)((*(struct ExecBase **)4)->MainInterface));
    }

    if (INewlib) {
        dprintf("INewlib %p\n", INewlib);
    } else {
        NewlibBase = OS4_OpenLibrary("newlib.library", 53);

        if (NewlibBase) {
            INewlib = OS4_GetInterface(NewlibBase);
            newlibOpened = INewlib != NULL;
        }
    }

    dprintf("IExec %p, INewlib %p\n", IExec, INewlib);
}

void _OS4_EXIT(void)
{
    if (newlibOpened && INewlib) {
        OS4_DropInterface(&INewlib);
    }

    if (NewlibBase) {
        OS4_CloseLibrary(&NewlibBase);
    }
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
