---
title: dos.library/VPrintf
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-vprintf
functions: [FPutC, IoErr, Output, Printf, RawDoFmt, VFPrintf]
libraries: [dos.library, exec.library]
---

# dos.library/VPrintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    VPrintf -- format and print string (buffered) (V36)
```
SYNOPSIS

```c
    count = VPrintf(fmt, argv)
      D0            D1   D2

    LONG VPrintf(STRPTR, LONG *)

    count = Printf(fmt, ...)

    LONG Printf(STRPTR, ...)
```
FUNCTION

```c
    Writes the formatted string and values to [Output()](autodocs-2.0/dos-library-output.md).  This routine is
    assumed to handle all internal buffering so that the formatting string
    and resultant formatted values can be arbitrarily long.  Any secondary
    error code is returned in [IoErr()](autodocs-2.0/dos-library-ioerr.md).  This routine is buffered.

    Note: [RawDoFmt](autodocs-2.0/exec-library-rawdofmt.md) assumes 16 bit ints, so you will usually need 'l's in
    your formats (ex: %ld versus %d).
```
INPUTS

```c
    fmt   - exec.library [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md) style formatting string
    argv  - Pointer to array of formatting values
```
RESULT

```c
    count - Number of bytes written or -1 (EOF) for an error
```
BUGS

```c
    The prototype for Printf() currently forces you to cast the first
    varargs parameter to LONG due to a deficiency in the program
    that generates fds, prototypes, and amiga.lib stubs.
```
SEE ALSO

```c
    [VFPrintf()](autodocs-2.0/dos-library-vfprintf.md), [VFWritef()](autodocs-2.0/dos-library-vfwritef.md), [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md), [FPutC()](autodocs-2.0/dos-library-fputc.md)
```

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [Printf — dos.library](../autodocs/dos.library.md#printf)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [VFPrintf — dos.library](../autodocs/dos.library.md#vfprintf)
