---
title: dos.library/DupLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-duplock
functions: [DupLock, DupLockFromFH, Lock, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/DupLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DupLock -- Duplicate a lock
SYNOPSIS

```c
    lock = DupLock( lock )
    D0              D1

    BPTR DupLock(BPTR)
```
FUNCTION

```c
    DupLock() is passed a shared filing system lock.  This is the ONLY
    way to obtain a duplicate of a lock... simply copying is not
    allowed.

    Another lock to the same object is then returned.  It is not
    possible to create a copy of a exclusive lock.

    A zero return indicates failure.
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    newLock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [DupLockFromFH()](autodocs-2.0/dos-library-duplockfromfh.md), [ParentOfFH()](autodocs-2.0/dos-library-parentoffh.md)
```

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
