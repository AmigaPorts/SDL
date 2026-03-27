---
title: 27 / / Using the Graphics Drawing Routines / Reading Individual Pixels
manual: libraries
chapter: libraries
section: 27-using-the-graphics-drawing-routines-reading-individual
functions: [ReadPixel]
libraries: [graphics.library]
---

# 27 / / Using the Graphics Drawing Routines / Reading Individual Pixels

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can determine the color of a specific pixel with a statement like this:


```c
    SHORT x, y;
    LONG result;
    result = ReadPixel(&rastPort, x, y);
```
[ReadPixel()](autodocs-2.0/graphics-library-readpixel.md) returns the value of the pixel color selector at the specified
x,y location. If the coordinates you specify are outside the range of your
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md), this function returns a value of -1.

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
