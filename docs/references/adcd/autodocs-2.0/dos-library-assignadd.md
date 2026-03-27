---
title: dos.library/AssignAdd
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-assignadd
functions: [AssignLate, AssignLock, AssignPath, DupLock, Lock, RemAssignList]
libraries: [dos.library]
---

# dos.library/AssignAdd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AssignAdd -- Adds a lock to an assign for multi-directory assigns (V36)
```
SYNOPSIS

```c
    success = AssignAdd(name,lock)
    D0                   D1   D2

    BOOL AssignAdd(STRPTR,BPTR)
```
FUNCTION

```c
    Adds a lock to an assign, making or adding to a multi-directory
    assign.  Note that this only will succeed on an assign created with
    [AssignLock()](autodocs-2.0/dos-library-assignlock.md), or an assign created with [AssignLate()](autodocs-2.0/dos-library-assignlate.md) which has been
    resolved (converted into a AssignLock()-assign).

    NOTE: you should not use the lock in any way after making this call
    successfully.  It becomes the part of the assign, and will be unlocked
    by the system when the assign is removed.  If you need to keep the
    lock, pass a lock from [DupLock()](autodocs-2.0/dos-library-duplock.md) to [AssignLock()](autodocs-2.0/dos-library-assignlock.md).
```
INPUTS

```c
    name - Name of device to assign lock to (without trailing ':')
    lock - Lock associated with the assigned name
```
RESULT

    success - Success/failure indicator.  On failure, the lock is not
              unlocked.
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md), [AssignPath()](autodocs-2.0/dos-library-assignpath.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md), [DupLock()](autodocs-2.0/dos-library-duplock.md),
    [RemAssignList()](autodocs-2.0/dos-library-remassignlist.md)
```

---

## See Also

- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [RemAssignList — dos.library](../autodocs/dos.library.md#remassignlist)
