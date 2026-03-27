---
title: 27 / / Using the Graphics Drawing Routines / Flood-fill Operations
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-flood-fill-operations
functions: [Flood]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Flood-fill Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Flood fill is a technique for filling an arbitrary shape with a color.
The Amiga flood-fill routines can use a plain color or do the fill using a
combination of the drawing mode, [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) and the area pattern.

Flood-fill requires a [TmpRas](libraries/27-the-rastport-structure-rastport-area-fill-information.md) structure at least as large as the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
in which the flood-fill will be done.  This is to ensure that even if the
flood-filling operation "leaks", it will not flow outside the TmpRas and
corrupt another task's memory.

You use the [Flood()](autodocs-2.0/graphics-library-flood.md) routine for flood fill. The syntax for this routine is
as follows:


```c
    Flood(&rastPort, mode, x, y);
```
The rastPort argument specifies the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) you want to draw into.  The x
and y arguments specify the starting coordinate within the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md).  The
mode argument tells how to do the fill.  There are two different modes for
flood fill:

Outline Mode

```c
    In outline mode, you specify an x,y coordinate, and from that point
    the system searches outward in all directions for a pixel whose color
    is the same as that specified in the area outline pen ([AOlPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md)).  All
    horizontally or vertically adjacent pixels not of that color are
    filled with a colored pattern or plain color.  The fill stops at the
    outline color. Outline mode is selected when the mode argument to
    [Flood()](autodocs-2.0/graphics-library-flood.md) is set to a 0.
```
Color Mode

```c
    In color mode, you specify an x,y coordinate, and whatever pixel
    color is found at that position defines the area to be filled. The
    system searches for all horizontally or vertically adjacent pixels
    whose color is the same as this one and replaces them with the
    colored pattern or plain color.  Color mode is selected when the mode
    argument ot [Flood()](autodocs-2.0/graphics-library-flood.md) is set to a one.
```
The following sample program fragment creates and then flood-fills a
triangular region. The overall effect is exactly the same as shown in the
preceding area-fill example above, except that flood-fill is slightly
slower than area-fill. Mode 0 (fill to a pixel that has the color of the
outline pen) is used in the example.


```c
    BYTE oldAPen;
    UWORD oldDrPt;
    struct RastPort *rastPort = Window->RPort;

    /* Save the old values of the foreground pen and draw pattern. */
    oldAPen = rastPort->FgPen;
    oldDrPt = rastPort->LinePtrn;

    /* Use AreaOutline pen color for foreground pen. */
    SetAPen(rastPort, rastPort->AOlPen);
    SetDrPt(rastPort, ~0);      /* Insure a solid draw pattern. */

    Move(rastPort, 0, 0);  /* Using mode 0 to create a triangular shape */
    Draw(rastPort, 0, 100);
    Draw(rastPort, 100, 100);
    Draw(rastPort, 0, 0);       /* close it */

    SetAPen(rastPort, oldAPen); /* Restore original foreground pen. */
    Flood(rastPort, 0, 10, 50); /* Start Flood() inside triangle. */

    SetDrPt(rastPort, oldDrPt); /* Restore original draw mode. */
```
This example saves the current [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) value and draws the shape in the same
color as [AOlPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md). Then FgPen is restored to its original color so that
FgPen, [BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [DrawMode](libraries/27-the-rastport-structure-rastport-drawing-modes.md), and [AreaPtrn](libraries/27-drawing-routines-the-rastport-structure.md) can be used to define the fill within
the outline.

---

## See Also

- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
