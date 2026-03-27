---
title: 14 Workbench and Icon Library / Function Reference
manual: libraries
chapter: libraries
section: 14-workbench-and-icon-library-function-reference
functions: [AddFreeList, BumpRevision, DeleteDiskObject, FindToolType, FreeDiskObject, FreeFreeList, GetDefDiskObject, GetDiskObject, GetDiskObjectNew, MatchToolValue, PutDefDiskObject, PutDiskObject, RemoveAppIcon, RemoveAppMenuItem, RemoveAppWindow]
libraries: [icon.library, workbench.library]
---

# 14 Workbench and Icon Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the functions in workbench.library
and icon.library.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details on each function call.


                    Table 14-3: Icon Library Functions
  _______________________________________________________________________
 |                                                                       |
 |         Function                  Description                         |
 |=======================================================================|
 |      [GetDiskObject()](autodocs-2.0/icon-library-getdiskobject.md)  Read the [.info](libraries/14-workbench-and-icon-library-the-info-file.md) file of an icon into a           |
 |                       [DiskObject](libraries/14-icon-library-data-structures-the-diskobject-structure.md) structure                            |
 |   [GetDiskObjectNew()](autodocs-2.0/icon-library-getdiskobjectnew.md)  Same as GetDiskObject() but returns a default   |
 |                       icon if none exists                             |
 |      [PutDiskObject()](autodocs-2.0/icon-library-putdiskobject.md)  Write a DiskObject structure to disk as a       |
 |                       .info file                                      |
 |     [FreeDiskObject()](autodocs-2.0/icon-library-freediskobject.md)  Free the DiskObject structure created by        |
 |                       GetDiskObject()                                 |
 |   [DeleteDiskObject()](autodocs-2.0/icon-library-deletediskobject.md)  Deletes a given .info file from disk            |
 |-----------------------------------------------------------------------|
 |       [FindToolType()](autodocs-2.0/icon-library-findtooltype.md)  Return the value of an entry in the icon's Tool |
 |                       Type array                                      |
 |     [MatchToolValue()](autodocs-2.0/icon-library-matchtoolvalue.md)  Check a Tool Type entry against a given value   |
 |-----------------------------------------------------------------------|
 |   [GetDefDiskObject()](autodocs-2.0/icon-library-getdefdiskobject.md)  Read the default icon for a given icon type     |
 |   [PutDefDiskObject()](autodocs-2.0/icon-library-putdefdiskobject.md)  Replace the default icon for a given icon type  |
 |                       (V36)                                           |
 |-----------------------------------------------------------------------|
 |        [AddFreeList()](autodocs-2.0/icon-library-addfreelist.md)  Add memory you have allocated to a FreeList     |
 |       [FreeFreeList()](autodocs-2.0/icon-library-freefreelist.md)  Free all the memory for entries in the FreeList |
 |       [BumpRevision()](autodocs-2.0/icon-library-bumprevision.md)  Create a new name for a second copy of a        |
 |                       Workbench object                                |
 |_______________________________________________________________________|


                 Table 14-4: Workbench Library Functions
  _______________________________________________________________________
 |                                                                       |
 |         Function                  Description                         |
 |=======================================================================|
 |         [AddAppIcon()](autodocs-2.0/workbench-library-addappicona.md)  Add an AppIcon to Workbench                     |
 |     [AddAppMenuItem()](autodocs-2.0/workbench-library-addappmenuitema.md)  Add an AppMenuItem to the Workbench Tools menu  |
 |       [AddAppWindow()](autodocs-2.0/workbench-library-addappwindowa.md)  Add an AppWindow to Workbench                   |
 |-----------------------------------------------------------------------|
 |      [RemoveAppIcon()](autodocs-2.0/workbench-library-removeappicon.md)  Remove an AppIcon to Workbench                  |
 |  [RemoveAppMenuItem()](autodocs-2.0/workbench-library-removeappmenuitem.md)  Remove an AppMenuItem to the Workbench Tools    |
 |                       menu                                            |
 |    [RemoveAppWindow()](autodocs-2.0/workbench-library-removeappwindow.md)  Remove an AppWindow to Workbench                |
 |_______________________________________________________________________|

---

## See Also

- [AddFreeList — icon.library](../autodocs/icon.library.md#addfreelist)
- [BumpRevision — icon.library](../autodocs/icon.library.md#bumprevision)
- [DeleteDiskObject — icon.library](../autodocs/icon.library.md#deletediskobject)
- [FindToolType — icon.library](../autodocs/icon.library.md#findtooltype)
- [FreeDiskObject — icon.library](../autodocs/icon.library.md#freediskobject)
- [FreeFreeList — icon.library](../autodocs/icon.library.md#freefreelist)
- [GetDefDiskObject — icon.library](../autodocs/icon.library.md#getdefdiskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [GetDiskObjectNew — icon.library](../autodocs/icon.library.md#getdiskobjectnew)
- [MatchToolValue — icon.library](../autodocs/icon.library.md#matchtoolvalue)
- [PutDefDiskObject — icon.library](../autodocs/icon.library.md#putdefdiskobject)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
- [RemoveAppIcon — workbench.library](../autodocs/workbench.library.md#removeappicon)
- [RemoveAppMenuItem — workbench.library](../autodocs/workbench.library.md#removeappmenuitem)
- [RemoveAppWindow — workbench.library](../autodocs/workbench.library.md#removeappwindow)
