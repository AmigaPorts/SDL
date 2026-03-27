---
title: timer.device/TR_SETSYSTIME
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-tr-setsystime
functions: [GetSysTime]
libraries: [timer.device]
---

# timer.device/TR_SETSYSTIME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TR_SETSYSTIME -- Set the system time.
FUNCTION

    Set the system idea of what time it is.  The system starts out
    at time "zero" so it is safe to set it forward to the real
    time.  However, care should be taken when setting the time
    backwards.  System time is generally expected to monotonically
    increasing.
TIMER REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by timer in [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by timer in [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      [TR_GETSYSTIME](autodocs-2.0/timer-device-tr-getsystime.md)
    io_Flags        IOF_QUICK permitted
    tr_time         a [timeval](autodocs-2.0/includes-devices-timer-h.md) structure with the current system
                        time
```
RESULTS

    tr_time         will contain junk
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/TR_GETSYSTIME](autodocs-2.0/timer-device-tr-getsystime.md),
    [timer.device/GetSysTime()](autodocs-2.0/timer-device-getsystime.md),
```
BUGS

---

## See Also

- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
