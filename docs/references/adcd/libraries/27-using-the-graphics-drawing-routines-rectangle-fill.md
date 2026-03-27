---
title: 27 / / Using the Graphics Drawing Routines / Rectangle-fill Operations
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-rectangle-fill
functions: [RectFill]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Rectangle-fill Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The final fill function, [RectFill()](autodocs-2.0/graphics-library-rectfill.md), is for filling rectangular areas.
The form of this function follows:


```c
    RectFill(&rastPort, xmin, ymin, xmax, ymax);
```
As usual, the rastPort argument specifies the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) you want to draw
into.  The xmin and ymin arguments specify the upper left corner of the
rectangle to be filled. The xmax and ymax arguments specify the lower
right corner of the rectangle to be filled.  Note that the variable xmax
must be equal to or greater than xmin, and ymax must be equal to or
greater than ymin.

Rectangle-fill uses [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [AOlPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md), [DrawMode](libraries/27-the-rastport-structure-rastport-drawing-modes.md), [AreaPtrn](libraries/27-drawing-routines-the-rastport-structure.md) and [Mask](libraries/27-the-rastport-structure-rastport-write-mask.md) to
fill the area you specify. Remember that the fill can be multicolored as
well as single- or two-colored.  When the DrawMode is [COMPLEMENT](libraries/27-the-rastport-structure-rastport-drawing-modes.md), it
complements all bit planes, rather than only those planes in which the
foreground is non-zero.

---

## See Also

- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
