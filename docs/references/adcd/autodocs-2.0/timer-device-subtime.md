---
title: timer.device/SubTime
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-subtime
functions: [AddTime, CmpTime]
libraries: [timer.device]
---

# timer.device/SubTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SubTime -- Subtract one time request from another.
SYNOPSIS

```c
    SubTime( Dest, Source )
             A0    A1

    void SubTime( struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *, struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *);
```
FUNCTION

```c
    This routine subtracts one [timeval](autodocs-2.0/includes-devices-timer-h.md) structure from another.  The
    results are stored in the destination (Dest - Source -> Dest)

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
    [timer.device/AddTime()](autodocs-2.0/timer-device-addtime.md),
    [timer.device/CmpTime()](autodocs-2.0/timer-device-cmptime.md)
```
BUGS

---

## See Also

- [AddTime — timer.device](../autodocs/timer.device.md#addtime)
- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
