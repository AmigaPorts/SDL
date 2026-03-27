/*
  SDL2 Condition Variables -- AmigaOS 3.x
  Phase 0: Stub (single-task, no real waiting).
  Commit 4: Real Exec Signal/Wait implementation.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"

struct SDL_cond {
    int dummy;
};

SDL_cond *SDL_CreateCond(void)
{
    SDL_cond *cond = (SDL_cond *)SDL_calloc(1, sizeof(*cond));
    if (cond == NULL) {
        SDL_OutOfMemory();
    }
    return cond;
}

void SDL_DestroyCond(SDL_cond *cond)
{
    if (cond != NULL) {
        SDL_free(cond);
    }
}

int SDL_CondSignal(SDL_cond *cond)
{
    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }
    return 0;
}

int SDL_CondBroadcast(SDL_cond *cond)
{
    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }
    return 0;
}

int SDL_CondWait(SDL_cond *cond, SDL_mutex *mutex)
{
    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }
    /* Phase 0: immediate return (single-task, nothing to wait for) */
    return 0;
}

int SDL_CondWaitTimeout(SDL_cond *cond, SDL_mutex *mutex, Uint32 ms)
{
    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }
    /* Phase 0: immediate return with timeout */
    (void)ms;
    return SDL_MUTEX_TIMEDOUT;
}

#endif /* SDL_THREAD_AMIGAOS3 */
