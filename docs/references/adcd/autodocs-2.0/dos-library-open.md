---
title: dos.library/Open
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-open
functions: [ChangeMode, Close, IoErr, NameFromFH, ParentOfFH]
libraries: [dos.library]
---

# dos.library/Open

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Open -- Open a file for input or output
SYNOPSIS

```c
    file = Open( name, accessMode )
    D0           D1    D2

    BPTR Open(STRPTR, LONG)
```
FUNCTION

```c
    The named file is opened and a file handle returned.  If the
    accessMode is MODE_OLDFILE, an existing file is opened for reading
    or writing. If the value is MODE_NEWFILE, a new file is created for
    writing. MODE_READWRITE opens a file with an shared lock, but
    creates it if it didn't exist.  Open types are documented in the
    [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md) or [<libraries/dos.h>](autodocs-2.0/includes-libraries-dos-h.md) include file.

    The 'name' can be a filename (optionally prefaced by a device
    name), a simple device such as NIL:, a window specification such as
    CON: or RAW: followed by window parameters, or "*", representing the
    current window.  Note that as of V36, "*" is obsolete, and CONSOLE:
    should be used instead.

    If the file cannot be opened for any reason, the value returned
    will be zero, and a secondary error code will be available by
    calling the routine [IoErr()](autodocs-2.0/dos-library-ioerr.md).
```
INPUTS

    name       - pointer to a null-terminated string
    accessMode - integer
RESULTS

    file - BCPL pointer to a file handle
SEE ALSO

```c
    [Close()](autodocs-2.0/dos-library-close.md), [ChangeMode()](autodocs-2.0/dos-library-changemode.md), [NameFromFH()](autodocs-2.0/dos-library-namefromfh.md), [ParentOfFH()](autodocs-2.0/dos-library-parentoffh.md), [ExamineFH()](autodocs-2.0/dos-library-examinefh.md)
```

---

## See Also

- [ChangeMode — dos.library](../autodocs/dos.library.md#changemode)
- [Close — dos.library](../autodocs/dos.library.md#close)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [NameFromFH — dos.library](../autodocs/dos.library.md#namefromfh)
- [ParentOfFH — dos.library](../autodocs/dos.library.md#parentoffh)
