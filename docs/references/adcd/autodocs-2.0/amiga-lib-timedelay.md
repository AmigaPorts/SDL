---
title: amiga.lib/TimeDelay
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-timedelay
functions: []
libraries: []
---

# amiga.lib/TimeDelay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TimeDelay -- Return after a period of time has elapsed.
SYNOPSIS

```c
    Error = TimeDelay( [Unit](autodocs-2.0/includes-exec-devices-h.md), Seconds, MicroSeconds )
    D0                 D0    D1       D2

    LONG TimeDelay( LONG, ULONG, ULONG );
```
FUNCTION

    Waits for the period of time specified before returning to the
    the caller.
INPUTS

```c
    [Unit](autodocs-2.0/includes-exec-devices-h.md) -- timer.device unit to open for this command.
    Seconds -- The seconds field of a [timerequest](autodocs-2.0/includes-devices-timer-h.md) is filled with
        this value. Check the documentation for what a partucular
        timer.device unit expects there.
    MicroSeconds -- The microseconds field of a [timerequest](autodocs-2.0/includes-devices-timer-h.md) is
        filled with this value. Check the documentation for what
        a particular timer.device units expects there.
```
RESULTS

```c
    Error -- will be zero if all went well; otherwise, non-zero.
```
NOTES

    Two likely reasons for failures are invalid unit numbers or
    no more free signal bits for this task.

    While this function first appears in V37 amiga.lib, it works
    on Kickstart V33 and higher.
SEE ALSO

```c
    [timer.device/TR_ADDREQUEST](autodocs-2.0/timer-device-tr-addrequest.md),
    timer.device/TR_WAITUNTIL,
    timer.device/WaitUnitl()
```
BUGS

