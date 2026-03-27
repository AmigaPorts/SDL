---
title: 27 / / Using the Graphics Drawing Routines / Drawing Individual Pixels
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-drawing-individual
functions: [WritePixel]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Drawing Individual Pixels

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can set a specific pixel to a desired color by using a statement like
this:


```c
    SHORT x, y;
    LONG result;
    result = WritePixel(&rastPort, x, y);
```
[WritePixel()](autodocs-2.0/graphics-library-writepixel.md) uses the primary drawing pen and changes the pixel at that
x,y position to the desired color if the x,y coordinate falls within the
boundaries of the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md). A value of 0 is returned if the write was
successful; a value of -1 is returned if x,y was outside the range of the
RastPort.

---

## See Also

- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
