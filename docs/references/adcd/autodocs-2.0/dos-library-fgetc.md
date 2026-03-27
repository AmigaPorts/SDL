---
title: dos.library/FGetC
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-fgetc
functions: [FGetC, FPutC, UnGetC]
libraries: [dos.library]
---

# dos.library/FGetC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FGetC -- Read a character from the specified input (buffered) (V36)
```
SYNOPSIS

```c
    char = FGetC(fh)
    D0           D1

    LONG FGetC(BPTR)
```
FUNCTION

```c
    Reads the next character from the input stream.  A -1 is
    returned when EOF or an error is encountered.  This call is buffered.
    Use [Flush()](autodocs-2.0/dos-library-flush.md) between buffered and unbuffered I/O on a filehandle.
```
INPUTS

    fh - filehandle to use for buffered I/O
RESULT

```c
    char - character read (0-255) or -1
```
BUGS

```c
    In V36, after an EOF was read, EOF would always be returned from
    FGetC() from then on.  Starting in V37, it tries to read from the
    handler again each time (unless UnGetC(fh,-1) was called).
```
SEE ALSO

```c
    [FPutC()](autodocs-2.0/dos-library-fputc.md), [UnGetC()](autodocs-2.0/dos-library-ungetc.md), [Flush()](autodocs-2.0/dos-library-flush.md)
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
