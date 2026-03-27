---
title: 27 / Display Routines and Structures / Viewport Display Memory
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-viewport-display-memory
functions: [VideoControl]
libraries: [graphics.library]
---

# 27 / Display Routines and Structures / Viewport Display Memory

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The picture you create in memory can be larger than the screen image that
can be displayed within your ViewPort.  This big picture (called a raster
and represented by the BitMap structure) can have a maximum size dependent
upon the version of the Agnus chip in the Amiga.  The ECS Agnus can handle
rasters up to 16,384 by 16,384 pixels.  Older Agnus chips are limited to
rasters up to 1,024 by 1,024 pixels.  The section earlier in this chapter
on "[Determining Chip Versions](libraries/27-about-ecs-determining-chip-versions.md)" explains how to find out which Agnus is
installed.

The example in the following figure introduces terms that tell the system
how to find the display data and how to display it in the ViewPort. These
terms are RHeight, RWidth, [RyOffset,](autodocs-2.0/includes-graphics-view-h.md) [RxOffset,](autodocs-2.0/includes-graphics-view-h.md) [DHeight](libraries/27-viewport-size-specifications-viewport-height.md), [DWidth](libraries/27-viewport-size-specifications-viewport-width.md), [DyOffset](autodocs-2.0/includes-graphics-view-h.md)
and [DxOffset](autodocs-2.0/includes-graphics-view-h.md).


```c
     [Figure 27-16: ViewPort Data Area Parameters](libraries/lib-pics-27-16-pic.md)
```
The terms RHeight and RWidth do not appear in actual system data
structures.  They refer to the dimensions of the raster and are used here
to relate the size of the raster to the size of the display area. RHeight
is the number of rows in the raster and RWidth is the number of bytes per
row times 8.  The raster shown in the figure is too big to fit entirely in
the display area, so you tell the system which pixel of the raster should
appear in the upper left corner of the display segment specified by your
ViewPort.  The variables that control that placement are [RyOffset](autodocs-2.0/includes-graphics-view-h.md) and
[RxOffset](autodocs-2.0/includes-graphics-view-h.md).

To compute [RyOffset](autodocs-2.0/includes-graphics-view-h.md) and [RxOffset](autodocs-2.0/includes-graphics-view-h.md), you need RHeight, RWidth, [DHeight](libraries/27-viewport-size-specifications-viewport-height.md), and
[DWidth](libraries/27-viewport-size-specifications-viewport-width.md).  The DHeight and DWidth variables define the height and width in
pixels of the portion of the display that you want to appear in the
ViewPort.  The example shows a full-screen, low-resolution mode
(320-pixel), non-interlaced (200-line) display formed from the larger
overall picture.

Normal values for [RyOffset](autodocs-2.0/includes-graphics-view-h.md) and [RxOffset](autodocs-2.0/includes-graphics-view-h.md) are defined by the formulas:


```c
    0 < = RyOffset < = (RHeight - DHeight)
    0 < = RxOffset < = (RWidth - DWidth)
```
Once you have defined the size of the raster and the section of that
raster that you wish to display, you need only specify where to put this
ViewPort on the screen.  This is controlled by the ViewPort variables
[DyOffset](autodocs-2.0/includes-graphics-view-h.md) and [DxOffset](autodocs-2.0/includes-graphics-view-h.md).  These are offsets relative to the [View.DxOffset](autodocs-2.0/includes-graphics-view-h.md)
and [DyOffset](autodocs-2.0/includes-graphics-view-h.md). Possible NTSC values for DyOffset range from -23 to +217
(-46 to +434 if the ViewPort is interlaced), PAL values range from -15 to
+267 (-30 to +534 for interlaced ViewPorts).  Possible values for DxOffset
range from -18 to +362 (-36 to +724 if the ViewPort is Hires, -72 to +1448
if SuperHires), when the View is in its default, initialized position.

The parameters shown in the figure above are distributed in the following
data structures:

  * [View](autodocs-2.0/includes-graphics-view-h.md) (information about the whole display) includes the variables

    that you use to position the whole display on the screen.  The View
    structure contains a Modes field used to determine if the whole
    display is to be interlaced or non-interlaced.  It also contains
    pointers to its list of ViewPorts and pointers to the Copper
    instructions produced by the system to create the display you have
    defined.
  * [ViewPort](autodocs-2.0/includes-graphics-view-h.md) (information about this segment of the display) includes the

```c
    values [DxOffset](autodocs-2.0/includes-graphics-view-h.md) and [DyOffset](autodocs-2.0/includes-graphics-view-h.md) that are used to position this portion
    relative to the overall View.  The ViewPort also contains the
    variables [DHeight](libraries/27-viewport-size-specifications-viewport-height.md) and [DWidth](libraries/27-viewport-size-specifications-viewport-width.md), which define the size of this display
    segment; a [Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) variable; and a pointer to the local [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).
    Under Release 2, the [VideoControl()](libraries/27-mode-specification-viewport-interface.md) function and its various tags are
    used to manipulate the ColorMap and ViewPort.Modes.  Each ViewPort
    also contains a pointer to the next ViewPort.  You create a linked
    list of ViewPorts to define the complete display.
```
  * [RasInfo](autodocs-2.0/includes-graphics-view-h.md) (information about the raster) contains the variables

```c
    [RxOffset](autodocs-2.0/includes-graphics-view-h.md) and [RyOffset](autodocs-2.0/includes-graphics-view-h.md). It also contains pointers to the BitMap
    structure and to a companion RasInfo structure if this is a dual
    playfield.
```
  * [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) (information about memory usage) tells the system where to

    find the display and drawing area memory and shows how this memory
    space is organized, including the display's depth.
You must allocate enough memory for the display you define. The memory you
use for the display may be shared with the area control structures used
for drawing.  This allows you to draw into the same areas that you are
currently displaying on the screen.

As an alternative, you can define two BitMaps.  One of them can be the
active structure (that being displayed) and the other can be the inactive
structure.  If you draw into one BitMap while displaying another, the user
cannot see the drawing taking place. This is called double-buffering of
the display.  See "[Advanced Topics](libraries/27-advanced-topics-creating-a-double-buffered-display.md)" below for an explanation of the steps
required for double-buffering.  Double-buffering takes twice as much
memory as single-buffering because two full displays are produced.

To determine the amount of required memory for each ViewPort for
single-buffering, you can use the following formula.


```c
    #include <graphics/gfx.h>

    /* Depth, Width, and Height get set to something reasonable. */
    UBYTE Depth, Width, Height;

    /* Calculate resulting VP size. */
    bytes_per_ViewPort = Depth * RASSIZE(Width, Height);
```
RASSIZE() is a system macro attuned to the current design of the system
memory allocation for display rasters.  See the <graphics/[gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)> include
file for the formula with which RASSIZE() is calculated.

For example, a 32-color ViewPort (depth = 5), 320 pixels wide by 200 lines
high currently uses 40,000 bytes.  A 16-color ViewPort (depth = 4), 640
pixels wide by 400 lines high currently uses 128,000 bytes.

---

## See Also

- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
