---
title: timer.device/GetSysTime
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-getsystime
functions: []
libraries: []
---

# timer.device/GetSysTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetSysTime -- Get the system time. (V36)
```
SYNOPSIS

```c
    GetSysTime( Dest )
                A0

    void GetSysTime( struct [timeval](autodocs-2.0/includes-devices-timer-h.md) * );
```
FUNCTION

```c
    Ask the system what time it is.  The system time starts off at
    zero at power on, but may be initialized via the [TR_SETSYSTIME](autodocs-2.0/timer-device-tr-setsystime.md)
    timer.device command.

    System time is monotonocally increasing and guarenteed to be
    unique (except when the system time is set back).

    A0 will be left unchanged.

    This function is less expensive to use than the [TR_GETSYSTIME](autodocs-2.0/timer-device-tr-getsystime.md)
    [IORequest](autodocs-2.0/includes-exec-io-h.md).
```
INPUTS

```c
    Dest -- pointer to a [timeval](autodocs-2.0/includes-devices-timer-h.md) structure to hold the system time.
```
RESULTS

```c
    Dest -- the [timeval](autodocs-2.0/includes-devices-timer-h.md) structure will contain the system time.
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_GETSYSTIME](autodocs-2.0/timer-device-tr-getsystime.md),
    [timer.device/TR_SETSYSTIME](autodocs-2.0/timer-device-tr-setsystime.md),
```
BUGS

