---
title: graphics.library/ScrollRasterBF
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-scrollrasterbf
functions: [EraseRect, RectFill, ScrollRaster, ScrollWindowRaster]
libraries: [graphics.library, intuition.library]
---

# graphics.library/ScrollRasterBF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
   ScrollRasterBF -- Push bits in rectangle in raster around by
                   dx,dy towards 0,0 inside rectangle. Newly empty areas
   		will be filled via [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md). (V39)

   SYNOPSIS
   ScrollRasterBF(rp, dx, dy, xmin, ymin, xmax, ymax)

                A1  D0  D1  D2    D3    D4    D5
   void ScrollRasterBF

```c
        (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD, WORD, WORD);
```
   FUNCTION
   [Move](autodocs-3.5/graphics-library-move-2.md) the bits in the raster by (dx,dy) towards (0,0)
   The space vacated is filled by calling EraseRect().
   Limit the scroll operation to the rectangle defined
   by (xmin,ymin)(xmax,ymax). Bits outside will not be
   affected. If xmax,ymax is outside the rastport then use
   the lower right corner of the rastport.
   If you are dealing with a SimpleRefresh layered [RastPort](autodocs-3.5/include-graphics-rastport-h.md) you
   should check rp->Layer->Flags & LAYERREFRESH to see if
   there is any damage in the damage list.  If there is you should
   call the appropriate BeginRefresh(Intuition) or BeginUpdate(graphics)
   routine sequence.

   INPUTS
   rp - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
   dx,dy are integers that may be positive, zero, or negative
   xmin,ymin - upper left of bounding rectangle
   xmax,ymax - lower right of bounding rectangle

   NOTES

   This call is exactly the same as [ScrollRaster](autodocs-3.5/graphics-library-scrollraster-2.md), except that it calls
   [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md) instead of [RectFill()](autodocs-3.5/graphics-library-rectfill-2.md) when clearing the newly exposed
   area. This allows use of a custom layer backfill hook.

   BUGS

   SEE ALSO
   [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md) [intuition.library/ScrollWindowRaster()](autodocs-3.5/intuition-library-scrollwindowraster.md) 
   graphics/rastport.h

---

## See Also

- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [ScrollWindowRaster — intuition.library](../autodocs/intuition.library.md#scrollwindowraster)
