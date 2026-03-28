/*
  SDL2 Threading -- AmigaOS 3.x via Exec Tasks / DOS Processes

  Thread creation via CreateNewProc(), synchronization via signals.

  WaitThread design (based on ADCD III-17 SIGF_SINGLE pattern and
  SDL2 OS4 port's signal-based approach):

  - Parent allocates a signal bit and stores it + its task pointer
    in the SDL_Thread struct (accessible to child via tc_UserData).
  - Child calls SDL_RunThread(), then signals the parent before exiting.
  - Parent Wait()s on that signal bit -- no polling, no reading freed memory.
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

#include "../../audio/amigaos3/SDL_os3debug.h"

/* Per-thread context stored in SDL_Thread->handle area.
 * The child reads parent_task and parent_signal to notify on exit. */
typedef struct {
    struct Task *parent_task;   /* task to signal on thread exit */
    ULONG parent_sigmask;       /* signal mask (1 << allocated bit) */
    BYTE parent_sigbit;         /* the allocated signal bit */
} OS3_ThreadData;

/* Entry point wrapper for new processes.
   CreateNewProc NP_Entry calls this. We retrieve the SDL_Thread*
   from the parent-stored tc_UserData, then call the user function,
   then signal the parent before exiting. */
static void OS3_ThreadEntry(void)
{
    struct Task *me = FindTask(NULL);
    SDL_Thread *thread = (SDL_Thread *)me->tc_UserData;

    DLOG("ThreadEntry: task=%p thread=%p name=%s",
         (void *)me, (void *)thread,
         thread && thread->name ? thread->name : "(null)");

    if (thread && thread->userfunc) {
        SDL_RunThread(thread);
    }

    /* Signal the parent that we are done. The parent may be in
     * SDL_SYS_WaitThread() doing Wait(). This must happen BEFORE
     * the process exits, while parent_task is still valid.
     * (ADCD III-17: child signals parent before exiting.) */
    if (thread && thread->handle) {
        OS3_ThreadData *td = (OS3_ThreadData *)thread->handle;
        DLOG("ThreadEntry: signaling parent=%p mask=0x%lx before exit",
             (void *)td->parent_task, td->parent_sigmask);
        Signal(td->parent_task, td->parent_sigmask);
        DLOG("ThreadEntry: signal sent, returning");
    }
}

int SDL_SYS_CreateThread(SDL_Thread *thread)
{
    struct Process *proc;
    OS3_ThreadData *td;
    char name[64];
    BYTE sigbit;

    /* Allocate a signal bit in the PARENT task for the child to signal us.
     * Per ADCD ch.22: signals are task-relative, allocated in calling task. */
    sigbit = AllocSignal(-1);
    if (sigbit == -1) {
        return SDL_SetError("No signal bits available for thread sync");
    }

    td = (OS3_ThreadData *)SDL_malloc(sizeof(*td));
    if (!td) {
        FreeSignal(sigbit);
        return SDL_OutOfMemory();
    }
    td->parent_task = FindTask(NULL);
    td->parent_sigbit = sigbit;
    td->parent_sigmask = 1UL << sigbit;

    /* Store in thread->handle so both parent and child can access it */
    thread->handle = (SYS_ThreadHandle)td;

    SDL_snprintf(name, sizeof(name), "SDL_%s", thread->name ? thread->name : "thread");

    /* Forbid() prevents task switching so the new process cannot run
       OS3_ThreadEntry before we set tc_UserData. Without this, the new
       process may read tc_UserData as NULL and exit immediately, causing
       SDL2's startup semaphore wait to deadlock.
       See ADCD ch.22: signals are task-relative. */
    Forbid();

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
        Permit();
        FreeSignal(sigbit);
        SDL_free(td);
        thread->handle = NULL;
        return SDL_SetError("CreateNewProc failed");
    }

    /* Store SDL_Thread pointer in the new task's tc_UserData
       so OS3_ThreadEntry can retrieve it. */
    proc->pr_Task.tc_UserData = (APTR)thread;

    DLOG("CreateThread: proc=%p name=%s sigbit=%d parent=%p",
         (void *)proc, name, (int)sigbit, (void *)td->parent_task);

    Permit(); /* now the child can run and find tc_UserData set */

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
    OS3_ThreadData *td = (OS3_ThreadData *)thread->handle;

    if (td == NULL) {
        return;
    }

    DLOG("WaitThread: waiting on mask=0x%lx for thread=%p name=%s",
         td->parent_sigmask, (void *)thread,
         thread->name ? thread->name : "(null)");

    /* Wait for the child to signal us before it exits.
     * Per ADCD III-17: Wait() on the signal the child will send.
     * No polling, no reading freed task memory. */
    Wait(td->parent_sigmask);

    DLOG("WaitThread: signal received, child signaled exit");

    /* Child has signaled but may not have fully exited yet -- it still
     * needs to return from OS3_ThreadEntry() and go through DOS process
     * cleanup (stack deallocation, tc_MemEntry freeing, etc.).
     * Give it time to finish before we free resources that might share
     * the same memory pool. Delay(1) = ~20ms = one tick. */
    Delay(1);

    DLOG("WaitThread: cleanup delay done, freeing sigbit=%d",
         (int)td->parent_sigbit);

    /* Now safe to free the signal bit and the thread data. */
    FreeSignal(td->parent_sigbit);
    SDL_free(td);
    thread->handle = NULL;
}

void SDL_SYS_DetachThread(SDL_Thread *thread)
{
    OS3_ThreadData *td = (OS3_ThreadData *)thread->handle;

    /* Detached threads run independently. Free the signal bit
     * since nobody will Wait on it. The child will Signal() into
     * the void (harmless -- the bit is freed, signal is ignored). */
    if (td != NULL) {
        FreeSignal(td->parent_sigbit);
        SDL_free(td);
    }
    thread->handle = NULL;
}

SDL_threadID SDL_ThreadID(void)
{
    /* Return the current task pointer as the thread ID.
       This is unique per task and stable for its lifetime. */
    return (SDL_threadID)(ULONG)FindTask(NULL);
}

#endif /* SDL_THREAD_AMIGAOS3 */
