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
#include "SDL_internal.h"

#if SDL_THREAD_AMIGAOS4

#include "../../main/amigaos4/SDL_os4debug.h"

#include <SDL3/SDL_thread.h>
#include "../../timer/amigaos4/SDL_os4timer_c.h"
#include "../../thread/amigaos4/SDL_systhread_c.h"

#include <proto/exec.h>
#include <dos/dos.h>

#define MUTEX_SIGNAL SIGBREAKF_CTRL_F
#define BREAK_SIGNAL SIGBREAKF_CTRL_C

struct SDL_Semaphore
{
    APTR mutex; // Protects the control block
    Uint32 count; // Current value
    struct MinList waiters; // Task waiting on this semaphore
};

typedef struct OS4_WaiterNode
{
    struct MinNode node;
    struct Task* task;
    bool queued;
} OS4_WaiterNode;

SDL_Semaphore *
SDL_CreateSemaphore(Uint32 initial_value)
{
    SDL_Semaphore* sem = (SDL_Semaphore *) SDL_malloc(sizeof(*sem));

    if (!sem) {
        SDL_OutOfMemory();
        return NULL;
    }

    sem->mutex = IExec->AllocSysObjectTags(ASOT_MUTEX,
        ASOMUTEX_Recursive, TRUE,
        TAG_DONE);

    if (!sem->mutex) {
        dprintf("Failed to allocate mutex\n");
        SDL_SetError("Failed to allocate mutex");
        SDL_free(sem);
        return NULL;
    }

    IExec->NewMinList(&sem->waiters);

    sem->count = initial_value;

    dprintf("Created semaphore %p with count %d\n", sem, sem->count);

    return (sem);
}

void
SDL_DestroySemaphore(SDL_Semaphore * sem)
{
    if (!sem) {
        dprintf("Semaphore is NULL\n");
        return;
    }

    dprintf("Destroying semaphore %p\n", sem);

    if (sem->mutex) {
        IExec->MutexObtain(sem->mutex);

		if (!IsMinListEmpty(&sem->waiters)) {
            dprintf("Semaphore %p has waiters\n", sem);

            OS4_WaiterNode* node;

            while ((node = (OS4_WaiterNode *)IExec->RemHead((struct List *)&sem->waiters))) {
                dprintf("Interrupting waiting task %p\n", node->task);

                node->queued = false;
                IExec->Signal(node->task, BREAK_SIGNAL);

                // Reschedule tasks. TODO: check if this is valid?
                IExec->MutexRelease(sem->mutex);
                IExec->MutexObtain(sem->mutex);
            }
        }

        IExec->MutexRelease(sem->mutex);

        IExec->FreeSysObject(ASOT_MUTEX, sem->mutex);
        sem->mutex = NULL;
    }

    SDL_free(sem);
}

bool
SDL_WaitSemaphoreTimeoutNS(SDL_Semaphore * sem, Sint64 timeout)
{
    if (!sem) {
        return SDL_SetError("Semaphore is NULL");
    }

    if (!sem->mutex) {
        return SDL_SetError("Mutex is NULL");
    }

    bool wait = true;

    struct Task* task = IExec->FindTask(NULL);

    ULONG alarmSignal = 0;
    OS4_TimerInstance* timer = NULL;

    if (timeout > 0) {
        timer = OS4_ThreadGetTimer();
        alarmSignal = OS4_TimerSetAlarmMicro(timer, timeout / 1000);
    }

    while (wait) {
        OS4_WaiterNode node;

        IExec->MutexObtain(sem->mutex);

        if (sem->count > 0) {
            sem->count--;
            wait = false;
        } else {
            if (timeout == 0) {
                //dprintf("Semaphore %p trying timed out\n", sem);
                IExec->MutexRelease(sem->mutex);
                return SDL_SetError("Timed out");
            }

            node.task = task;
            node.queued = true;
            IExec->AddTail((struct List *)&sem->waiters, (struct Node *)&node);
        }

        IExec->MutexRelease(sem->mutex);

        if (wait) {
            //dprintf("Semaphore %p signals before wait 0x%X, count %u\n", sem, IExec->SetSignal(0L, 0L), sem->count);

            const ULONG signals = IExec->Wait(MUTEX_SIGNAL | BREAK_SIGNAL | alarmSignal);

            IExec->MutexObtain(sem->mutex);
            if (node.queued) {
                IExec->Remove((struct Node *)&node);
                node.queued = false;
            }

            if (sem->count > 0) {
                sem->count--;
                IExec->MutexRelease(sem->mutex);
                if (timer) {
                    OS4_TimerClearAlarm(timer);
                }
                return true;
            }

            IExec->MutexRelease(sem->mutex);

            if (signals & BREAK_SIGNAL) {
                dprintf("Semaphore %p interrupted\n", sem);
                if (timer) {
                    OS4_TimerClearAlarm(timer);
                }
                return SDL_SetError("Timed out");
            }

            if (signals & alarmSignal) {
                //dprintf("Semaphore %p timer triggered\n");
                if (timer) {
                    OS4_TimerClearAlarm(timer);
                }
                return SDL_SetError("Timed out");
            }

            if (signals & MUTEX_SIGNAL) {
                dprintf("Semaphore %p got signal 0x%lX\n", sem, signals);
            }
        }
    }

    if (timer) {
        OS4_TimerClearAlarm(timer);
    }

    //dprintf("Semaphore %p obtained\n", sem);

    return true;
}

// Returns the current count of the semaphore
Uint32
SDL_GetSemaphoreValue(SDL_Semaphore * sem)
{
    Uint32 value;

    if (!sem) {
        dprintf("Semaphore is NULL\n");
        return 0;
    }

    if (!sem->mutex) {
        dprintf("Mutex is NULL\n");
        return 0;
    }

    IExec->MutexObtain(sem->mutex);
    value = sem->count;
    IExec->MutexRelease(sem->mutex);

    return value;
}

void
SDL_SignalSemaphore(SDL_Semaphore * sem)
{
    if (!sem) {
        dprintf("Semaphore is NULL\n");
        return;
    }

    if (!sem->mutex) {
        dprintf("Mutex is NULL\n");
        return;
    }

    //dprintf("Called\n");

    IExec->MutexObtain(sem->mutex);

    sem->count++;

    OS4_WaiterNode* node = (OS4_WaiterNode *)IExec->RemHead((struct List *)&sem->waiters);

    if (node) {
        node->queued = false;
        dprintf("Signalling task %p for semaphore %p\n", node->task, sem);
        IExec->Signal(node->task, MUTEX_SIGNAL);
    }

    IExec->MutexRelease(sem->mutex);

    //dprintf("Semaphore %p value %u\n", sem, sem->count);
}

#endif // SDL_THREAD_AMIGAOS4
