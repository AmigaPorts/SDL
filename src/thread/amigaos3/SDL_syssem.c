/*
  SDL2 Counting Semaphores -- AmigaOS 3.x
  Implemented using SignalSemaphore + counter + Exec Signals.

  Design: A SignalSemaphore protects the counter. Wait decrements;
  if counter reaches 0, the waiter blocks on a signal bit until
  Post increments and signals a waiter.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"

#include <proto/exec.h>
#include <exec/tasks.h>

#define OS3_SEM_MAX_WAITERS 32

struct SDL_semaphore {
    struct SignalSemaphore lock;  /* Protects count and waiter list */
    Uint32 count;
    int num_waiters;
    struct {
        struct Task *task;
        BYTE signal_bit;
    } waiters[OS3_SEM_MAX_WAITERS];
};

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
    SDL_sem *sem = (SDL_sem *)SDL_calloc(1, sizeof(*sem));
    if (sem == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }
    InitSemaphore(&sem->lock);
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
    int retval;

    if (sem == NULL) {
        return SDL_SetError("Passed a NULL semaphore");
    }

    ObtainSemaphore(&sem->lock);
    if (sem->count > 0) {
        sem->count--;
        retval = 0;
    } else {
        retval = SDL_MUTEX_TIMEDOUT;
    }
    ReleaseSemaphore(&sem->lock);

    return retval;
}

int SDL_SemWait(SDL_sem *sem)
{
    return SDL_SemWaitTimeout(sem, SDL_MUTEX_MAXWAIT);
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
    struct Task *me;
    BYTE sig;
    ULONG wait_mask;

    if (sem == NULL) {
        return SDL_SetError("Passed a NULL semaphore");
    }

    /* Fast path: try without blocking */
    ObtainSemaphore(&sem->lock);
    if (sem->count > 0) {
        sem->count--;
        ReleaseSemaphore(&sem->lock);
        return 0;
    }

    /* If no wait requested, return immediately */
    if (timeout == 0) {
        ReleaseSemaphore(&sem->lock);
        return SDL_MUTEX_TIMEDOUT;
    }

    /* Need to block: allocate a signal and add to waiter list */
    me = FindTask(NULL);
    sig = AllocSignal(-1);
    if (sig == -1) {
        ReleaseSemaphore(&sem->lock);
        return SDL_SetError("No signal bits available");
    }

    if (sem->num_waiters >= OS3_SEM_MAX_WAITERS) {
        ReleaseSemaphore(&sem->lock);
        FreeSignal(sig);
        return SDL_SetError("Semaphore wait queue full");
    }

    wait_mask = 1UL << sig;
    sem->waiters[sem->num_waiters].task = me;
    sem->waiters[sem->num_waiters].signal_bit = sig;
    sem->num_waiters++;
    ReleaseSemaphore(&sem->lock);

    /* Block until signaled */
    Wait(wait_mask);

    FreeSignal(sig);
    return 0;
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
    Uint32 value;

    if (sem == NULL) {
        SDL_SetError("Passed a NULL semaphore");
        return 0;
    }

    ObtainSemaphore(&sem->lock);
    value = sem->count;
    ReleaseSemaphore(&sem->lock);

    return value;
}

int SDL_SemPost(SDL_sem *sem)
{
    if (sem == NULL) {
        return SDL_SetError("Passed a NULL semaphore");
    }

    ObtainSemaphore(&sem->lock);
    if (sem->num_waiters > 0) {
        /* Wake the first waiter instead of incrementing count */
        struct Task *waiter = sem->waiters[0].task;
        BYTE sig = sem->waiters[0].signal_bit;

        sem->num_waiters--;
        if (sem->num_waiters > 0) {
            SDL_memmove(&sem->waiters[0], &sem->waiters[1],
                        sem->num_waiters * sizeof(sem->waiters[0]));
        }

        ReleaseSemaphore(&sem->lock);
        Signal(waiter, 1UL << sig);
    } else {
        sem->count++;
        ReleaseSemaphore(&sem->lock);
    }

    return 0;
}

#endif /* SDL_THREAD_AMIGAOS3 */
