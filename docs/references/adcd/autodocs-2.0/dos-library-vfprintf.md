---
title: dos.library/VFPrintf
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-vfprintf
functions: [FPrintf, FPutC, IoErr, RawDoFmt, VPrintf]
libraries: [dos.library, exec.library]
---

# dos.library/VFPrintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    VFPrintf -- format and print a string to a file (buffered) (V36)
```
SYNOPSIS

```c
    count = VFPrintf(fh, fmt, argv)
    D0               D1  D2    D3

    LONG VFPrintf(BPTR, STRPTR, LONG *)

    count = FPrintf(fh, fmt, ...)

    LONG FPrintf(BPTR, STRPTR, ...)
```
FUNCTION

```c
    Writes the formatted string and values to the given file.  This
    routine is assumed to handle all internal buffering so that the
    formatting string and resultant formatted values can be arbitrarily
    long.  Any secondary error code is returned in [IoErr()](autodocs-2.0/dos-library-ioerr.md).  This routine
    is buffered.
```
INPUTS

```c
    fh    - Filehandle to write to
    fmt   - [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md) style formatting string
    argv  - Pointer to array of formatting values
```
RESULT

```c
    count - Number of bytes written or -1 (EOF) for an error
```
BUGS

```c
    The prototype for FPrintf() currently forces you to cast the first
    varargs parameter to LONG due to a deficiency in the program
    that generates fds, prototypes, and amiga.lib stubs.
```
SEE ALSO

```c
    [VPrintf()](autodocs-2.0/dos-library-vprintf.md), [VFWritef()](autodocs-2.0/dos-library-vfwritef.md), [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md), [FPutC()](autodocs-2.0/dos-library-fputc.md)
```

---

## See Also

- [FPrintf — dos.library](../autodocs/dos.library.md#fprintf)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [VPrintf — dos.library](../autodocs/dos.library.md#vprintf)
