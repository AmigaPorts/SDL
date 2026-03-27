---
title: dos.library/AssignLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-assignlock
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, DupLock, Lock, RemAssignList]
libraries: [dos.library]
---

# dos.library/AssignLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AssignLock -- Creates an assignment to a locked object (V36)
```
SYNOPSIS

```c
    success = AssignLock(name,lock)
    D0                    D1   D2

    BOOL AssignLock(STRPTR,BPTR)
```
FUNCTION

```c
    Sets up an assign of a name to a given lock.  Passing NULL for a lock
    cancels any outstanding assign to that name.  If an assign entry of
    that name is already on the list, this routine replaces that entry.  If
    an entry is on the list that conflicts with the new assign, then a
    failure code is returned.

    NOTE: you should not use the lock in any way after making this call
    successfully.  It becomes the assign, and will be unlocked by the
    system when the assign is removed.  If you need to keep the lock,
    pass a lock from [DupLock()](autodocs-2.0/dos-library-duplock.md) to AssignLock().
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
    [Lock()](autodocs-2.0/dos-library-lock.md), [AssignAdd()](autodocs-2.0/dos-library-assignadd.md), [AssignPath()](autodocs-2.0/dos-library-assignpath.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md), [DupLock()](autodocs-2.0/dos-library-duplock.md),
    [RemAssignList()](autodocs-2.0/dos-library-remassignlist.md)
```

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [RemAssignList — dos.library](../autodocs/dos.library.md#remassignlist)
