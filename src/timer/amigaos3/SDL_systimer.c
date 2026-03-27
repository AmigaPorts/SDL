/*
  SDL2 Timer -- AmigaOS 3.x (timer.device / ReadEClock)
  Phase 0: Stub -- returns 0 for all timing functions.
  Phase 1+: Real ReadEClock-based high-resolution timing.
*/

#include "../../SDL_internal.h"

#if SDL_TIMER_AMIGAOS3

#include "SDL_timer.h"

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
    /* Phase 0: busy-wait (no timer.device yet) */
    /* Phase 1+: timer.device TR_ADDREQUEST */
    (void)ms;
}

#endif /* SDL_TIMER_AMIGAOS3 */
