---
title: timer.device/--background--
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-background
functions: [ReadEClock]
libraries: [timer.device]
---

# timer.device/--background--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

TIMER REQUEST

```c
    A time request is a non standard IO Request.  It has an [IORequest](autodocs-2.0/includes-exec-io-h.md)
    followed by a [timeval](autodocs-2.0/includes-devices-timer-h.md) structure or an eclockval structure.
```
TIMEVAL

```c
    A [timeval](autodocs-2.0/includes-devices-timer-h.md) structure consists of two longwords.  The first is
    the number of seconds, the latter is the fractional number
    of microseconds.  The microseconds must always be "normalized"
    e.g. the longword must be between 0 and one million.
```
ECLOCKVAL

```c
    A eclockval structure consists of two longwords.  The first is
    the high order 32 bits of a 64 bit number and the second is the
    the low order 32 bits.  The 64 bit number is a count of "E" clock
    ticks.  The "E" clock frequency is related to the master clock
    frequency of the machine and can be determined by calling the
    [ReadEClock()](autodocs-2.0/timer-device-readeclock.md) library like call.
```
UNITS

    The timer contains five units -- two designed to accuratly measure
    short intervals, one that has little system overhead and is very
    stable over time, and two that work like an alarm clock.
UNIT_MICROHZ

```c
    This unit uses the programmable timers in the 8520s to keep track
    of its time.  It has precision down to about 2 microseconds, but
    will drift as system load increases.  The accuracy of this unit
    is the same as that of the master clock of the machine.  This unit
    uses a [timeval](autodocs-2.0/includes-devices-timer-h.md) in its [timerequest](autodocs-2.0/includes-devices-timer-h.md).
```
UNIT_VBLANK

```c
    This unit uses a strobe from the power supply to keep track of its
    time or the "E" clock on machines without power supply strobes.
    It is very stable over time, but only has a resolution of that of
    the vertical blank interrupt.  This unit is very cheap to use, and
    should be used by those who are waiting for long periods of time
    (typically 1/2 second or more).  This unit uses a [timeval](autodocs-2.0/includes-devices-timer-h.md) in its
    [timerequest](autodocs-2.0/includes-devices-timer-h.md).
```
UNIT_ECLOCK

```c
    This unit is exacly the same as UNIT_MICROHZ except that it uses
    an eclockval instead of a [timeval](autodocs-2.0/includes-devices-timer-h.md) in its [timerequest](autodocs-2.0/includes-devices-timer-h.md).
```
UNIT_WAITUNTIL

```c
    This unit waits until the systime is greater than or equal to the
    time in the [timeval](autodocs-2.0/includes-devices-timer-h.md) in the [timerequest](autodocs-2.0/includes-devices-timer-h.md).  This unit has the same
    resolution and accuracy as that of UNIT_VBLANK.
```
UNIT_WAITECLOCK

```c
    This unit waits until the E-Clock value as returned by [ReadEClock()](autodocs-2.0/timer-device-readeclock.md)
    is greater than or equal to the eclockval in the [timerequest](autodocs-2.0/includes-devices-timer-h.md). This
    unit has the same resolution and accuracy as that of UNIT_ECLOCK.
```
LIBRARY

    In addition to the normal device calls, the timer also supports
    several direct, library like calls.
BUGS

```c
    In the V1.2/V1.3 release, the timer device has problems with
    very short time requests.  When one of these is made, other
    timer requests may be finished inaccurately.  A side effect
    is that AmigaDOS requests such as "Delay(0);" or
    "WaitForChar(x,0);" are unreliable.
```

---

## See Also

- [ReadEClock — timer.device](../autodocs/timer.device.md#readeclock)
