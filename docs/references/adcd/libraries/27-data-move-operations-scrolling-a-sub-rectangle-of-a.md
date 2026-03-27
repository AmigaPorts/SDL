---
title: 27 / / Data Move Operations / Scrolling a Sub-rectangle of a Raster
manual: libraries
chapter: libraries
section: 27-data-move-operations-scrolling-a-sub-rectangle-of-a
functions: [CopySBitMap, ScrollRaster, SyncSBitMap]
libraries: [graphics.library]
---

# 27 / / Data Move Operations / Scrolling a Sub-rectangle of a Raster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can scroll a sub-rectangle of a raster in any direction--up, down,
left, right, or diagonally. To perform a scroll, you use the
[ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) routine and specify a dx and dy (delta-x, delta-y) by which
the rectangle image should be moved relative to the (0,0) location.

As a result of this operation, the data within the rectangle will become
physically smaller by the size of delta-x and delta-y, and the area
vacated by the data when it has been cropped and moved is filled with the
background color (color in [BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md)). [ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) is affected by the [Mask](libraries/27-the-rastport-structure-rastport-write-mask.md)
setting.

Here is the syntax of the [ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) function:


```c
    ScrollRaster(&rastPort, dx, dy, xmin, ymin, xmax, ymax);
```
The &rastPort argument is a pointer to a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).  The dx and dy
arguments are the distances (positive, 0, or negative) to move the
rectangle.  The outer bounds of the sub-rectangle are defined by the xmin,
xmax, ymin and ymax arguments.

Here are some examples that scroll a sub-rectangle:


```c
    /* scroll up 2 */
    ScrollRaster(&rastPort, 0, 2, 10, 10, 50, 50);

    /* scroll right 1 */
    ScrollRaster(&rastPort, -1, 0, 10, 10, 50, 50);
```
When scrolling a Simple Refresh window (or other layered [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)),
[ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) scrolls the appropriate existing damage region.  Refer to
the "[Intuition Windows](libraries/4-intuition-windows-preserving-the-window-display.md)" chapter for an explanation of [Simple Refresh](libraries/4-refreshing-intuition-windows-simple-refresh.md)
windows and [damage regions](libraries/4-preserving-the-window-display-damage-regions.md).

When scrolling a SuperBitMap window [ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md) requires a properly
initialized TmpRas.  The TmpRas must be initialized to the size of one
bitplane with a width and height the same as the SuperBitMap, using the
technique described in the "[Area-Fill Information](libraries/27-the-rastport-structure-rastport-area-fill-information.md)" section above.

If you are using a SuperBitMap [Layer](libraries/30-layers-the-layer-structure.md), it is possible that the information
in the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) is not fully reflected in the layer and vice-versa.  Two
graphics calls, [CopySBitMap()](libraries/4-setting-up-a-superbitmap-window-graphics-and-layers.md) and [SyncSBitMap()](libraries/4-setting-up-a-superbitmap-window-graphics-and-layers.md), remedy these situations.
Again, refer to the "[Intuition Windows](libraries/4-preserving-the-window-display-setting-up-a-superbitmap.md)" chapter for more on this.

---

## See Also

- [CopySBitMap — graphics.library](../autodocs/graphics.library.md#copysbitmap)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [SyncSBitMap — graphics.library](../autodocs/graphics.library.md#syncsbitmap)
