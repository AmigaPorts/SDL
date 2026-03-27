---
title: dos.library/DupLockFromFH
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-duplockfromfh
functions: [DupLock, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/DupLockFromFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DupLockFromFH -- Gets a lock on an open file (V36)
```
SYNOPSIS

```c
    lock = DupLockFromFH(fh)
    D0                   D1

    BPTR DupLockFromFH(BPTR)
```
FUNCTION

    Obtain a lock on the object associated with fh.  Only works if the
    file was opened using a non-exclusive mode.  Other restrictions may be
    placed on success by the filesystem.
INPUTS

    fh   - Opened file for which to obtain the lock
RESULT

    lock - Obtained lock or NULL for failure
SEE ALSO

```c
    [DupLock()](autodocs-2.0/dos-library-duplock.md), [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md)
```

---

## See Also

- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
