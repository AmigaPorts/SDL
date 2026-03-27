---
title: graphics.library/AreaEnd
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-areaend
functions: [AreaDraw, AreaEllipse, AreaMove, InitArea, InitTmpRas]
libraries: [graphics.library]
---

# graphics.library/AreaEnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


```c
    AreaEnd -- [Process](autodocs-2.0/includes-dos-dosextens-h.md) table of vectors and ellipses and produce areafill.
```
SYNOPSIS

```c
    error = AreaEnd(rp)
      d0            A1

    LONG AreaEnd( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) * );
```
FUNCTION

```c
    Trigger the filling operation.
    [Process](autodocs-2.0/includes-dos-dosextens-h.md) the vector buffer and generate required
    fill into the raster planes. After the fill is complete, reinitialize
    for the next [AreaMove](autodocs-2.0/graphics-library-areamove.md) or [AreaEllipse](autodocs-2.0/graphics-library-areaellipse.md). Use the raster set up by
    [InitTmpRas](autodocs-2.0/graphics-library-inittmpras.md) when generating an areafill mask.
```
RESULT

    error - zero for success, or -1 if an error occured anywhere.
INPUTS

```c
    rp - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure which specifies where the filled
         regions will be rendered to.
```
BUGS

SEE ALSO

```c
    [InitArea()](autodocs-2.0/graphics-library-initarea.md) [AreaMove()](autodocs-2.0/graphics-library-areamove.md) [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md)  [InitTmpRas()](autodocs-2.0/graphics-library-inittmpras.md)
    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
- [InitTmpRas — graphics.library](../autodocs/graphics.library.md#inittmpras)
