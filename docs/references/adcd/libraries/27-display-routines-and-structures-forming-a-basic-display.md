---
title: 27 / Display Routines and Structures / Forming a Basic Display
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-forming-a-basic-display
functions: [GfxAssociate, GfxFree, GfxLookUp, GfxNew, VideoControl]
libraries: [graphics.library]
---

# 27 / Display Routines and Structures / Forming a Basic Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here are the data structures that you need to define to create a basic
display:


```c
    struct View view;               /* These get used in all versions of */
    struct ViewPort viewPort;       /* the OS */
    struct BitMap bitMap;
    struct RasInfo rasInfo;
    struct ColorMap *cm;

    struct ViewExtra *vextra;       /* Extra View data, new in Release 2 */
    struct ViewPortExtra *vpextra;  /* Extra ViewPort data, new in       */
                                    /* Release 2 */
    struct MonitorSpec *monspec;    /* Monitor data needed in Release 2  */
    struct DimensionInfo dimquery;  /* Display dimension data needed in  */
                                    /* Release 2 */
```
[ViewExtra](autodocs-2.0/includes-graphics-view-h.md) and [ViewPortExtra](autodocs-2.0/includes-graphics-view-h.md) are new data structures used in Release 2 to
hold extended data about their corresponding parent structure.  ViewExtra
contains information about the video monitor being used to render the
[View](libraries/27-display-routines-and-structures-viewport-display-memory.md).  ViewPortExtra contains information required for clipping of the
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).

[GfxNew()](autodocs-2.0/graphics-library-gfxnew.md) is used to create these extended data structures and
[GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md) is used to associate the extended data structure with an
appropriate parent structure.  Although GfxAssociate() can associate a
[ViewPortExtra](autodocs-2.0/includes-graphics-view-h.md) structure with a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md), it is better to use
[VideoControl()](libraries/27-mode-specification-viewport-interface.md) with the [VTAG_VIEWPORTEXTRA_SET](libraries/27-mode-specification-viewport-interface.md) tag instead.  Keep in mind
that GfxNew() allocates memory for the resulting data structure which must
be returned using [GfxFree()](autodocs-2.0/graphics-library-gfxfree.md) before the application exits.  The function
[GfxLookUp()](autodocs-2.0/graphics-library-gfxlookup.md) will find the address of an extended data structure from the
address of its parent.

 [Preparing the View Structure](libraries/27-forming-a-basic-display-preparing-the-view-structure.md) 
 [Preparing the BitMap Structure](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md) 
 [Preparing the RasInfo Structure](libraries/27-forming-a-basic-display-preparing-the-rasinfo-structure.md) 
 [Preparing the ViewPort Structure](libraries/27-forming-a-basic-display-preparing-the-viewport-structure.md) 
 [Preparing the ColorMap Structure](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md) 
 [Creating the Display Instructions](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) 

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxLookUp — graphics.library](../autodocs/graphics.library.md#gfxlookup)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
