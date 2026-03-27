---
title: dos.library/RemAssignList
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-remassignlist
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, DupLock, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/RemAssignList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemAssignList -- Remove an entry from a multi-dir assign (V36)
```
SYNOPSIS

```c
    success = RemAssignList(name,lock)
    D0                       D1   D2

    BOOL RemAssignList(STRPTR,BPTR)
```
FUNCTION

```c
    Removes an entry from a multi-directory assign.  The entry removed is
    the first one for which [SameLock](autodocs-2.0/dos-library-samelock.md) with 'lock' returns that they are on
    the same object.  The lock for the entry in the list is unlocked (not
    the entry passed in).
```
INPUTS

```c
    name - Name of device to remove lock from (without trailing ':')
    lock - Lock associated with the object to remove from the list
```
RESULT

    success - Success/failure indicator.
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md), [AssignPath()](autodocs-2.0/dos-library-assignpath.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md), [DupLock()](autodocs-2.0/dos-library-duplock.md),
    [AssignAdd()](autodocs-2.0/dos-library-assignadd.md), [UnLock()](autodocs-2.0/dos-library-unlock.md)
```

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
