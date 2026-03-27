---
title: dos.library/SetIoErr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-setioerr
functions: [Fault, IoErr, PrintFault]
libraries: [dos.library]
---

# dos.library/SetIoErr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetIoErr -- Sets the value returned by [IoErr()](autodocs-2.0/dos-library-ioerr.md) (V36)
```
SYNOPSIS

```c
    oldcode = SetIoErr(code)
    D0                  D1

    LONG SetIoErr(LONG);
```
FUNCTION

```c
    This routine sets up the secondary result (pr_Result2) return code
    (returned by the [IoErr()](autodocs-2.0/dos-library-ioerr.md) function).
```
INPUTS

```c
    code - Code to be returned by a call to [IoErr](autodocs-2.0/dos-library-ioerr.md).
```
RESULT

    oldcode - The previous error code.
SEE ALSO

```c
    [IoErr()](autodocs-2.0/dos-library-ioerr.md), [Fault()](autodocs-2.0/dos-library-fault.md), [PrintFault()](autodocs-2.0/dos-library-printfault.md)
```

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PrintFault — dos.library](../autodocs/dos.library.md#printfault)
