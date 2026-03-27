---
title: dos.library/AssignPath
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-assignpath
functions: [AssignAdd, AssignLate, AssignLock, AssignPath, Open]
libraries: [dos.library]
---

# dos.library/AssignPath

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AssignPath -- Creates an assignment to a specified path (V36)
```
SYNOPSIS

```c
    success = AssignPath(name,path)
    D0                    D1   D2

    BOOL AssignPath(STRPTR,STRPTR)
```
FUNCTION

```c
    Sets up a assignment that is expanded upon EACH reference to the name.
    This is implemented through a new device list type (DLT_ASSIGNPATH, or
    some such).  The path (a string) would be attached to the node.  When
    the name is referenced (Open("FOO:xyzzy"...), the string will be used
    to determine where to do the open.  No permanent lock will be part of
    it.  For example, you could AssignPath() c2: to df2:c, and references
    to c2: would go to df2:c, even if you change disks.

    The other major advantage is assigning things to unmounted volumes,
    which will be requested upon access (useful in startup sequences).
```
INPUTS

```c
    name - Name of device to be assigned (without trailing ':')
    path - Name of late assignment to be resolved at each reference
```
RESULT

    success - Success/failure indicator of the operation
SEE ALSO

```c
    [AssignAdd()](autodocs-2.0/dos-library-assignadd.md), [AssignLock()](autodocs-2.0/dos-library-assignlock.md), [AssignLate()](autodocs-2.0/dos-library-assignlate.md), [Open()](autodocs-2.0/dos-library-open.md)
```

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [Open — dos.library](../autodocs/dos.library.md#open)
