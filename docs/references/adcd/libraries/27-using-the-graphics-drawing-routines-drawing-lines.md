---
title: 27 / / Using the Graphics Drawing Routines / Drawing Lines
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-drawing-lines
functions: [Draw, Move]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Drawing Lines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two functions are associated with line drawing: [Move()](autodocs-2.0/graphics-library-move.md) and [Draw()](autodocs-2.0/graphics-library-draw.md). Move()
simply moves the cursor to a new position.  It is like picking up a
drawing pen and placing it at a new location. This function is executed by
the statement:


```c
    Move(&rastPort, x, y);
```
[Draw()](autodocs-2.0/graphics-library-draw.md) draws a line from the current x,y position to a new x,y position
specified in the statement itself. The drawing pen is left at the new
position. This is done by the statement:


```c
    Draw(&rastPort, x, y);
```
[Draw()](autodocs-2.0/graphics-library-draw.md) uses the pen color specified for [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md). Here is a sample sequence
that draws a line from location (0,0) to (100,50).


```c
    SetAPen(&rastPort, COLOR1);    /* Set A pen color. */
    Move(&rastPort, 0, 0);    /* Move to this location. */
    Draw(&rastPort, 100,50);    /* Draw to a this location. */


    Caution:
    --------
    If you attempt to draw a line outside the bounds of the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md),
    using the basic initialized [RastPort](libraries/27-drawing-routines-the-rastport-structure.md), you may crash the system.
    You must either do your own software clipping to assure that the line
    is in range, or use the layers library. Software clipping means that
    you need to determine if the line will fall outside your BitMap
    before you draw it, and render only the part which falls inside
    the BitMap.
```

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [Move — graphics.library](../autodocs/graphics.library.md#move)
