---
title: dos.library/Write
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-write
functions: [Close, FPutC, Open, Read, Write]
libraries: [dos.library]
---

# dos.library/Write

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Write -- Write bytes of data to a file
SYNOPSIS

```c
    returnedLength =  Write( file, buffer, length )
    D0                       D1    D2      D3

    LONG Write (BPTR, void *, LONG)
```
FUNCTION

```c
    Write() writes bytes of data to the opened file 'file'. 'length'
    indicates the length of data to be transferred; 'buffer' is a
    pointer to the buffer. The value returned is the length of
    information actually written. So, when 'length' is greater than
    zero, the value of 'length' is the number of characters written.
    Errors are indicated by a value of -1.

    Note: this is an unbuffered routine (the request is passed directly
    to the filesystem.)  Buffered I/O is more efficient for small
    reads and writes; see [FPutC()](autodocs-2.0/dos-library-fputc.md).
```
INPUTS

    file - BCPL pointer to a file handle
    buffer - pointer to the buffer
    length - integer
RESULTS

    returnedLength - integer
SEE ALSO

```c
    [Read()](autodocs-2.0/dos-library-read.md), [Seek()](autodocs-2.0/dos-library-seek.md), [Open()](autodocs-2.0/dos-library-open.md), [Close()](autodocs-2.0/dos-library-close.md), [FPutC](autodocs-2.0/dos-library-fputc.md)
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)
