---
title: timer.device/AddTime
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-addtime
functions: [CmpTime, SubTime]
libraries: [timer.device]
---

# timer.device/AddTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddTime -- Add one time request to another.
SYNOPSIS

```c
    AddTime( Dest, Source )
             A0    A1

    void AddTime( struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *, struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *);
```
FUNCTION

```c
    This routine adds one [timeval](autodocs-2.0/includes-devices-timer-h.md) structure to another.  The
    results are stored in the destination (Dest + Source -> Dest)

    A0 and A1 will be left unchanged
```
INPUTS

```c
    Dest, Source -- pointers to [timeval](autodocs-2.0/includes-devices-timer-h.md) structures.
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/CmpTime()](autodocs-2.0/timer-device-cmptime.md),
    [timer.device/SubTime()](autodocs-2.0/timer-device-subtime.md)
```
BUGS

---

## See Also

- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
- [SubTime — timer.device](../autodocs/timer.device.md#subtime)
