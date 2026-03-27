/*
  SDL2 Mutex -- AmigaOS 3.x (SignalSemaphore)
  Phase 0: Stub using static flag (single-task safe).
  Commit 4: Real SignalSemaphore implementation.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"

struct SDL_mutex {
    int locked;
};

SDL_mutex *SDL_CreateMutex(void)
{
    SDL_mutex *mutex = (SDL_mutex *)SDL_calloc(1, sizeof(*mutex));
    if (mutex == NULL) {
        SDL_OutOfMemory();
    }
    return mutex;
}

void SDL_DestroyMutex(SDL_mutex *mutex)
{
    if (mutex != NULL) {
        SDL_free(mutex);
    }
}

int SDL_LockMutex(SDL_mutex *mutex) SDL_NO_THREAD_SAFETY_ANALYSIS
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    /* Phase 0: single-task, just set flag */
    mutex->locked = 1;
    return 0;
}

int SDL_TryLockMutex(SDL_mutex *mutex)
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    /* Phase 0: always succeeds (single-task) */
    mutex->locked = 1;
    return 0;
}

int SDL_UnlockMutex(SDL_mutex *mutex) SDL_NO_THREAD_SAFETY_ANALYSIS
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    mutex->locked = 0;
    return 0;
}

#endif /* SDL_THREAD_AMIGAOS3 */
