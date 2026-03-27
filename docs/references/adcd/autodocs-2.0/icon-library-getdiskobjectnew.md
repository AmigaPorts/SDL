---
title: icon.library/GetDiskObjectNew
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-getdiskobjectnew
functions: [DeleteDiskObject, FreeDiskObject, GetDiskObject, IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/GetDiskObjectNew

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDiskObjectNew - read in a Workbench disk object from disk.    (V36)
```
SYNOPSIS

```c
    diskobj = GetDiskObjectNew(name)
      D0                      A0

    struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *GetDiskObjectNew(char *);
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

    This call is functionally identical to [GetDiskObject](autodocs-2.0/icon-library-getdiskobject.md) with one
    exception.  If its call to [GetDiskObject](autodocs-2.0/icon-library-getdiskobject.md) fails, this function calls
    [GetDefDiskObject](autodocs-2.0/icon-library-getdefdiskobject.md).  This is useful when there is no .info file for the
    icon you are trying to get a disk object for.  Applications that use
    workbench application windows MUST use this call if they want to
    handle the user dropping an icon (that doesn't have a .info file) on
    their window.  The V2.0 icon editor program is an example of a
    workbench application window that uses this call.
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
    [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md), [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md), [DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md)
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
