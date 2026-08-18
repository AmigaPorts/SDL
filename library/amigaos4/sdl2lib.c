/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied warranty.
  In no event will the authors be held liable for any damages arising from
  the use of this software.

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

#include <dos/dos.h>
#include <exec/resident.h>
#include <proto/exec.h>

#include <interfaces/sdl2.h>
#include "sdl2_gateproto.h"

#define SDL2_LIBRARY_NAME "sdl2.library"
#define SDL2_LIBRARY_PRIORITY 0
#define SDL2_LIBRARY_VERSION SDL_MINOR_VERSION
#define SDL2_LIBRARY_REVISION SDL_PATCHLEVEL
#define SDL2_STRINGIFY_(value) #value
#define SDL2_STRINGIFY(value) SDL2_STRINGIFY_(value)
#define SDL2_LIBRARY_VERSION_STRING \
    "sdl2.library " SDL2_STRINGIFY(SDL_MINOR_VERSION) "." \
    SDL2_STRINGIFY(SDL_PATCHLEVEL) " (" __AMIGADATE__ ") [SDL " \
    SDL2_STRINGIFY(SDL_MAJOR_VERSION) "." SDL2_STRINGIFY(SDL_MINOR_VERSION) "." \
    SDL2_STRINGIFY(SDL_PATCHLEVEL) "]"

struct SDL2LibraryBase
{
    struct Library Library;
    uint16 Padding;
    BPTR SegList;
};

extern struct ExecIFace *IExec;
extern struct Interface *INewlib;
static struct Library *SDL2NewlibBase;

uint32 SDL2Lib_Obtain(struct SDL2IFace *Self)
{
    return ++Self->Data.RefCount;
}

uint32 SDL2Lib_Release(struct SDL2IFace *Self)
{
    return --Self->Data.RefCount;
}

static CONST_APTR SDL2Lib_MainVectors[] = {
    (CONST_APTR)SDL2Lib_Obtain,
    (CONST_APTR)SDL2Lib_Release,
    (CONST_APTR)0,
    (CONST_APTR)0,
#include "sdl2_functable.h"
    (CONST_APTR)-1
};

static struct SDL2LibraryBase *SDL2Lib_Open(struct LibraryManagerInterface *Self,
                                            uint32 version)
{
    struct SDL2LibraryBase *base = (struct SDL2LibraryBase *)Self->Data.LibBase;
    (void)version;
    ++base->Library.lib_OpenCnt;
    base->Library.lib_Flags &= (UBYTE)~LIBF_DELEXP;
    return base;
}

static BPTR SDL2Lib_Expunge(struct LibraryManagerInterface *Self)
{
    struct SDL2LibraryBase *base = (struct SDL2LibraryBase *)Self->Data.LibBase;
    BPTR seglist = 0;

    if (base->Library.lib_OpenCnt == 0) {
        SDL_Quit();
        IExec->Remove(&base->Library.lib_Node);
        seglist = base->SegList;
        if (INewlib) {
            IExec->DropInterface(INewlib);
            INewlib = NULL;
        }
        if (SDL2NewlibBase) {
            IExec->CloseLibrary(SDL2NewlibBase);
            SDL2NewlibBase = NULL;
        }
        IExec->DeleteLibrary(&base->Library);
    } else {
        base->Library.lib_Flags |= LIBF_DELEXP;
    }
    return seglist;
}

static BPTR SDL2Lib_Close(struct LibraryManagerInterface *Self)
{
    struct SDL2LibraryBase *base = (struct SDL2LibraryBase *)Self->Data.LibBase;

    --base->Library.lib_OpenCnt;
    if (base->Library.lib_OpenCnt == 0 &&
        (base->Library.lib_Flags & LIBF_DELEXP) != 0) {
        return SDL2Lib_Expunge(Self);
    }
    return 0;
}

static APTR SDL2Lib_ManagerVectors[] = {
    (APTR)SDL2Lib_Obtain,
    (APTR)SDL2Lib_Release,
    (APTR)0,
    (APTR)0,
    (APTR)SDL2Lib_Open,
    (APTR)SDL2Lib_Close,
    (APTR)SDL2Lib_Expunge,
    (APTR)0,
    (APTR)-1
};

static struct TagItem SDL2Lib_ManagerTags[] = {
    { MIT_Name, (uint32)"__library" },
    { MIT_VectorTable, (uint32)SDL2Lib_ManagerVectors },
    { MIT_Version, 1 },
    { TAG_END, 0 }
};

static struct TagItem SDL2Lib_MainTags[] = {
    { MIT_Name, (uint32)"main" },
    { MIT_VectorTable, (uint32)SDL2Lib_MainVectors },
    { MIT_Version, 1 },
    { TAG_END, 0 }
};

static APTR SDL2Lib_Interfaces[] = {
    SDL2Lib_ManagerTags,
    SDL2Lib_MainTags,
    NULL
};

static struct SDL2LibraryBase *SDL2Lib_Init(struct SDL2LibraryBase *base,
                                            BPTR seglist,
                                            struct ExecIFace *exec)
{
    IExec = exec;
    SDL2NewlibBase = IExec->OpenLibrary("newlib.library", 53);
    if (!SDL2NewlibBase) {
        return NULL;
    }
    INewlib = IExec->GetInterface(SDL2NewlibBase, "main", 1, NULL);
    if (!INewlib) {
        IExec->CloseLibrary(SDL2NewlibBase);
        SDL2NewlibBase = NULL;
        return NULL;
    }

    base->Library.lib_Node.ln_Type = NT_LIBRARY;
    base->Library.lib_Node.ln_Pri = SDL2_LIBRARY_PRIORITY;
    base->Library.lib_Node.ln_Name = SDL2_LIBRARY_NAME;
    base->Library.lib_Flags = LIBF_SUMUSED | LIBF_CHANGED;
    base->Library.lib_Version = SDL2_LIBRARY_VERSION;
    base->Library.lib_Revision = SDL2_LIBRARY_REVISION;
    base->Library.lib_IdString = SDL2_LIBRARY_VERSION_STRING;
    base->SegList = seglist;
    return base;
}

static struct TagItem SDL2Lib_CreateTags[] = {
    { CLT_DataSize, sizeof(struct SDL2LibraryBase) },
    { CLT_InitFunc, (uint32)SDL2Lib_Init },
    { CLT_Interfaces, (uint32)SDL2Lib_Interfaces },
    { TAG_END, 0 }
};

static const char SDL2Lib_VerTag[] __attribute__((used)) =
    "\0$VER: " SDL2_LIBRARY_VERSION_STRING;

static struct Resident SDL2Lib_Resident __attribute__((used)) = {
    RTC_MATCHWORD,
    &SDL2Lib_Resident,
    &SDL2Lib_Resident + 1,
    RTF_NATIVE | RTF_AUTOINIT,
    SDL2_LIBRARY_VERSION,
    NT_LIBRARY,
    SDL2_LIBRARY_PRIORITY,
    SDL2_LIBRARY_NAME,
    SDL2_LIBRARY_VERSION_STRING,
    SDL2Lib_CreateTags
};

void _start(void)
{
}
