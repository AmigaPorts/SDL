---
title: icon.library/FreeDiskObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: icon-library-freediskobject
functions: [DeleteDiskObject, FreeFreeList, GetDiskObject, PutDiskObject]
libraries: [icon.library]
---

# icon.library/FreeDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeDiskObject - free all memory in a Workbench disk object.
SYNOPSIS

```c
    FreeDiskObject(diskobj)
                    A0

    void FreeDiskObject(struct [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

```c
    This routine frees all memory in a Workbench disk object, and the
    object itself.  It is implemented via [FreeFreeList()](autodocs-2.0/icon-library-freefreelist.md).

    [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md) takes care of all the initialization required
    to set up the object's free list.  This procedure may ONLY
    be called on a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) allocated via [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md).
```
INPUTS

```c
    diskobj -- a pointer to a [DiskObject](autodocs-2.0/includes-workbench-workbench-h.md) structure
```
RESULTS

    None
SEE ALSO

```c
    [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md), [DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md), [FreeFreeList()](autodocs-2.0/icon-library-freefreelist.md)
```
BUGS

    None

---

## See Also

- [DeleteDiskObject — icon.library](../autodocs/icon.library.md#deletediskobject)
- [FreeFreeList — icon.library](../autodocs/icon.library.md#freefreelist)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
