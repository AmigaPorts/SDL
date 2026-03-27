---
title: 27 / / / Drawing Multiple Lines with a Single Command
manual: libraries
chapter: libraries
section: 27-drawing-multiple-lines-with-a-single-command
functions: [Draw, PolyDraw]
libraries: [graphics.library]
---

# 27 / / / Drawing Multiple Lines with a Single Command

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can use multiple [Draw()](autodocs-2.0/graphics-library-draw.md) statements to draw connected line figures. If
the shapes are all definable as interconnected, continuous lines, you can
use a simpler function, called [PolyDraw()](autodocs-2.0/graphics-library-polydraw.md). PolyDraw() takes a set of line
endpoints and draws a shape using these points. You call PolyDraw() with
the statement:


```c
    PolyDraw(&rastPort, count, arraypointer);
```
[PolyDraw()](autodocs-2.0/graphics-library-polydraw.md) reads the array of points and draws a line from the first pair
of coordinates to the second, then a connecting line to each succeeding
pair in the array until count points have been connected. This function
uses the current drawing mode, pens, line pattern, and write mask
specified in the target [RastPort](libraries/27-drawing-routines-the-rastport-structure.md); for example, this fragment draws a
rectangle, using the five defined pairs of x,y coordinates.


```c
    SHORT linearray[] =
        {
         3, 3,
        15, 3,
        15,15,
         3,15,
         3, 3
        };

    PolyDraw(&rastPort, 5, linearray);
```

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [PolyDraw — graphics.library](../autodocs/graphics.library.md#polydraw)
