---
title: debug.lib/KPrintF
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kprintf
functions: [RawDoFmt]
libraries: [exec.library]
---

# debug.lib/KPrintF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    KPrintF - print formatted data to the console
              (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    KPrintF("format string",values)
             A0             A1
```
FUNCTION

```c
    print a formatted C-type string to the console.  See the
    exec [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md) call for the supported % formatting commands.
```
INPUTS

    "format string" - A C style string with % commands to indicate
                      where paramters are to be inserted.
    values - A pointer to an array of paramters, to be inserted into
             specified places in the string.

    KPutFmt and KPrintF are identical assembly interfaces that want the
    two pointers in registers.  _KPrintF and _kprintf are C interfaces
    that expect the format string pointer on the stack, and the
    paramters on the stack above that.
SEE ALSO

```c
    [exec.library/RawDoFmt](autodocs-2.0/exec-library-rawdofmt.md), any C compiler's "printf" call.
```

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
