/*
  SDL2 Timer -- AmigaOS 3.x (timer.device / ReadEClock)
  Phase 0: Stub -- returns 0 for all timing functions.
  Phase 1+: Real ReadEClock-based high-resolution timing.
*/

#include "../../SDL_internal.h"

#if SDL_TIMER_AMIGAOS3

#include "SDL_timer.h"

#include <proto/dos.h>  /* Delay() -- dos.library, always available */

void SDL_TicksInit(void)
{
    /* Phase 0: nothing to init */
    /* Phase 1+: OpenDevice("timer.device"), get EClockFrequency */
}

void SDL_TicksQuit(void)
{
    /* Phase 0: nothing to clean up */
    /* Phase 1+: CloseDevice(timer.device) */
}

Uint64 SDL_GetTicks64(void)
{
    /* Phase 0: return 0 (no timing) */
    /* Phase 1+: ReadEClock() based timing */
    return 0;
}

Uint64 SDL_GetPerformanceCounter(void)
{
    return SDL_GetTicks64();
}

Uint64 SDL_GetPerformanceFrequency(void)
{
    /* Phase 0: 1000 Hz (milliseconds) */
    /* Phase 1+: EClockFrequency from timer.device */
    return 1000;
}

void SDL_Delay(Uint32 ms)
{
    /* Phase 1+: timer.device TR_ADDREQUEST for sub-tick precision.
       Phase 0: use dos.library Delay() as a coarse yield mechanism.
       Delay(n) waits n * 1/50 s (one 50Hz tick ~= 20ms per tick).
       Delay(0) yields the current timeslice immediately -- this is
       CRITICAL for AmigaOS cooperative multitasking: SDL_AtomicLock
       calls SDL_Delay(0) inside its spin loop, and without a real
       yield the waiting task monopolizes the CPU and starves the task
       that holds the lock.  Delay(0) is the correct AmigaOS primitive
       for "yield this timeslice". */
    ULONG ticks;
    if (ms == 0) {
        /* Yield immediately -- Delay(0) does one task switch on AmigaOS */
        Delay(0UL);
    } else {
        /* Round up: 1 tick = 20ms at 50Hz.  Use (ms + 19) / 20 to
           ensure we wait at least ms milliseconds.
           Maximum practical delay via Delay() is ~24 days (ULONG ticks). */
        ticks = (ULONG)((ms + 19UL) / 20UL);
        if (ticks == 0) ticks = 1;
        Delay(ticks);
    }
}

#endif /* SDL_TIMER_AMIGAOS3 */
