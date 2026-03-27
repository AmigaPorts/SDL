---
title: dos.library/ParentOfFH
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-parentoffh
functions: [DupLockFromFH, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/ParentOfFH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ParentOfFH -- returns a lock on the parent directory of a file (V36)
```
SYNOPSIS

```c
    lock = ParentOfFH(fh)
    D0               D1

    BPTR ParentOfFH(BPTR)
```
FUNCTION

    Returns a shared lock on the parent directory of the filehandle.
INPUTS

    fh   - Filehandle you want the parent of.
RESULT

    lock - Lock on parent directory of the filehandle or NULL for failure.
SEE ALSO

```c
    Parent(), [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md) [DupLockFromFH()](autodocs-2.0/dos-library-duplockfromfh.md)
```

---

## See Also

- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
