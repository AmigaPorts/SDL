---
title: dos.library/ParentDir
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-parentdir
functions: [DupLock, DupLockFromFH, Lock, ParentDir, ParentOfFH, UnLock]
libraries: [dos.library]
---

# dos.library/ParentDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ParentDir -- Obtain the parent of a directory or file
SYNOPSIS

```c
    newlock = ParentDir( lock )
    D0                   D1

    BPTR ParentDir(BPTR)
```
FUNCTION

```c
    The argument 'lock' is associated with a given file or directory.
    ParentDir() returns 'newlock' which is associated the parent
    directory of 'lock'.

    Taking the ParentDir() of the root of the current filing system
    returns a NULL (0) lock.  Note this 0 lock represents the root of
    file system that you booted from (which is, in effect, the parent
    of all other file system roots.)
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    newlock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [DupLock()](autodocs-2.0/dos-library-duplock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [ParentOfFH()](autodocs-2.0/dos-library-parentoffh.md), [DupLockFromFH()](autodocs-2.0/dos-library-duplockfromfh.md)
```

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ParentDir — dos.library](../autodocs/dos.library.md#parentdir)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
