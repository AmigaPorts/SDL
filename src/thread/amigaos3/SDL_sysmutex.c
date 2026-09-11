/*
  SDL2 Mutex -- AmigaOS 3.x via Exec SignalSemaphore
  Real implementation using InitSemaphore/ObtainSemaphore/ReleaseSemaphore.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <exec/semaphores.h>
#ifdef WARPUP
#pragma pop
#endif

struct SDL_mutex {
    struct SignalSemaphore sem;
};

SDL_mutex *SDL_CreateMutex(void)
{
    SDL_mutex *mutex = (SDL_mutex *)SDL_calloc(1, sizeof(*mutex));
    if (mutex == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }
    InitSemaphore(&mutex->sem);
    return mutex;
}

void SDL_DestroyMutex(SDL_mutex *mutex)
{
    if (mutex != NULL) {
        /* SignalSemaphore has no cleanup function -- just free memory.
           Caller must ensure no task holds the semaphore. */
        SDL_free(mutex);
    }
}

int SDL_LockMutex(SDL_mutex *mutex) SDL_NO_THREAD_SAFETY_ANALYSIS
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    /* ObtainSemaphore is blocking and supports recursive locking
       (same task can lock multiple times via ss_NestCount). */
    ObtainSemaphore(&mutex->sem);
    return 0;
}

int SDL_TryLockMutex(SDL_mutex *mutex)
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    /* AttemptSemaphore returns TRUE if locked, FALSE if held by another task */
    if (AttemptSemaphore(&mutex->sem)) {
        return 0;
    }
    return SDL_MUTEX_TIMEDOUT;
}

int SDL_UnlockMutex(SDL_mutex *mutex) SDL_NO_THREAD_SAFETY_ANALYSIS
{
    if (mutex == NULL) {
        return SDL_SetError("Passed a NULL mutex");
    }
    /* ReleaseSemaphore decrements ss_NestCount.
       If count reaches 0 and tasks are waiting, next waiter is woken. */
    ReleaseSemaphore(&mutex->sem);
    return 0;
}

#endif /* SDL_THREAD_AMIGAOS3 */
