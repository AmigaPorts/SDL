---
title: dos.library/NameFromLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-namefromlock
functions: [IoErr, Lock, NameFromFH]
libraries: [dos.library]
---

# dos.library/NameFromLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NameFromLock -- Returns the name of a locked object (V36)
```
SYNOPSIS

```c
    success = NameFromLock(lock, buffer, len)
    D0                      D1     D2    D3

    BOOL NameFromLock(BPTR, STRPTR, LONG)
```
FUNCTION

```c
    Returns a fully qualified path for the lock.  This routine is
    guaranteed not to write more than len characters into the buffer.  The
    name will be null-terminated.  NOTE: if the volume is not mounted,
    the system will request it (unless of course you set pr_WindowPtr to
    -1).  If the volume is not mounted or inserted, it will return an
    error.  If the lock passed in is NULL, "SYS:" will be returned. If
    the buffer is too short, an error will be returned, and [IoErr()](autodocs-2.0/dos-library-ioerr.md) will
    return ERROR_LINE_TOO_LONG.
```
INPUTS

    lock   - Lock of object to be examined.
    buffer - Buffer to store name.
    len    - Length of buffer.
RESULT

    success - Success/failure indicator.
BUGS

    Should return the name of the boot volume instead of SYS: for a NULL
    lock.
SEE ALSO

```c
    [NameFromFH()](autodocs-2.0/dos-library-namefromfh.md), [Lock()](autodocs-2.0/dos-library-lock.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [NameFromFH — dos.library](../autodocs/dos.library.md#namefromfh)
