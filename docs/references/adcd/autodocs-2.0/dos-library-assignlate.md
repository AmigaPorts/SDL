---
title: dos.library/AssignLate
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-assignlate
functions: [AssignAdd, AssignLock, AssignPath, Lock]
libraries: [dos.library]
---

# dos.library/AssignLate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AssignLate -- Creates an assignment to a specified path later (V36)
```
SYNOPSIS

```c
    success = AssignLate(name,path)
    D0                    D1   D2

    BOOL AssignLate(STRPTR,STRPTR)
```
FUNCTION

```c
    Sets up a assignment that is expanded upon the FIRST reference to the
    name.  The path (a string) would be attached to the node.  When
    the name is referenced (Open("FOO:xyzzy"...), the string will be used
    to determine where to set the assign to, and if the directory can be
    locked, the assign will act from that point on as if it had been
    created by [AssignLock()](autodocs-2.0/dos-library-assignlock.md).

    A major advantage is assigning things to unmounted volumes, which
    will be requested upon access (useful in startup sequences).
```
INPUTS

```c
    name - Name of device to be assigned (without trailing ':')
    path - Name of late assignment to be resolved on the first reference.
```
RESULT

    success - Success/failure indicator of the operation
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [AssignAdd()](autodocs-2.0/dos-library-assignadd.md), [AssignPath()](autodocs-2.0/dos-library-assignpath.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md),
```

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
