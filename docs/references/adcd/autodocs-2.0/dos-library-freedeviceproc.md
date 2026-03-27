---
title: dos.library/FreeDeviceProc
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-freedeviceproc
functions: [AssignLate, AssignLock, AssignPath, FreeDeviceProc, GetDeviceProc]
libraries: [dos.library]
---

# dos.library/FreeDeviceProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeDeviceProc -- Releases port returned by [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md) (V36)
```
SYNOPSIS

```c
    FreeDeviceProc(devproc)
                     D1

    void FreeDeviceProc(struct [DevProc](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    Frees up the structure created by [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md), and any associated
    temporary locks.

    Decrements the counter incremented by [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md).  The counter
    is in an extension to the 1.3 process structure.  After calling
    FreeDeviceProc(), do not use the port or lock again!  It is safe to
    call FreeDeviceProc(NULL).
```
INPUTS

```c
    devproc - A value returned by [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md)
```
BUGS

    Counter not currently active in 2.0.
SEE ALSO

```c
    [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md), [DeviceProc()](autodocs-2.0/dos-library-deviceproc.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md),
    [AssignPath()](autodocs-2.0/dos-library-assignpath.md)
```

---

## See Also

- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [FreeDeviceProc — dos.library](../autodocs/dos.library.md#freedeviceproc)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
