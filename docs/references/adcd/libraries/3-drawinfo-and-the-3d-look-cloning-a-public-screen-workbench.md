---
title: 3 / DrawInfo and the 3D Look / Cloning a Public Screen (Workbench)
manual: libraries
chapter: libraries
section: 3-drawinfo-and-the-3d-look-cloning-a-public-screen-workbench
functions: [GetRGB4, GetScreenData, GetScreenDrawInfo, GetVPModeID, LoadRGB4, LockPubScreen, OpenScreenTagList, QueryOverscan, SetRGB4, SetRGB4CM, VideoControl]
libraries: [graphics.library, intuition.library]
---

# 3 / DrawInfo and the 3D Look / Cloning a Public Screen (Workbench)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

User preferences for screen attributes are generally reflected in the
Workbench screen or in the default [public screen](libraries/3-intuition-screens-public-screen-functions.md).  In some cases it may be
useful to create a new screen with the same attributes.

Under V34, information on a screen was available through the
[GetScreenData()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) call.  Due to extensions in V36 screen and graphics
capabilities, this call is no longer sufficient to completely describe the
display.  Applications should now use a variety of calls; the specific
call depends on the information required.

[LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) returns a pointer to the Screen structure of a specific
screen.  [GetScreenDrawInfo()](libraries/3-drawinfo-and-the-3d-look-cloning-a-public-screen-workbench.md) returns rendering information on the screen,
such as the pen array and font used.  [QueryOverscan()](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md) returns the overscan
information of a specific display mode (for more information, see the
section on "[Overscan and the Display Clip](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md)").

The example below shows how to use [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md) to examine the
attributes of the Workbench screen so that a new screen with the same
attributes can be created.


```c
    struct DrawInfo *GetScreenDrawInfo( struct Screen * )
```
The attributes required to clone an existing screen are its width, height,
depth, pens and mode.  The pens and screen depth are available through the
[DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  The width and height may be obtained from the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md)
structure.  (The width and height may be larger than the overscan area if
the screen is scrollable, and autoscroll may always be enabled as it does
not effect displays smaller than or equal to the overscan area.)

The screen's display mode can be obtained using the graphics library call
[GetVPModeID()](libraries/27-the-display-database-and-the-displayinfo-record.md).  This call returns the display ID of an existing screen
which can then be used as the data for the [SA_DisplayID](libraries/3-custom-screen-functions-screen-attributes.md) tag in
[OpenScreenTagList()](libraries/3-intuition-screens-custom-screen-functions.md).  Note that the example assumes the screen should be
open to the user's text overscan preference.  If an exact copy of the
display clip of the existing screen is required, use the [VideoControl()](libraries/27-mode-specification-viewport-interface.md)
command of the graphics library to access the [ViewPortExtra](autodocs-2.0/includes-graphics-view-h.md) structure.

The colors of the screen may be copied using the graphics library calls
[GetRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md), [SetRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md), [SetRGB4CM()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) and [LoadRGB4()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md).  The example code does
not copy the colors.

The example copies the font from the cloned screen.  A reasonable
alternative would be to use the user's preference font, which may be
accessed through the [SA_SysFont](libraries/3-custom-screen-functions-screen-attributes.md) tag.


```c
     [clonescreen.c](libraries/lib-examples-clonescreen-c.md) 
```

---

## See Also

- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
