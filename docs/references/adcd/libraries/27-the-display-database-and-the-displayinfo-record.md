---
title: 27 / / / The Display Database and the DisplayInfo Record
manual: libraries
chapter: libraries
section: 27-the-display-database-and-the-displayinfo-record
functions: [FindDisplayInfo, GetDisplayInfoData, GetVPModeID, VideoControl]
libraries: [graphics.library]
---

# 27 / / / The Display Database and the DisplayInfo Record

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each ModeID, the graphics library has a body of data that enables the
set up of the display hardware and provides applications with information
about the properties of the display mode.

The display information in the database is accessed by searching it for a
record with a given ModeID.  For performance reasons, a look-up function
named [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md) is provided which, given a ModeID, will return a
handle to the internal data record about the attributes of the display.

This handle is then used for queries to the display database and
specification of display mode to the low-level graphics routines.  It is
never used as a pointer.  The private data structure associated with a
given ModeID is called a [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md).  From the <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>
include file:


```c
    /* the "public" handle to a DisplayInfo  */

     typedef APTR DisplayInfoHandle;
```
In order to obtain database information about an existing [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md), you
must first gain reference to its 32-bit ModeID.  A graphics function
[GetVPModeID()](autodocs-2.0/graphics-library-getvpmodeid.md) simplifies this operation:


```c
    modeID = ULONG GetVPModeID(struct ViewPort *vp )
```
The vp argument is pointer to a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.  This function returns
the normal display ModeID, if one is currently associated with this
ViewPort.  If no ModeID exists this function returns INVALID_ID.

Each new valid 32-bit ModeID is associated with data initialized by the
graphics library at powerup.  This data is accessed by obtaining a handle
to it with the graphics function [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md).


```c
    handle = DisplayInfoHandle FindDisplayInfo(ULONG modeID);
```
Given a 32-bit ModeID key (modeID in the prototype above)
[FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md) returns a handle to a valid [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) Record found in
the graphics database, or NULL.  Using this handle, you can obtain
information about this video mode, including its default dimensions,
properties and whether it is currently available for use.

For instance, you can use a [DisplayInfoHandle](autodocs-2.0/includes-graphics-displayinfo-h.md) with the [GetDisplayInfoData()](libraries/27-monitors-modes-and-display-database-accessing-displayinfo.md)
function to look up the properties of a mode ([see below](libraries/27-monitors-modes-and-display-database-accessing-displayinfo.md)).  Or use the
DisplayInfoHandle with [VideoControl()](libraries/27-mode-specification-viewport-interface.md) and the [VTAG_NORMAL_DISP_SET](libraries/27-mode-specification-viewport-interface.md) tag to
set up a custom [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).

---

## See Also

- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
