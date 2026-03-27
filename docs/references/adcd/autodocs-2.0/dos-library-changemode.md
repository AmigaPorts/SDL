---
title: dos.library/ChangeMode
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-changemode
functions: [Lock, Open]
libraries: [dos.library]
---

# dos.library/ChangeMode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ChangeMode - Change the current mode of a lock or filehandle (V36)
```
SYNOPSIS

```c
    success = ChangeMode(type, object, newmode)
    D0                    D1     D2      D3

    BOOL ChangeMode(ULONG, BPTR, ULONG)
```
FUNCTION

    This allows you to attempt to change the mode in use by a lock or
    filehandle.  For example, you could attempt to turn a shared lock
    into an exclusive lock.  The handler may well reject this request.
    Warning: if you use the wrong type for the object, the system may
    crash.
INPUTS

    type    - Either CHANGE_FH or CHANGE_LOCK
    object  - A lock or filehandle
    newmode - The new mode you want
RESULT

    success - Boolean
BUGS

```c
    Did not work in 2.02 or before (V36).  Works in V37.  In the
    earlier versions, it can crash the machine.
```
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
