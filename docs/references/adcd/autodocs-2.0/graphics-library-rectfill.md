---
title: graphics.library/RectFill
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-rectfill
functions: [AreaEnd]
libraries: [graphics.library]
---

# graphics.library/RectFill

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RectFill -- Fill a rectangular region in a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS


```c
    RectFill( rp, xmin, ymin, xmax, ymax)
             a1  d0:16 d1:16 d2:16 d3:16

    void RectFill( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT, SHORT, SHORT );
```
FUNCTION

    Fills  the  rectangular  region  specified  by  the
    parameters  with the chosen pen  colors,  areafill
    pattern, and drawing mode. If no areafill pattern is
    specified, fill the rectangular region with the FgPen
    color, taking into account the drawing mode.
INPUTS
```c
    rp - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    (xmin,ymin) (xmax,ymax) are the coordinates of the upper
            left corner and the lower right corner, respectively, of the
            rectangle.
```
NOTE


```c
    The following relation MUST be true:
            (xmax >= xmin) and (ymax >= ymin)
```
BUGS

    Complement mode with FgPen complements all bitplanes.
SEE ALSO

```c
    [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
