---
title: dos.library/PrintFault
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-printfault
functions: [FPuts, Fault, IoErr, Output, SetIoErr]
libraries: [dos.library]
---

# dos.library/PrintFault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PrintFault -- Returns the text associated with a DOS error code (V36)
```
SYNOPSIS

```c
    success = PrintFault(code, header)
    D0                    D1     D2

    BOOL PrintFault(LONG, STRPTR)
```
FUNCTION

```c
    This routine obtains the error message text for the given error code.
    This is similar to the [Fault()](autodocs-2.0/dos-library-fault.md) function, except that the output is
    written to the default output channel with buffered output.
    The value returned by [IoErr()](autodocs-2.0/dos-library-ioerr.md) is set to the code passed in.
```
INPUTS

    code   - Error code
    header - header to output before error text
RESULT

    success - Success/failure code.
SEE ALSO

```c
    [IoErr()](autodocs-2.0/dos-library-ioerr.md), [Fault()](autodocs-2.0/dos-library-fault.md), [SetIoErr()](autodocs-2.0/dos-library-setioerr.md), [Output()](autodocs-2.0/dos-library-output.md), [FPuts()](autodocs-2.0/dos-library-fputs.md)
```

---

## See Also

- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SetIoErr — dos.library](../autodocs/dos.library.md#setioerr)
