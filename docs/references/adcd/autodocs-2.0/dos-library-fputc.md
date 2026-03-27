---
title: dos.library/FPutC
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-fputc
functions: [FGetC, UnGetC]
libraries: [dos.library]
---

# dos.library/FPutC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FPutC -- Write a character to the specified output (buffered) (V36)
```
SYNOPSIS

```c
    char = FPutC(fh, char)
    D0           D1   D2

    LONG FPutC(BPTR, UBYTE)
```
FUNCTION

```c
    Writes a single character to the output stream.  This call is
    buffered.  Use [Flush()](autodocs-2.0/dos-library-flush.md) between buffered and unbuffered I/O on a
    filehandle.  Interactive filehandles are flushed automatically
    on a newline, return, '0', or line feed.
```
INPUTS

    fh   - filehandle to use for buffered I/O
    char - character to write
RESULT

    char - either the character written, or EOF for an error.
SEE ALSO

```c
    [FGetC()](autodocs-2.0/dos-library-fgetc.md), [UnGetC()](autodocs-2.0/dos-library-ungetc.md), [Flush()](autodocs-2.0/dos-library-flush.md)
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
