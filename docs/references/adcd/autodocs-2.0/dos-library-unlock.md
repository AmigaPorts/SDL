---
title: dos.library/UnLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-unlock
functions: [CreateDir, DupLock, DupLockFromFH, Lock, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/UnLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UnLock -- Unlock a directory or file
SYNOPSIS

```c
    UnLock( lock )
            D1

    void UnLock(BPTR)
```
FUNCTION

```c
    The filing system lock (obtained from [Lock()](autodocs-2.0/dos-library-lock.md), [DupLock()](autodocs-2.0/dos-library-duplock.md), or
    [CreateDir()](autodocs-2.0/dos-library-createdir.md)) is removed and deallocated.
```
INPUTS

    lock - BCPL pointer to a lock
NOTE

```c
    passing zero to UnLock() is harmless
```
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [DupLock()](autodocs-2.0/dos-library-duplock.md), [ParentOfFH()](autodocs-2.0/dos-library-parentoffh.md), [DupLockFromFH()](autodocs-2.0/dos-library-duplockfromfh.md)
```

---

## See Also

- [CreateDir — dos.library](../autodocs/dos.library.md#createdir)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
