---
title: 27 / / Using Drawing Routines / Ellipse and Circle-fill Operations
manual: libraries
chapter: libraries
section: 27-using-drawing-routines-ellipse-and-circle-fill-operations
functions: [AreaCircle, AreaEllipse, SetOPen]
libraries: [graphics.library]
---

# 27 / / Using Drawing Routines / Ellipse and Circle-fill Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two functions are associated with drawing filled ellipses: [AreaCircle()](autodocs-2.0/graphics-library-areacircle.md)
and [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md). AreaCircle()  (a macro that calls AreaEllipse()) will
draw a circle from the specified center point using the specified radius.
This function is executed by the statement:


```c
    AreaCircle(&rastPort, center_x, center_y, radius);
```
Similarly, [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md) draws a filled ellipse with the specified radii
from the specified center point:


```c
    AreaEllipse(&rastPort, center_x, center_y, horiz_r, vert_r);
```
Outlining with [SetOPen()](autodocs-2.0/graphics-library-setopen.md) is not currently supported by the [AreaCircle()](autodocs-2.0/graphics-library-areacircle.md)
and [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md) routines.


```c
    Caution:
    --------
    If you attempt to fill an area outside the bounds of the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md),
    using the basic initialized [RastPort](libraries/27-drawing-routines-the-rastport-structure.md), it may crash the system. You
    must either do your own software clipping to assure that the area is
    in range, or use the layers library.
```

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [SetOPen — graphics.library](../autodocs/graphics.library.md#setopen)
