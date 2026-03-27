/*
  SDL2 Threading -- AmigaOS 3.x (Exec Tasks)
  Phase 0: Stub -- thread creation returns error.
  Commit 4: Real CreateNewProc() implementation.
*/

#include "../../SDL_internal.h"

#if SDL_THREAD_AMIGAOS3

#include "SDL_thread.h"
#include "../SDL_systhread.h"
#include "../SDL_thread_c.h"

int SDL_SYS_CreateThread(SDL_Thread *thread)
{
    /* Phase 0: thread creation not implemented */
    return SDL_SetError("Threads not yet implemented");
}

void SDL_SYS_SetupThread(const char *name)
{
    /* Phase 0: no-op */
    (void)name;
}

int SDL_SYS_SetThreadPriority(SDL_ThreadPriority priority)
{
    /* Phase 0: no-op, return success */
    (void)priority;
    return 0;
}

void SDL_SYS_WaitThread(SDL_Thread *thread)
{
    /* Phase 0: no-op */
    (void)thread;
}

void SDL_SYS_DetachThread(SDL_Thread *thread)
{
    /* Phase 0: no-op */
    (void)thread;
}

SDL_threadID SDL_ThreadID(void)
{
    /* Phase 0: return 1 (main task) */
    return 1;
}

#endif /* SDL_THREAD_AMIGAOS3 */
