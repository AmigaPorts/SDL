---
title: icon.library/GetDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-getdiskobject
functions: [DeleteDiskObject, FreeDiskObject, GetDiskObjectNew, IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/GetDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetDiskObject - read in a Workbench disk object from disk.
SYNOPSIS

```c
    diskobj = GetDiskObject(name)
      D0                      A0

    struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *GetDiskObject(char *);
```
FUNCTION

```c
    This routine reads in a Workbench disk object in from disk.  The
    name parameter will have a ".info" postpended to it, and the
    info file of that name will be read.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    Using this routine protects you from any future changes to
    the way icons are stored within the system.

    A [FreeList](autodocs-2.0/includes-workbench-workbench-h.md) structure is allocated just after the [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md)
    structure; [FreeDiskObject](autodocs-2.0/icon-library-freediskobject.md) makes use of this to get rid of the
    memory that was allocated.
```
INPUTS

```c
    name -- name of the object (char *) or NULL if you just want a
            [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) structure allocated for you (useful when
            calling AddAppIcon in workbench.library).
```
RESULTS

    diskobj -- the Workbench disk object in question
SEE ALSO

```c
    [GetDiskObjectNew()](autodocs-2.0/icon-library-getdiskobjectnew.md), [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md), [DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md),
    [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md)
```
BUGS

    None

---

## See Also

- [DeleteDiskObject — icon.library](../autodocs/icon.library.md#deletediskobject)
- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)
- [GetDiskObjectNew — icon.library](../autodocs/icon.library.md#getdiskobjectnew)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
