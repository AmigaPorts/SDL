---
title: dos.library/ReadLink
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-readlink
functions: [GetDeviceProc, Lock, MakeLink, Open]
libraries: [dos.library]
---

# dos.library/ReadLink

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadLink -- Reads the path for a soft filesystem link (V36)
```
SYNOPSIS

```c
    success = ReadLink( port, lock, path, buffer, size)
    D0                   D1    D2    D3     D4     D5

    BOOL ReadLink( struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, BPTR, STRPTR, STRPTR, ULONG)
```
FUNCTION

```c
    ReadLink() takes a lock/name pair (usually from a failed attempt
    to use them to access an object with packets), and asks the
    filesystem to find the softlink and fill buffer with the modified
    path string.  You then start the resolution process again by
    calling [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md) with the new string from ReadLink().

    Soft-links are resolved at access time by a combination of the
    filesystem (by returning ERROR_IS_SOFT_LINK to dos), and by
    Dos (using ReadLink() to resolve any links that are hit).
```
INPUTS

    port - msgport of the filesystem
    lock - lock this path is relative to on the filesystem
    path - path that caused the ERROR_IS_SOFT_LINK
    buffer - pointer to buffer for new path from handler.
    size - size of buffer.
RESULT

    Success - boolean
BUGS

    In V36, soft-links didn't work in the ROM filesystem.  This was
    fixed for V37.
SEE ALSO

```c
    [MakeLink()](autodocs-2.0/dos-library-makelink.md), [Open()](autodocs-2.0/dos-library-open.md), [Lock()](autodocs-2.0/dos-library-lock.md), [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md)
```

---

## See Also

- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [MakeLink — dos.library](../autodocs/dos.library.md#makelink)
- [Open — dos.library](../autodocs/dos.library.md#open)
