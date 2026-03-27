---
title: 27 / / Using Graphics Drawing Routines / Drawing Ellipses and Circles
manual: libraries
chapter: libraries
section: 27-using-graphics-drawing-routines-drawing-ellipses-and
functions: [DrawEllipse]
libraries: [graphics.library]
---

# 27 / / Using Graphics Drawing Routines / Drawing Ellipses and Circles

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two functions are associated with drawing ellipses: [DrawCircle()](autodocs-2.0/includes-graphics-gfxmacros-h.md) and
[DrawEllipse()](autodocs-2.0/graphics-library-drawellipse.md). DrawCircle(), a macro that calls DrawEllipse(), will draw a
circle from the specified center point using the specified radius.  This
function is executed by the statement:


```c
    DrawCircle(&rastPort, center_x, center_y, radius);
```
Similarly, [DrawEllipse()](autodocs-2.0/graphics-library-drawellipse.md) draws an ellipse with the specified radii from
the specified center point:


```c
    DrawEllipse(&rastPort, center_x, center_y, horiz_r, vert_r);
```
Neither function performs clipping on a non-layered [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).

---

## See Also

- [DrawEllipse — graphics.library](../autodocs/graphics.library.md#drawellipse)
