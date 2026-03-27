/*
  SDL2 Semaphores -- AmigaOS 3.x
  Phase 0: Stub counting semaphore (single-task safe).
  Commit 4: Real Exec-based counting semaphore.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"

struct SDL_semaphore {
    Uint32 count;
};

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
    SDL_sem *sem = (SDL_sem *)SDL_calloc(1, sizeof(*sem));
    if (sem == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }
    sem->count = initial_value;
    return sem;
}

void SDL_DestroySemaphore(SDL_sem *sem)
{
    if (sem != NULL) {
        SDL_free(sem);
    }
}

int SDL_SemTryWait(SDL_sem *sem)
{
    if (sem == NULL) {
        return SDL_SetError("Passed a NULL semaphore");
    }
    if (sem->count > 0) {
        sem->count--;
        return 0;
    }
    return SDL_MUTEX_TIMEDOUT;
}

int SDL_SemWait(SDL_sem *sem)
{
    return SDL_SemTryWait(sem);
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
    (void)timeout;
    return SDL_SemTryWait(sem);
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
    if (sem == NULL) {
        SDL_SetError("Passed a NULL semaphore");
        return 0;
    }
    return sem->count;
}

int SDL_SemPost(SDL_sem *sem)
{
    if (sem == NULL) {
        return SDL_SetError("Passed a NULL semaphore");
    }
    sem->count++;
    return 0;
}

#endif /* SDL_THREAD_AMIGAOS3 */
