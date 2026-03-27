---
title: 14 / The Icon Library / Icon Library Functions
manual: libraries
chapter: libraries
section: 14-the-icon-library-icon-library-functions
functions: [DeleteDiskObject, FindToolType, FreeDiskObject, GetDefDiskObject, GetDiskObject, GetDiskObjectNew, MatchToolValue, PutDefDiskObject, PutDiskObject]
libraries: [icon.library]
---

# 14 / The Icon Library / Icon Library Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The icon library functions do all the work needed to read, write and
examine an icon's [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file and corresponding [DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md) structure:


struct DiskObject *GetDiskObject(UBYTE *name);
struct DiskObject *GetDiskObjectNew(UBYTE *name);                     (V36)
BOOL               PutDiskObject(UBYTE *name, struct DiskObject *diskobj);
void               FreeDiskObject(struct DiskObject *diskobj);
BOOL               DeleteDiskObject(UBYTE *);                         (V37)

UBYTE             *FindToolType(UBYTE **toolTypeArray, UBYTE *typeName);
BOOL               MatchToolValue(UBYTE *typeString, UBYTE *value);

struct DiskObject *GetDefDiskObjectNew(LONG type);                    (V36)
BOOL               PutDefDiskObject(struct DiskObject *diskobj);      (V36)

UBYTE             *BumpRevision(UBYTE *newbuf, UBYTE *oldname);


The icon library routine [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md) reads an icon's [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file from
disk into a [DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md) structure it creates in memory where it can be
examined or altered.  [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md) writes the DiskObject out to disk
and [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md) frees the memory it used. If you modify any pointers
in a DiskObject acquired via GetDiskObject(), replace the old pointers
before calling FreeDiskObject() so that the proper memory will be freed.

Release 2 includes a new function named [GetDiskObjectNew()](autodocs-2.0/icon-library-getdiskobjectnew.md) that works the
same as [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md), except that if no [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file is found, a default
[DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md) will be created for you.  Also new for Release 2 is
[DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md) for removing .info files from disk, and the functions
[GetDefDiskObject()](autodocs-2.0/icon-library-getdefdiskobject.md) and [PutDefDiskObject()](autodocs-2.0/icon-library-putdefdiskobject.md) which allow the default icons in
ROM to be copied or replaced with new defaults in RAM.

Once an icon's [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file has been read into a [DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md) structure, the
functions [FindToolType()](libraries/14-the-icon-library-the-tool-types-array.md) and [MatchToolValue()](libraries/14-the-icon-library-the-tool-types-array.md) can be used to examine the
icon's Tool Types array.

---

## See Also

- [DeleteDiskObject — icon.library](../autodocs/icon.library.md#deletediskobject)
- [FindToolType — icon.library](../autodocs/icon.library.md#findtooltype)
- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)
- [GetDefDiskObject — icon.library](../autodocs/icon.library.md#getdefdiskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [GetDiskObjectNew — icon.library](../autodocs/icon.library.md#getdiskobjectnew)
- [MatchToolValue — icon.library](../autodocs/icon.library.md#matchtoolvalue)
- [PutDefDiskObject — icon.library](../autodocs/icon.library.md#putdefdiskobject)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
