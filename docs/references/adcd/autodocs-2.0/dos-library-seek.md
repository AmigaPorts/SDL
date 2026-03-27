---
title: dos.library/Seek
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-seek
functions: [IoErr, Read, Write]
libraries: [dos.library]
---

# dos.library/Seek

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Seek -- Set the current position for reading and writing
SYNOPSIS

```c
    oldPosition = Seek( file, position, mode )
    D0                  D1    D2        D3

    LONG Seek(BPTR, LONG, LONG)
```
FUNCTION

```c
    Seek() sets the read/write cursor for the file 'file' to the
    position 'position'. This position is used by both [Read()](autodocs-2.0/dos-library-read.md) and
    [Write()](autodocs-2.0/dos-library-write.md) as a place to start reading or writing. The result is the
    current absolute position in the file, or -1 if an error occurs, in
    which case [IoErr()](autodocs-2.0/dos-library-ioerr.md) can be used to find more information. 'mode' can
    be OFFSET_BEGINNING, OFFSET_CURRENT or OFFSET_END. It is used to
    specify the relative start position. For example, 20 from current
    is a position 20 bytes forward from current, -20 is 20 bytes back
    from current.

    So that to find out where you are, seek zero from current. The end
    of the file is a Seek() positioned by zero from end. You cannot
    Seek() beyond the end of a file.
```
INPUTS

    file - BCPL pointer to a file handle
    position - integer
    mode - integer
RESULTS

    oldPosition - integer
BUGS

```c
    The V36 and V37 ROM filesystem (and V36/V37 l:fastfilesystem)
    returns the current position instead of -1 on an error.  It sets
    [IoErr()](autodocs-2.0/dos-library-ioerr.md) to 0 on success, and an error code on an error.
```
SEE ALSO

```c
    [Read()](autodocs-2.0/dos-library-read.md), [Write()](autodocs-2.0/dos-library-write.md), [SetFileSize()](autodocs-2.0/dos-library-setfilesize.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)
