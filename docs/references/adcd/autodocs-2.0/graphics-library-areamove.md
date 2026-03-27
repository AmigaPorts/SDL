---
title: graphics.library/AreaMove
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-areamove
functions: [AreaDraw, AreaEllipse, AreaEnd, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaMove

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    AreaMove -- Define a new starting point for a new
                shape in the vector list.
SYNOPSIS

```c
    error =  AreaMove( rp,   x,     y)
     d0                a1  d0:16  d1:16

    LONG AreaMove( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT );
```
FUNCTION

```c
    Close  the last polygon and start another polygon
    at  (x,y). Add the necessary  points  to  vector
    buffer. Closing a polygon may result in the generation
    of another [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) to close previous polygon.
    [Remember](autodocs-2.0/includes-intuition-intuition-h.md) to have an initialized [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure attached
    to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    rp  - points to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    x,y - positions in the raster
```
RETURNS

    error - zero for success, or -1 if there is no space left in the
    vector list
BUGS

SEE ALSO

```c
    [InitArea()](autodocs-2.0/graphics-library-initarea.md) [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md) [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
