---
title: dos.library/SetVBuf
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setvbuf
functions: [FGetC, FGets, FPuts, FRead, FWrite, UnGetC]
libraries: [dos.library]
---

# dos.library/SetVBuf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetVBuf -- set buffering modes and size (V36)
```
SYNOPSIS

```c
    error = SetVBuf(fh, buff, type, size)
    D0              D1   D2    D3    D4

    LONG SetVBuf(BPTR, STRPTR, LONG, LONG)
```
FUNCTION

```c
    Changes the buffering modes and buffer size for a filehandle.
    With buff == NULL, the current buffer will be deallocated and a
    new one of (approximately) size will be allocated.  If buffer is
    non-NULL, it will be used for buffering and must be at least
    max(size,208) bytes long.  If buff is NULL and size is -1,
    then only the buffering mode will be changed.
```
INPUTS

```c
    fh   - Filehandle
    buff - buffer pointer for buffered I/O
    type - buffering mode (see [<dos/stdio.h>](autodocs-2.0/includes-dos-stdio-h.md))
    size - size of buffer for buffered I/O (sizes less than 208 bytes
           will be ignored).
```
RESULT

    error - 0 if successful.  NOTE: opposite of most dos functions!
BUGS

    Not implemented yet, always returns 0.
SEE ALSO

```c
    FputC(), [FGetC()](autodocs-2.0/dos-library-fgetc.md), [UnGetC()](autodocs-2.0/dos-library-ungetc.md), [Flush()](autodocs-2.0/dos-library-flush.md), [FRead()](autodocs-2.0/dos-library-fread.md), [FWrite()](autodocs-2.0/dos-library-fwrite.md), [FGets()](autodocs-2.0/dos-library-fgets.md),
    [FPuts()](autodocs-2.0/dos-library-fputs.md).
```

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FRead — dos.library](../autodocs/dos.library.md#fread)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
