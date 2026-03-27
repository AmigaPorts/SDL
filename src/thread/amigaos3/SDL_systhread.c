/*
  SDL2 Threading -- AmigaOS 3.x via Exec Tasks / DOS Processes
  Thread creation via CreateNewProc(), data passing via tc_UserData.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_thread.h"
#include "../SDL_systhread.h"
#include "../SDL_thread_c.h"

#include <proto/exec.h>
#include <proto/dos.h>
#include <exec/tasks.h>
#include <dos/dostags.h>
#include <dos/dosextens.h>

/* Entry point wrapper for new processes.
   CreateNewProc NP_Entry calls this. We retrieve the SDL_Thread*
   from the parent-stored tc_UserData, then call the user function. */
static void OS3_ThreadEntry(void)
{
    struct Task *me = FindTask(NULL);
    SDL_Thread *thread = (SDL_Thread *)me->tc_UserData;

    if (thread && thread->userfunc) {
        /* Call SDL's internal thread runner which calls the user function */
        SDL_RunThread(thread);
    }
}

int SDL_SYS_CreateThread(SDL_Thread *thread)
{
    struct Process *proc;
    char name[64];

    SDL_snprintf(name, sizeof(name), "SDL_%s", thread->name ? thread->name : "thread");

    proc = CreateNewProcTags(
        NP_Entry, (ULONG)OS3_ThreadEntry,
        NP_Name, (ULONG)name,
        NP_StackSize, (ULONG)(thread->stacksize ? thread->stacksize : 32768),
        NP_Priority, 0,
        NP_Input, 0,     /* No I/O for threads */
        NP_Output, 0,
        NP_CloseInput, FALSE,
        NP_CloseOutput, FALSE,
        TAG_DONE
    );

    if (proc == NULL) {
        return SDL_SetError("CreateNewProc failed");
    }

    /* Store SDL_Thread pointer in the new task's tc_UserData
       so OS3_ThreadEntry can retrieve it. */
    proc->pr_Task.tc_UserData = (APTR)thread;

    /* Store the task handle for WaitThread */
    thread->handle = (SYS_ThreadHandle)&proc->pr_Task;

    return 0;
}

void SDL_SYS_SetupThread(const char *name)
{
    /* Called inside the new thread after startup.
       On AmigaOS, the process name was already set via NP_Name. */
    (void)name;
}

int SDL_SYS_SetThreadPriority(SDL_ThreadPriority priority)
{
    struct Task *task = FindTask(NULL);
    BYTE pri;

    switch (priority) {
    case SDL_THREAD_PRIORITY_LOW:
        pri = -5;
        break;
    case SDL_THREAD_PRIORITY_NORMAL:
        pri = 0;
        break;
    case SDL_THREAD_PRIORITY_HIGH:
        pri = 5;
        break;
    case SDL_THREAD_PRIORITY_TIME_CRITICAL:
        pri = 10;
        break;
    default:
        pri = 0;
        break;
    }

    SetTaskPri(task, pri);
    return 0;
}

void SDL_SYS_WaitThread(SDL_Thread *thread)
{
    /* Wait for the child process to finish.
       On AmigaOS, there's no direct "wait for task exit."
       We use a signal-based approach: the child signals the parent on exit.

       For Phase 0, use a simple polling approach.
       Phase 4+ should implement proper signal-based notification. */
    struct Task *child = (struct Task *)thread->handle;

    if (child == NULL) {
        return;
    }

    /* Poll until the task is no longer in the system.
       This is not ideal but works for Phase 0. A proper implementation
       would use a reply port or signal. */
    while (1) {
        struct Task *found;
        Forbid();
        /* Check if the task still exists by looking it up */
        found = FindTask(child->tc_Node.ln_Name);
        Permit();
        if (found != child) {
            break; /* Task is gone */
        }
        /* Yield to let the child run */
        Delay(1); /* 1 tick = ~20ms */
    }
}

void SDL_SYS_DetachThread(SDL_Thread *thread)
{
    /* Detached threads run independently. On AmigaOS, processes
       already clean up after themselves when they exit. Just clear
       the handle so WaitThread won't try to wait. */
    thread->handle = NULL;
}

SDL_threadID SDL_ThreadID(void)
{
    /* Return the current task pointer as the thread ID.
       This is unique per task and stable for its lifetime. */
    return (SDL_threadID)(ULONG)FindTask(NULL);
}

#endif /* SDL_THREAD_AMIGAOS3 */
