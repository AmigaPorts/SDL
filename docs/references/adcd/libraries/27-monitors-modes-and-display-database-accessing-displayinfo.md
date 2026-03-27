---
title: 27 / / Monitors, Modes and Display Database / Accessing DisplayInfo
manual: libraries
chapter: libraries
section: 27-monitors-modes-and-display-database-accessing-displayinfo
functions: [FindDisplayInfo, GetDisplayInfoData]
libraries: [graphics.library]
---

# 27 / / Monitors, Modes and Display Database / Accessing DisplayInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Basic information about a display can be obtained by calling the Release 2
graphics function [GetDisplayInfoData()](autodocs-2.0/graphics-library-getdisplayinfodata.md).  You also call this function
during the set up of a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).

   result = ULONG GetDisplayInfoData( DisplayInfoHandle handle, UBYTE *buf,

```c
                                  ULONG size, ULONG tagID, ULONG modeID )
```
Set the handle argument to the [DisplayInfoHandle](autodocs-2.0/includes-graphics-displayinfo-h.md) returned by a previous
call to [FindDisplayInfo()](libraries/27-the-display-database-and-the-displayinfo-record.md).  This function will also accept a 32-bit ModeID
directly as an argument.  The handle argument should be set to NULL in
that case.

The buf argument points to a destination buffer you have set up to hold
the information about the properties of the display.  The size argument
gives the size of the buffer which depends on the type of inquiry you make.

The tagID argument specifies the type information you want to know about
and may be set as follows:


```c
    DTAG_DISP  Returns display properties and availability information
               (the buffer should be set to the size of a [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md)
               structure).

    DTAG_DIMS  Returns default dimensions and overscan information (the
               buffer should be set to the size of a [DimensionInfo](autodocs-2.0/includes-graphics-displayinfo-h.md)
               structure).

    DTAG_MNTR  Returns monitor type, view position, scan rate, and
               compatibility (the buffer should be set to the size of a
               [MonitorInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) structure).

    DTAG_NAME  Returns the user friendly name for this mode (the buffer
               should be set to the size of a [NameInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) structure).
```
If the call succeeds, result is positive and reports the number of bytes
actually transferred to the buffer.  If the call fails (no information for
the ModeID was available), result is zero.

---

## See Also

- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
