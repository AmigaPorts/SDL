---
title: timer.device/TR_GETSYSTIME
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-tr-getsystime
functions: [GetSysTime]
libraries: [timer.device]
---

# timer.device/TR_GETSYSTIME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TR_GETSYSTIME -- get the system time.
FUNCTION

```c
    Ask the system what time it is.  The system time starts off at
    zero at power on, but may be initialized via the [TR_SETSYSTIME](autodocs-2.0/timer-device-tr-setsystime.md)
    call.

    System time is monotonically increasing, and guaranteed to be
    unique (except when the system time is set backwards).
```
TIMER REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by timer in [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by timer in [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      TR_GETSYSTIME
    io_Flags        IOF_QUICK permitted
```
RESULTS

```c
    tr_time         a [timeval](autodocs-2.0/includes-devices-timer-h.md) structure with the current system
                        time
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_SETSYSTIME](autodocs-2.0/timer-device-tr-setsystime.md),
    [timer.device/GetSysTime()](autodocs-2.0/timer-device-getsystime.md),
```
BUGS

---

## See Also

- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
