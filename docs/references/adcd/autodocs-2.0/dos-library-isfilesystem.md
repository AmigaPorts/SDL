---
title: dos.library/IsFileSystem
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-isfilesystem
functions: [IsFileSystem, Lock]
libraries: [dos.library]
---

# dos.library/IsFileSystem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    IsFileSystem -- returns whether a Dos handler is a filesystem (V36)
```
SYNOPSIS

```c
    result = IsFileSystem(name)
    D0                     D1

    BOOL IsFileSystem(STRPTR)
```
FUNCTION

```c
    Returns whether the device is a filesystem or not.  A filesystem
    supports seperate files storing information.  It may also support
    sub-directories, but is not required to.  If the filesystem doesn't
    support this new packet, IsFileSystem() will use Lock(":",...) as
    an indicator.
```
INPUTS

    name   - Name of device in question, with trailing ':'.
RESULT

    result - Flag to indicate if device is a file system
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md)
```

---

## See Also

- [IsFileSystem — dos.library](../autodocs/dos.library.md#isfilesystem)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
