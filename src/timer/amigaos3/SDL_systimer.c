/*
  SDL2 Timer -- AmigaOS 3.x (timer.device / ReadEClock)

  ReadEClock returns a 64-bit monotonic counter at the E-Clock rate
  (typically 709379 Hz PAL, 715909 Hz NTSC). We capture the frequency
  and start value at init, then compute deltas for SDL_GetTicks64().

  Opening timer.device with UNIT_ECLOCK gives us access to ReadEClock()
  via TimerBase. We use AllocMem for the timerequest (no MsgPort needed
  since we only call library functions, not DoIO).

  Reference: ADCD timer-device-readeclock, timer-device-e-clock-time
*/

#include "../../SDL_internal.h"

#if SDL_TIMER_AMIGAOS3

#include "SDL_timer.h"

#ifdef WARPUP
#pragma pack(push,2)
#endif
#include <proto/exec.h>
#include <proto/dos.h>    /* Delay() */
#include <proto/timer.h>
#include <devices/timer.h>
#ifdef WARPUP
#pragma pop
#endif

/* timer.device base -- required by proto/timer.h inline calls.
   ReadEClock is interrupt-safe (ADCD), so cross-task calls via this
   shared TimerBase are safe. Phase 5 TR_ADDREQUEST will need per-task
   MsgPort + timerequest pairs (DoIO signals the creating task only). */
#ifdef WARPUP
struct Library *TimerBase = NULL;
#else
struct Device *TimerBase = NULL;
#endif

/* Timer state */
static struct MsgPort *timer_port = NULL;
static struct timerequest *timer_io = NULL;
static ULONG eclock_freq = 0;       /* E-Clock ticks per second */
static struct EClockVal eclock_start; /* value at SDL_TicksInit */
static int timer_initialized = 0;


/* Combine EClockVal hi/lo into a 64-bit value */
static SDL_INLINE Uint64 eclock_to_u64(const struct EClockVal *ev)
{
    return ((Uint64)ev->ev_hi << 32) | (Uint64)ev->ev_lo;
}

void SDL_TicksInit(void)
{
    LONG error;

    if (timer_initialized) {
        return;
    }

    /* Create MsgPort + IORequest for OpenDevice.
       OpenDevice requires a valid mn_ReplyPort in the IORequest. */
    timer_port = CreateMsgPort();
    if (!timer_port) {
        return;
    }

    timer_io = (struct timerequest *)
        CreateIORequest(timer_port, sizeof(struct timerequest));
    if (!timer_io) {
        DeleteMsgPort(timer_port);
        timer_port = NULL;
        return;
    }

    /* Open timer.device with UNIT_ECLOCK to access ReadEClock(). */
    error = OpenDevice(
        (CONST_STRPTR)TIMERNAME,
        UNIT_ECLOCK,
        (struct IORequest *)timer_io,
        0
    );
    if (error != 0) {
        DeleteIORequest((struct IORequest *)timer_io);
        timer_io = NULL;
        DeleteMsgPort(timer_port);
        timer_port = NULL;
        return;
    }

    /* Set TimerBase so proto/timer.h inlines work */
    TimerBase = (struct Device *)timer_io->tr_node.io_Device;

    /* Get E-Clock frequency and initial reading */
    eclock_freq = ReadEClock(&eclock_start);

    timer_initialized = 1;
}

void SDL_TicksQuit(void)
{
    if (!timer_initialized) {
        return;
    }

    if (timer_io) {
        CloseDevice((struct IORequest *)timer_io);
        DeleteIORequest((struct IORequest *)timer_io);
        timer_io = NULL;
    }
    if (timer_port) {
        DeleteMsgPort(timer_port);
        timer_port = NULL;
    }
    TimerBase = NULL;
    timer_initialized = 0;
}

Uint64 SDL_GetTicks64(void)
{
    struct EClockVal now;
    Uint64 start, current, delta_ticks;

    if (!timer_initialized) {
        SDL_TicksInit();
    }
    if (!timer_initialized) {
        return 0;
    }

    ReadEClock(&now);

    start = eclock_to_u64(&eclock_start);
    current = eclock_to_u64(&now);
    delta_ticks = current - start;

    /* Convert to milliseconds.
       Use 32-bit arithmetic when possible (delta fits in 32 bits for
       the first ~6000 seconds at 709 KHz, which covers all practical
       test durations). Fall back to 64-bit for longer intervals. */
    if (delta_ticks <= 0xFFFFFFFFULL) {
        ULONG d32 = (ULONG)delta_ticks;
        ULONG ms32 = (d32 / eclock_freq) * 1000UL
                    + ((d32 % eclock_freq) * 1000UL) / eclock_freq;
        return (Uint64)ms32;
    } else {
        return (delta_ticks / (Uint64)eclock_freq) * 1000ULL
             + ((delta_ticks % (Uint64)eclock_freq) * 1000ULL)
               / (Uint64)eclock_freq;
    }
}

Uint64 SDL_GetPerformanceCounter(void)
{
    struct EClockVal now;

    if (!timer_initialized) {
        SDL_TicksInit();
    }
    if (!timer_initialized) {
        return 0;
    }

    ReadEClock(&now);
    return eclock_to_u64(&now);
}

Uint64 SDL_GetPerformanceFrequency(void)
{
    if (!timer_initialized) {
        SDL_TicksInit();
    }
    if (!timer_initialized) {
        return 1000;  /* fallback: pretend milliseconds */
    }
    return (Uint64)eclock_freq;
}

void SDL_Delay(Uint32 ms)
{
    /* dos.library Delay() for coarse timing.
       Delay(n) waits n * 1/50 s (one 50Hz tick ~= 20ms per tick).
       Delay(0) yields the current timeslice immediately -- this is
       CRITICAL for AmigaOS cooperative multitasking: SDL_AtomicLock
       calls SDL_Delay(0) inside its spin loop, and without a real
       yield the waiting task monopolizes the CPU and starves the task
       that holds the lock. */
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
