---
title: dos.library/Flush
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-flush
functions: [Close, FGetC, UnGetC]
libraries: [dos.library]
---

# dos.library/Flush

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Flush -- Flushes buffers for a buffered filehandle (V36)
```
SYNOPSIS

```c
    success = Flush(fh)
    D0              D1

    LONG Flush(BPTR)
```
FUNCTION

```c
    Flushes any pending buffered writes to the filehandle.  All buffered
    writes will also be flushed on [Close()](autodocs-2.0/dos-library-close.md).  If the filehandle was being
    used for input, it drops the buffer, and tries to [Seek()](autodocs-2.0/dos-library-seek.md) back to the
    last read position  (so subsequent reads or writes will occur at the
    expected position in the file).
```
INPUTS

    fh      - Filehandle to flush.
RESULT

    success - Success or failure.
BUGS

```c
    Before V37 release, Flush() returned a random value.  As of V37,
    it always returns success (this will be fixed in some future
    release).
```
SEE ALSO

```c
    FputC(), [FGetC()](autodocs-2.0/dos-library-fgetc.md), [UnGetC()](autodocs-2.0/dos-library-ungetc.md), [Seek()](autodocs-2.0/dos-library-seek.md), [Close()](autodocs-2.0/dos-library-close.md)
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
