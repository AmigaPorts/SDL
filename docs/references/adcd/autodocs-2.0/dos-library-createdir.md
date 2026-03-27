---
title: dos.library/CreateDir
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-createdir
functions: [Lock, UnLock]
libraries: [dos.library]
---

# dos.library/CreateDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CreateDir -- Create a new directory
SYNOPSIS

```c
    lock = CreateDir( name )
    D0                D1

    BPTR CreateDir(STRPTR)
```
FUNCTION

    CreateDir creates a new directory with the specified name. An error
    is returned if it fails.  Directories can only be created on
    devices which support them, e.g. disks.  CreateDir returns an
    exclusive lock on the new directory if it succeeds.
INPUTS

    name - pointer to a null-terminated string
RESULTS

    lock - BCPL pointer to a lock or NULL for failure.
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md)
```

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
