---
title: 27 / / / Mode Specification, ViewPort Interface
manual: libraries
chapter: libraries
section: 27-mode-specification-viewport-interface
functions: [GetColorMap, GfxFree, GfxNew, VideoControl]
libraries: [graphics.library]
---

# 27 / / / Mode Specification, ViewPort Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When working directly with graphics, the interface is based on [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) and
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structures, rather than on Intuition's [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  As
previously mentioned, new information must be associated with the ViewPort
to specify the new Release 2 modes, and also with the View to specify what
virtual monitor the whole View will be displayed on.  There is also a lot
of information to associate with a ViewPort regarding enhanced genlock
capabilities.

This association of this new data with the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) is made through a display
database system which has been added to the Release 2 graphics library.
All correctly written programs that allocate a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure for a
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) use the [GetColorMap()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) function to do it.  Hence, in Release 2 the
ColorMap structure is used as the general purpose black box extension of
the ViewPort data.

To set or obtain the data in the extended structures, Release 2 provides a
new function named [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) which takes a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) as an argument.
This allows the setting and getting of the new extended display data.
This mechanism is used to associate a [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) handle (not a ModeID)
with a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  A DisplayInfo handle is an abstract link to the display
database area associated with a particular ModeID.  This handle is passed
to the graphics database functions when getting or setting information
about the mode. Using VideoControl(), a program can enable, disable, or
obtain the state of a ViewPort's ColorMap, mode, genlock and other
features.  The function uses a tag based interface and returns NULL if no
error occurred.


```c
    error = BOOL VideoControl( struct ColorMap *cm, struct TagItem *tag );
```
The first argument is a pointer to a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure as returned by the
[GetColorMap()](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) function.  The second argument is a pointer to an array of
video control tag items, used to indicate whether information is being
given or requested as well as to pass (or receive the information).  The
tags you can use with [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) include the following:

VTAG_ATTACH_CM_GET (or _SET) is used to obtain the [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure from
the indicated [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) or attach a given ColorMap to it.

VTAG_VIEWPORTEXTRA_GET (or _SET) is used to obtain the [ViewPortExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md)
structure from the indicated [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure or attach a given
ViewPortExtra to it.  A ViewPortExtra structure is an extension of the
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure and should be allocated and freed with [GfxNew()](libraries/27-display-routines-and-structures-forming-a-basic-display.md) and
[GfxFree()](autodocs-2.0/graphics-library-gfxfree.md) and associated with the ViewPort with [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md).

VTAG_NORMAL_DISP_GET (or _SET) is used to obtain or set the [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md)
structure for the standard or "normal" mode.

See <graphics/[videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md)> for a list of all the available tags.  See
the [section on genlocking](libraries/27-graphics-primitives-ecs-and-genlocking-features.md) for information on using [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md) to
interact with the Amiga's genlock capabilities.  Note that the graphics
library will modify the tag list passed to VideoControl().

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
