---
title: graphics.library/AreaEllipse
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-areaellipse
functions: [AreaCircle, AreaDraw, AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaEllipse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    AreaEllipse -- add a ellipse to areainfo list for areafill.
SYNOPSIS

```c
    error = AreaEllipse( rp, cx,   cy,   a,    b    )
    d0                   a1  d0:16 d1:16 d2:16 d3:16

    LONG AreaEllipse( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT, SHORT, SHORT)
```
FUNCTION

```c
    Add an ellipse to the vector buffer. It will be draw when [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) is
    called.
```
INPUTS

```c
    rp - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    cx - x coordinate of the centerpoint relative to the rastport.
    cy - y coordinate of the centerpoint relative to the rastport.
    a  - the horizontal radius of the ellipse (note: a must be > 0)
    b  - the vertical radius of the ellipse (note: b must be > 0)
```
RESULT

    error - zero for success, or -1 if there is no space left in the
            vector list
SEE ALSO

```c
    [AreaMove()](autodocs-2.0/graphics-library-areamove.md) [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) [AreaCircle()](autodocs-2.0/graphics-library-areacircle.md) [InitArea()](autodocs-2.0/graphics-library-initarea.md) [AreaEnd()](autodocs-2.0/graphics-library-areaend.md)
    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
