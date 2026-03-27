---
title: icon.library/PutDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-putdiskobject
functions: [DeleteDiskObject, FreeDiskObject, GetDiskObject, IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/PutDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PutDiskObject - write out a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) to disk.
```
SYNOPSIS

```c
    status = PutDiskObject(name, diskobj)
      D0                    A0      A1

    BOOL PutDiskObject(char *, struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

```c
    This routine writes out a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) structure, and its
    associated information.  The file name of the info
    file will be the name parameter with a
    ".info" postpended to it.  If the call fails, a zero will
    be returned.  The reason for the failure may be obtained
    via [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    As of release V2.0, PutDiskObject (if sucessful) notifies workbench
    han an icon has been created/modified.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
```
INPUTS

```c
    name -- name of the object (pointer to a character string)
    diskobj -- a pointer to a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md)
```
RESULTS

    status -- TRUE if the call succeeded else FALSE
NOTES

```c
    It is recommended that if you wish to copy an icon from one place
    to another than you use [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md) and PutDiskObject()
    and do not copy them directly.
```
SEE ALSO

```c
    [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md), [DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md)
```
BUGS

    None

---

## See Also

- [DeleteDiskObject — icon.library](../autodocs/icon.library.md#deletediskobject)
- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
