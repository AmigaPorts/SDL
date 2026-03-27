---
title: graphics.library/AreaDraw
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-areadraw
functions: [AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaDraw

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    AreaDraw -- Add a point to a list of end points for areafill.
SYNOPSIS

```c
    error = AreaDraw( rp,  x,     y)
      d0              A1 D0:16 D1:16

    ULONG AreaDraw( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT);
```
FUNCTION


    Add point to the vector buffer.
INPUTS

```c
    rp      - points to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure.
    x,y     - are coordinates of a point in the raster.
```
RESULT

    error   - zero for success, else -1 if no there was no space
              left in the vector list.
BUGS

SEE ALSO

```c
    [AreaMove()](autodocs-2.0/graphics-library-areamove.md) [InitArea()](autodocs-2.0/graphics-library-initarea.md) [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
