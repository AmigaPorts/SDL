---
title: timer.device/CmpTime
manual: autodocs-2.0
chapter: autodocs-2.0
section: timer-device-cmptime
functions: [AddTime, SubTime]
libraries: [timer.device]
---

# timer.device/CmpTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CmpTime -- Compare two [timeval](autodocs-2.0/includes-devices-timer-h.md) structures.
```
SYNOPSIS

```c
    result = CmpTime( Dest, Source )
    D0                A0    A1

    LONG CmpTime( struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *, struct [timeval](autodocs-2.0/includes-devices-timer-h.md) *);
```
FUNCTION

```c
    This routine compares [timeval](autodocs-2.0/includes-devices-timer-h.md) structures

    A0 and A1 will be left unchanged
```
INPUTS

```c
    Dest, Source -- pointers to [timeval](autodocs-2.0/includes-devices-timer-h.md) structures.
```
RESULTS

    result will be   0 if Dest has same time as source
                    -1 if Dest has more time than source
                    +1 if Dest has less time than source
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/AddTime()](autodocs-2.0/timer-device-addtime.md),
    [timer.device/SubTime()](autodocs-2.0/timer-device-subtime.md)
```
BUGS

```c
    Older version of this document had the sense of the return
    codes wrong; the code hasn't changed but the document has.
```

---

## See Also

- [AddTime — timer.device](../autodocs/timer.device.md#addtime)
- [SubTime — timer.device](../autodocs/timer.device.md#subtime)
