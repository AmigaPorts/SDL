---
title: dos.library/FRead
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-fread
functions: [FGetC, FGets, FWrite, IoErr]
libraries: [dos.library]
---

# dos.library/FRead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FRead -- Reads a number of blocks from an input (buffered) (V36)
```
SYNOPSIS

```c
    count = FRead(fh, buf, blocklen, blocks)
    D0            D1  D2     D3        D4

    LONG FRead(BPTR, STRPTR, ULONG, ULONG)
```
FUNCTION

    Attempts to read a number of blocks, each blocklen long, into the
    specified buffer from the input stream.  May return less than
    the number of blocks requested, either due to EOF or read errors.
    This call is buffered.
INPUTS

    fh       - filehandle to use for buffered I/O
    buf      - Area to read bytes into.
    blocklen - number of bytes per block.  Must be > 0.
    blocks   - number of blocks to read.  Must be > 0.
RESULT

    count - Number of _blocks_ read, or 0 for EOF.  On an error, the
            number of blocks actually read is returned.
BUGS

```c
    Doesn't clear [IoErr()](autodocs-2.0/dos-library-ioerr.md) before starting.  If you want to find out
    about errors, use SetIoErr(0L) before calling.
```
SEE ALSO

```c
    [FGetC()](autodocs-2.0/dos-library-fgetc.md), [FWrite()](autodocs-2.0/dos-library-fwrite.md), [FGets()](autodocs-2.0/dos-library-fgets.md)
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
