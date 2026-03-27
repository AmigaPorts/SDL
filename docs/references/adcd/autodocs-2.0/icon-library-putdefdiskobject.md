---
title: icon.library/PutDefDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-putdefdiskobject
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/PutDefDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PutDefDiskObject - write disk object as the default for its type.
                       (V36)
```
SYNOPSIS

```c
    status = PutDefDiskObject(diskobj)
      D0                        A0

    BOOL PutDefDiskObject(struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

```c
    This routine writes out a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) structure, and its
    associated information.  If the call fails, a zero will
    be returned.  The reason for the failure may be obtained
    via [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    Note that this function calls [PutDiskObject](autodocs-2.0/icon-library-putdiskobject.md) internally which means
    that this call (if sucessful) notifies workbench than an icon has
    been created/modified.

    Using this routine protects you from any future changes to
    the way default icons are stored within the system.
```
INPUTS

```c
    diskobj -- a pointer to a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md)
```
RESULTS

    status -- TRUE if the call succeeded else FALSE
SEE ALSO

```c
    [GetDefDiskObject](autodocs-2.0/icon-library-getdefdiskobject.md)
```
BUGS

    None

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
