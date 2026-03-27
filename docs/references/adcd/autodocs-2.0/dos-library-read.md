---
title: dos.library/Read
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-read
functions: [Close, FGetC, Open, Read, Write]
libraries: [dos.library]
---

# dos.library/Read

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Read -- Read bytes of data from a file
SYNOPSIS

```c
    actualLength = Read( file, buffer, length )
    D0                   D1    D2      D3

    LONG Read(BPTR, void *, LONG)
```
FUNCTION

```c
    Data can be copied using a combination of Read() and [Write()](autodocs-2.0/dos-library-write.md).
    Read() reads bytes of information from an opened file (represented
    here by the argument 'file') into the buffer given. The argument
    'length' is the length of the buffer given.

    The value returned is the length of the information actually read.
    So, when 'actualLength' is greater than zero, the value of
    'actualLength' is the the number of characters read. Usually Read
    will try to fill up your buffer before returning. A value of zero
    means that end-of-file has been reached. Errors are indicated by a
    value of -1.

    Note: this is an unbuffered routine (the request is passed directly
    to the filesystem.)  Buffered I/O is more efficient for small
    reads and writes; see [FGetC()](autodocs-2.0/dos-library-fgetc.md).
```
INPUTS

    file - BCPL pointer to a file handle
    buffer - pointer to buffer
    length - integer
RESULTS

    actualLength - integer
SEE ALSO

```c
    [Open()](autodocs-2.0/dos-library-open.md), [Close()](autodocs-2.0/dos-library-close.md), [Write()](autodocs-2.0/dos-library-write.md), [Seek()](autodocs-2.0/dos-library-seek.md), [FGetC()](autodocs-2.0/dos-library-fgetc.md)
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)
