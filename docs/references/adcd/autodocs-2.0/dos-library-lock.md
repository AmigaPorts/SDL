---
title: dos.library/Lock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-lock
functions: [ChangeMode, DupLock, DupLockFromFH, Lock, NameFromLock, UnLock]
libraries: [dos.library]
---

# dos.library/Lock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Lock -- Lock a directory or file
SYNOPSIS

```c
    lock  = Lock( name, accessMode )
    D0            D1        D2

    BPTR Lock(STRPTR, LONG)
```
FUNCTION

```c
    A filing system lock on the file or directory 'name' is returned if
    possible.

    If the accessMode is ACCESS_READ, the lock is a shared read lock;
    if the accessMode is ACCESS_WRITE then it is an exclusive write
    lock.  Do not use random values for mode.

    If Lock() fails (that is, if it cannot obtain a filing system lock
    on the file or directory) it returns a zero.

    Tricky assumptions about the internal format of a lock are unwise,
    as are any attempts to use the fl_Link or fl_Access fields.
```
INPUTS

    name       - pointer to a null-terminated string
    accessMode - integer
RESULTS

    lock - BCPL pointer to a lock
SEE ALSO

```c
    [UnLock()](autodocs-2.0/dos-library-unlock.md), [DupLock()](autodocs-2.0/dos-library-duplock.md), [ChangeMode()](autodocs-2.0/dos-library-changemode.md), [NameFromLock()](autodocs-2.0/dos-library-namefromlock.md), [DupLockFromFH()](autodocs-2.0/dos-library-duplockfromfh.md)
```

---

## See Also

- [ChangeMode — dos.library](../autodocs/dos.library.md#changemode)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [DupLockFromFH — dos.library](../autodocs/dos.library.md#duplockfromfh)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [NameFromLock — dos.library](../autodocs/dos.library.md#namefromlock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
