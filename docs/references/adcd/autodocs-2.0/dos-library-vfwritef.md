---
title: dos.library/VFWritef
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-vfwritef
functions: [FPutC, VFPrintf]
libraries: [dos.library]
---

# dos.library/VFWritef

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    VFWritef - write a BCPL formatted string to a file (buffered) (V36)
```
SYNOPSIS

```c
    count = VFWritef(fh, fmt, argv)
    D0               D1  D2    D3

    LONG VFWritef(BPTR, STRPTR, LONG *)

    count = FWritef(fh, fmt, ...)

    LONG FWritef(BPTR, STRPTR, ...)
```
FUNCTION

```c
    Writes the formatted string and values to the default output.  This
    routine is assumed to handle all internal buffering so that the
    formatting string and resultant formatted values can be arbitrarily
    long.  The formats are in BCPL form.  This routine is buffered.

    Supported formats are:  (Note x is in base 36!)
            %S  - string (CSTR)
            %Tx - writes a left-justified string in a field at least
                  x bytes long.
            %C  - writes a single character
            %Ox - writes a number in octal, maximum x characters wide
            %Xx - writes a number in hex, maximum x characters wide
            %Ix - writes a number in decimal, maximum x characters wide
            %N  - writes a number in decimal, any length
            %Ux - writes an unsigned number, maximum x characters wide
            %$  - ignore parameter

    Note: 'x' above is actually the character value - '0'.
```
INPUTS

    fmt   - BCPL style formatting string
    argv  - Pointer to array of formatting values
RESULT

    count - Number of bytes written or -1 for error
BUGS

```c
    As of V37, VFWritef() does NOT return a valid return value.  In
    order to reduce possible errors, the prototypes supplied for the
    system as of V37 have it typed as VOID.
```
SEE ALSO

```c
    [VFPrintf()](autodocs-2.0/dos-library-vfprintf.md), [VFPrintf()](autodocs-2.0/dos-library-vfprintf.md), [FPutC()](autodocs-2.0/dos-library-fputc.md)
```

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [VFPrintf — dos.library](../autodocs/dos.library.md#vfprintf)
