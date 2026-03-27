---
title: graphics.library/AreaCircle
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-areacircle
functions: [AreaCircle, AreaDraw, AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaCircle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    AreaCircle -- add a circle to areainfo list for areafill.
SYNOPSIS

```c
    error = (int) AreaCircle( rp,  cx,  cy, radius)
    D0                        A1   D0   D1  D2

    ULONG AreaCircle(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD, UWORD);
```
FUNCTION

```c
    Add circle to the vector buffer. It will be drawn to the rastport when
    [AreaEnd](autodocs-2.0/graphics-library-areaend.md) is executed.
```
INPUTS

```c
    rp       - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure

    cx, cy   - the coordinates of the center of the desired circle.

    radius   - is the radius of the circle to draw around the centerpoint.
```
RESULTS

    0 if no error
    -1 if no space left in vector list
NOTES

```c
    This function is actually a macro which calls
        AreaEllipse(rp,cx,cy,radius,radius).
```
SEE ALSO

```c
    [AreaMove()](autodocs-2.0/graphics-library-areamove.md) [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) AreaCircle() [InitArea()](autodocs-2.0/graphics-library-initarea.md) [AreaEnd()](autodocs-2.0/graphics-library-areaend.md)
    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md) [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)
```

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
