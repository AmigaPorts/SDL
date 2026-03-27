---
title: dos.library/DeviceProc
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-deviceproc
functions: [AssignPath, DupLock, FreeDeviceProc, GetDeviceProc, IoErr, UnLock]
libraries: [dos.library]
---

# dos.library/DeviceProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeviceProc -- Return the process [MsgPort](autodocs-2.0/includes-exec-ports-h.md) of specific I/O handler
```
SYNOPSIS

```c
    process = DeviceProc( name )
    D0                    D1

    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *DeviceProc (STRPTR)
```
FUNCTION

```c
    DeviceProc() returns the process identifier of the process which
    handles the device associated with the specified name. If no
    process handler can be found then the result is zero. If the name
    refers to an assign then a directory lock is returned in [IoErr()](autodocs-2.0/dos-library-ioerr.md).
    This lock should not be UnLock()ed or Examine()ed (if you wish to do
    so, [DupLock()](autodocs-2.0/dos-library-duplock.md) it first).
```
BUGS

```c
    In V36, if you try to DeviceProc() something relative to an assign
    made with [AssignPath()](autodocs-2.0/dos-library-assignpath.md), it will fail.  This is because there's no
    way to know when to unlock the lock.  If you're writing code for
    V36 or later, it is highly advised you use [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md) instead,
    or make your code conditional on V36 to use GetDeviceProc()/
    [FreeDeviceProc()](autodocs-2.0/dos-library-freedeviceproc.md).
```
SEE ALSO

```c
    [GetDeviceProc()](autodocs-2.0/dos-library-getdeviceproc.md), [FreeDeviceProc()](autodocs-2.0/dos-library-freedeviceproc.md), [DupLock()](autodocs-2.0/dos-library-duplock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [Examine()](autodocs-2.0/dos-library-examine.md)
```

---

## See Also

- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [FreeDeviceProc — dos.library](../autodocs/dos.library.md#freedeviceproc)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
