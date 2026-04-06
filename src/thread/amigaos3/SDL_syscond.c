/*
  SDL2 Condition Variables -- AmigaOS 3.x
  Implemented using Exec Signals + SignalSemaphore for the wait queue.

  Design: Each waiter allocates a signal bit, adds itself to the wait list,
  then releases the mutex and Wait()s for the signal. CondSignal/CondBroadcast
  sends signals to waiting tasks.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_mutex.h"
#include "SDL_thread.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <exec/tasks.h>
#ifdef WARPUP
#pragma pop
#endif

#define OS3_COND_MAX_WAITERS 32

struct SDL_cond {
    struct SignalSemaphore lock;  /* Protects the waiter list */
    int num_waiters;
    struct {
        struct Task *task;
        BYTE signal_bit;
    } waiters[OS3_COND_MAX_WAITERS];
};

SDL_cond *SDL_CreateCond(void)
{
    SDL_cond *cond = (SDL_cond *)SDL_calloc(1, sizeof(*cond));
    if (cond == NULL) {
        SDL_OutOfMemory();
        return NULL;
    }
    InitSemaphore(&cond->lock);
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

    ObtainSemaphore(&cond->lock);
    if (cond->num_waiters > 0) {
        /* Wake the first waiter */
        struct Task *waiter = cond->waiters[0].task;
        BYTE sig = cond->waiters[0].signal_bit;

        /* Remove from wait list by shifting */
        cond->num_waiters--;
        if (cond->num_waiters > 0) {
            SDL_memmove(&cond->waiters[0], &cond->waiters[1],
                        cond->num_waiters * sizeof(cond->waiters[0]));
        }

        Signal(waiter, 1UL << sig);
    }
    ReleaseSemaphore(&cond->lock);

    return 0;
}

int SDL_CondBroadcast(SDL_cond *cond)
{
    int i;

    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }

    ObtainSemaphore(&cond->lock);
    for (i = 0; i < cond->num_waiters; i++) {
        Signal(cond->waiters[i].task, 1UL << cond->waiters[i].signal_bit);
    }
    cond->num_waiters = 0;
    ReleaseSemaphore(&cond->lock);

    return 0;
}

int SDL_CondWaitTimeout(SDL_cond *cond, SDL_mutex *mutex, Uint32 ms)
{
    struct Task *me;
    BYTE sig;
    ULONG received;
    ULONG wait_mask;
    int retval = 0;

    if (cond == NULL) {
        return SDL_SetError("Passed a NULL condition variable");
    }

    me = FindTask(NULL);
    sig = AllocSignal(-1);
    if (sig == -1) {
        return SDL_SetError("No signal bits available");
    }

    wait_mask = 1UL << sig;

    /* Add ourselves to the wait list */
    ObtainSemaphore(&cond->lock);
    if (cond->num_waiters >= OS3_COND_MAX_WAITERS) {
        ReleaseSemaphore(&cond->lock);
        FreeSignal(sig);
        return SDL_SetError("Condition variable wait queue full");
    }
    cond->waiters[cond->num_waiters].task = me;
    cond->waiters[cond->num_waiters].signal_bit = sig;
    cond->num_waiters++;
    ReleaseSemaphore(&cond->lock);

    /* Release the mutex before waiting (standard condvar protocol) */
    SDL_UnlockMutex(mutex);

    /* Wait for signal or timeout */
    if (ms == SDL_MUTEX_MAXWAIT) {
        received = Wait(wait_mask);
    } else {
        /* For timeout, we'd need timer.device.
           Phase 0: just wait without timeout (treat as infinite). */
        received = Wait(wait_mask);
        /* TODO Phase 4: implement timed wait via timer.device */
    }

    /* Re-acquire the mutex (standard condvar protocol) */
    SDL_LockMutex(mutex);

    /* Check if we timed out (signal not received) */
    if (!(received & wait_mask)) {
        /* Remove ourselves from wait list */
        ObtainSemaphore(&cond->lock);
        {
            int i;
            for (i = 0; i < cond->num_waiters; i++) {
                if (cond->waiters[i].task == me && cond->waiters[i].signal_bit == sig) {
                    cond->num_waiters--;
                    if (i < cond->num_waiters) {
                        SDL_memmove(&cond->waiters[i], &cond->waiters[i + 1],
                                    (cond->num_waiters - i) * sizeof(cond->waiters[0]));
                    }
                    break;
                }
            }
        }
        ReleaseSemaphore(&cond->lock);
        retval = SDL_MUTEX_TIMEDOUT;
    }

    FreeSignal(sig);
    return retval;
}

int SDL_CondWait(SDL_cond *cond, SDL_mutex *mutex)
{
    return SDL_CondWaitTimeout(cond, mutex, SDL_MUTEX_MAXWAIT);
}

#endif /* SDL_THREAD_AMIGAOS3 */
