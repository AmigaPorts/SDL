---
title: dos.library/CurrentDir
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-currentdir
functions: [DupLock, Lock, Open, UnLock]
libraries: [dos.library]
---

# dos.library/CurrentDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CurrentDir -- Make a directory lock the current directory
SYNOPSIS

```c
    oldLock = CurrentDir( lock )
    D0                    D1

    BPTR CurrentDir(BPTR)
```
FUNCTION

```c
    CurrentDir() causes a directory associated with a lock to be made
    the current directory.  The old current directory lock is returned.

    A value of zero is a valid result here, this 0 lock represents the
    root of file system that you booted from.

    Any call that has to [Open()](autodocs-2.0/dos-library-open.md) or [Lock()](autodocs-2.0/dos-library-lock.md) files (etc) requires that
    the current directory be a valid lock or 0.
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    oldLock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [Open()](autodocs-2.0/dos-library-open.md), [DupLock()](autodocs-2.0/dos-library-duplock.md)
```

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
