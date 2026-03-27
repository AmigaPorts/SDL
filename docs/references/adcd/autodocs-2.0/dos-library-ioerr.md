---
title: dos.library/IoErr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-ioerr
functions: [Fault, IoErr, PrintFault, SetIoErr]
libraries: [dos.library]
---

# dos.library/IoErr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IoErr -- Return extra information from the system
SYNOPSIS

```c
    error = IoErr()
      D0

    LONG IoErr(void)
```
FUNCTION

```c
    Most I/O routines return zero to indicate an error. When this
    happens (or whatever the defined error return for the routine)
    this routine may be called to determine more information. It is
    also used in some routines to pass back a secondary result.

    Note: there is no guarantee as to the value returned from IoErr()
    after a successful operation, unless to specified by the routine.
```
RESULTS

    error - integer
SEE ALSO

```c
    [Fault()](autodocs-2.0/dos-library-fault.md), [PrintFault()](autodocs-2.0/dos-library-printfault.md), [SetIoErr()](autodocs-2.0/dos-library-setioerr.md)
```

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PrintFault — dos.library](../autodocs/dos.library.md#printfault)
- [SetIoErr — dos.library](../autodocs/dos.library.md#setioerr)
