/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

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
#include "SDL_internal.h"

#if SDL_THREAD_AMIGAOS4

/* Mutex functions using the AmigaOS 4 API */

#include "../../main/amigaos4/SDL_os4debug.h"

#include "SDL_mutex.h"

#include <proto/exec.h>

struct SDL_Mutex
{
    APTR mtx;
};

SDL_Mutex *
SDL_CreateMutex(void)
{
    SDL_Mutex* mutex;

    /* Allocate mutex memory */
    mutex = (SDL_Mutex *) SDL_malloc(sizeof(*mutex));

    if (mutex) {
        mutex->mtx = IExec->AllocSysObjectTags(ASOT_MUTEX,
            ASOMUTEX_Recursive, TRUE,
            TAG_DONE);

        if (!mutex->mtx) {
            dprintf("Failed to allocate mutex\n");
            SDL_free(mutex);
            SDL_OutOfMemory();
            return NULL;
        }

        dprintf("Created mutex %p\n", mutex->mtx);
    } else {
        SDL_OutOfMemory();
    }

    return mutex;
}

void
SDL_DestroyMutex(SDL_Mutex * mutex)
{
    if (mutex) {
        dprintf("Destroying mutex %p\n", mutex->mtx);
        IExec->FreeSysObject(ASOT_MUTEX, mutex->mtx);
        mutex->mtx = NULL;
        SDL_free(mutex);
    }
}

void
SDL_LockMutex(SDL_Mutex * mutex)
{
    //dprintf("Called\n");

    if (mutex) {
        IExec->MutexObtain(mutex->mtx);

        //dprintf("Locked mutex %p\n", mutex);
    }
}

bool
SDL_TryLockMutex(SDL_Mutex * mutex)
{
    int retval = true;
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }

    //dprintf("Called\n");

    if (!IExec->MutexAttempt(mutex->mtx)) {
        retval = false;
    }
    return retval;
}

void
SDL_UnlockMutex(SDL_Mutex * mutex)
{
    //dprintf("Unlocking mutex %p\n", mutex);

    if (mutex) {
        IExec->MutexRelease(mutex->mtx);
    }
}

#endif /* SDL_THREAD_AMIGAOS4 */

/* vi: set ts=4 sw=4 expandtab: */

