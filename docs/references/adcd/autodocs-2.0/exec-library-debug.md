---
title: exec.library/Debug
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-debug
functions: [SetFunction]
libraries: [exec.library]
---

# exec.library/Debug

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Debug -- run the system debugger
SYNOPSIS

```c
    Debug(flags)
          D0

    void Debug(ULONG);
```
FUNCTION

```c
    This function calls the system debugger.  By default this debugger
    is "ROM-WACK".  Other debuggers are encouraged to take over this
    entry point (via [SetFunction()](autodocs-2.0/exec-library-setfunction.md)) so that when an application calls
    Debug(), the alternative debugger will get control.  Currently a
    zero is passed to allow future expansion.
```
NOTE

```c
    The Debug() call may be made when the system is in a questionable
    state; if you have a [SetFunction()](autodocs-2.0/exec-library-setfunction.md) patch, make few assumptions, be
    prepared for [Supervisor](autodocs-2.0/exec-library-supervisor.md) mode, and be aware of differences in the
    Motorola stack frames on the 68000,'10,'20, and '30.
```
SEE ALSO

```c
    [SetFunction](autodocs-2.0/exec-library-setfunction.md)
    your favorite debugger's manual
    the ROM-WACK chapter of the ROM Kernel Manual
```

---

## See Also

- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
