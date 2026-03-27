---
title: dos.library/AddBuffers
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-addbuffers
functions: [IoErr]
libraries: [dos.library]
---

# dos.library/AddBuffers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddBuffers -- Changes the number of buffers for a filesystem (V36)
```
SYNOPSIS

```c
    success = AddBuffers(filesystem, number)
    D0                     D1          D2

    BOOL AddBuffers(STRPTR, LONG)
```
FUNCTION

```c
    Adds buffers to a filesystem.  If it succeeds, the number of current
    buffers is returned in [IoErr()](autodocs-2.0/dos-library-ioerr.md).  Note that "number" may be negative.
    The amount of memory used per buffer, and any limits on the number of
    buffers, are dependant on the filesystem in question.
    If the call succeeds, the number of buffers in use on the filesystem
    will be returned by [IoErr()](autodocs-2.0/dos-library-ioerr.md).
```
INPUTS

```c
    filesystem - Name of device to add buffers to (with ':').
    number     - Number of buffers to add.  May be negative.
```
RESULT

    success    - Success or failure of command.
BUGS

```c
    The V36 ROM filesystem (FFS/OFS) doesn't return the right number of
    buffers unless preceded by an AddBuffers(fs,-1) (in-use buffers aren't
    counted).  This is fixed in V37.

    The V37 and before ROM filesystem doesn't return success, it returns
    the number of buffers.  The best way to test for this is to consider
    0 (FALSE) failure, -1 (DOSTRUE) to mean that [IoErr()](autodocs-2.0/dos-library-ioerr.md) will have the
    number of buffers, and any other positive value to be the number of
    buffers.  It may be fixed in some future ROM revision.
```
SEE ALSO

```c
    [IoErr()](autodocs-2.0/dos-library-ioerr.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
