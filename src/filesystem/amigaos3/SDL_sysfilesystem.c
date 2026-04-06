/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

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

/*
  SDL2 Filesystem -- AmigaOS 3.x (dos.library)

  BasePath:  PROGDIR: (the directory containing the running program)
  PrefPath:  ENVARC:{org}/{app}/ (persistent prefs, survives reboot)

  Uses Lock/CreateDir from dos.library.
  Suppresses volume requesters via pr_WindowPtr = -1.
*/

#include "../../SDL_internal.h"

#if SDL_FILESYSTEM_AMIGAOS3

#include "SDL_filesystem.h"
#include "SDL_error.h"
#include "SDL_stdinc.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>
#ifdef WARPUP
#pragma pop
#endif

/* Create a directory, ignoring ERROR_OBJECT_EXISTS (already exists). */
/* Returns 1 on success (created or exists), 0 on failure. */
static int OS3_CreateDir(const char *path)
{
    BPTR lock;

    lock = CreateDir((CONST_STRPTR)path);
    if (lock) {
        UnLock(lock);
        return 1;
    }

    /* Already exists is fine */
    if (IoErr() == ERROR_OBJECT_EXISTS) {
        return 1;
    }

    return 0;
}

char *SDL_GetBasePath(void)
{
    /* PROGDIR: is an AmigaOS assign that always points to the
       directory containing the currently running program.
       The trailing colon acts as a path separator. */
    return SDL_strdup("PROGDIR:");
}

char *SDL_GetPrefPath(const char *org, const char *app)
{
    char *path;
    size_t len;
    struct Process *me;
    APTR old_window;

    if (!app) {
        SDL_InvalidParamError("app");
        return NULL;
    }

    /* Suppress volume requesters while probing ENVARC: */
    me = (struct Process *)FindTask(NULL);
    old_window = me->pr_WindowPtr;
    me->pr_WindowPtr = (APTR)-1;

    if (org) {
        /* ENVARC:org/app/ */
        char org_dir[128];

        len = SDL_strlen("ENVARC:") + SDL_strlen(org) + 1
            + SDL_strlen(app) + 1 + 1;

        SDL_snprintf(org_dir, sizeof(org_dir), "ENVARC:%s", org);
        if (!OS3_CreateDir(org_dir)) {
            me->pr_WindowPtr = old_window;
            SDL_SetError("Couldn't create directory %s", org_dir);
            return NULL;
        }

        path = (char *)SDL_malloc(len);
        if (!path) {
            me->pr_WindowPtr = old_window;
            SDL_OutOfMemory();
            return NULL;
        }

        SDL_snprintf(path, len, "ENVARC:%s/%s/", org, app);
    } else {
        /* ENVARC:app/ */
        len = SDL_strlen("ENVARC:") + SDL_strlen(app) + 1 + 1;

        path = (char *)SDL_malloc(len);
        if (!path) {
            me->pr_WindowPtr = old_window;
            SDL_OutOfMemory();
            return NULL;
        }

        SDL_snprintf(path, len, "ENVARC:%s/", app);
    }

    /* Create the final app directory */
    if (!OS3_CreateDir(path)) {
        me->pr_WindowPtr = old_window;
        SDL_SetError("Couldn't create directory %s", path);
        SDL_free(path);
        return NULL;
    }

    me->pr_WindowPtr = old_window;
    return path;
}

#endif /* SDL_FILESYSTEM_AMIGAOS3 */
