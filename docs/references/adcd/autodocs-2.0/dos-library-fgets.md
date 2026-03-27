---
title: dos.library/FGets
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-fgets
functions: [FGetC, FPuts, FRead, IoErr]
libraries: [dos.library]
---

# dos.library/FGets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FGets -- Reads a line from the specified input (buffered) (V36)
```
SYNOPSIS

```c
    buffer = FGets(fh, buf, len)
    D0             D1  D2   D3

    STRPTR FGets(BPTR, STRPTR, ULONG)
```
FUNCTION

    This routine reads in a single line from the specified input stopping
    at a NEWLINE character or EOF.  In either event, UP TO the number of
    len specified bytes minus 1 will be copied into the buffer.  Hence if
    a length of 50 is passed and the input line is longer than 49 bytes,
    it will return 49 characters.  It returns the buffer pointer normally,
    or NULL if EOF is the first thing read.

    If terminated by a newline, the newline WILL be the last character in
    the buffer.  This is a buffered read routine.  The string read in IS
    null-terminated.
INPUTS

    fh  - filehandle to use for buffered I/O
    buf - Area to read bytes into.
    len - Number of bytes to read, must be > 0.
RESULT

```c
    buffer - Pointer to buffer passed in, or NULL for immediate EOF or for
             an error.  If NULL is returnd for an EOF, [IoErr()](autodocs-2.0/dos-library-ioerr.md) will return
             0.
```
SEE ALSO

```c
    [FRead()](autodocs-2.0/dos-library-fread.md), [FPuts()](autodocs-2.0/dos-library-fputs.md), [FGetC()](autodocs-2.0/dos-library-fgetc.md)
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FRead — dos.library](../autodocs/dos.library.md#fread)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
