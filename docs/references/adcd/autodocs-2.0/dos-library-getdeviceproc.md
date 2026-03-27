---
title: dos.library/GetDeviceProc
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-getdeviceproc
functions: [AssignLate, AssignLock, AssignPath, FreeDeviceProc, GetDeviceProc, IoErr]
libraries: [dos.library]
---

# dos.library/GetDeviceProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDeviceProc -- Finds a handler to send a message to (V36)
```
SYNOPSIS

```c
    devproc = GetDeviceProc(name, devproc)
      D0                     D1     D2

    struct [DevProc](autodocs-2.0/includes-dos-dosextens-h.md) *GetDeviceProc(STRPTR, struct [DevProc](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    Finds the handler/filesystem to send packets regarding 'name' to.
    This may involve getting temporary locks.  It returns a structure
    that includes a lock and msgport to send to to attempt your operation.
    It also includes information on how to handle multiple-directory
    assigns (by passing the [DevProc](autodocs-2.0/includes-dos-dosextens-h.md) back to GetDeviceProc() until it
    returns NULL).

    The initial call to GetDeviceProc() should pass NULL for devproc.  If
    after using the returned [DevProc](autodocs-2.0/includes-dos-dosextens-h.md), you get an ERROR_OBJECT_NOT_FOUND,
    and (devproc->dvp_Flags & DVPF_ASSIGN) is true, you should call
    GetDeviceProc() again, passing it the devproc structure.  It will
    either return a modified devproc structure, or NULL (with
    ERROR_NO_MORE_ENTRIES in IoErr()).  Continue until it returns NULL.

    This call also increments the counter that locks a handler/fs into
    memory.  After calling [FreeDeviceProc()](autodocs-2.0/dos-library-freedeviceproc.md), do not use the port or lock
    again!
```
INPUTS

```c
    name    - name of the object you wish to access.  This can be a
              relative path ("foo/bar"), relative to the current volume
              (":foo/bar"), or relative to a device/volume/assign
              ("foo:bar").
    devproc - A value returned by GetDeviceProc() before, or NULL
```
RESULT

```c
    devproc - a pointer to a [DevProc](autodocs-2.0/includes-dos-dosextens-h.md) structure or NULL
```
BUGS

    Counter not currently active in 2.0.
    In 2.0 and 2.01, you HAD to check DVPF_ASSIGN before calling it again.
    This was fixed for the 2.02 release of V36.
SEE ALSO

```c
    [FreeDeviceProc()](autodocs-2.0/dos-library-freedeviceproc.md), [DeviceProc()](autodocs-2.0/dos-library-deviceproc.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md),
    [AssignPath()](autodocs-2.0/dos-library-assignpath.md)
```

---

## See Also

- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [FreeDeviceProc — dos.library](../autodocs/dos.library.md#freedeviceproc)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
