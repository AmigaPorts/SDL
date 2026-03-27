---
title: graphics.library/Flood
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-flood
functions: [AreaEnd, InitTmpRas]
libraries: [graphics.library]
---

# graphics.library/Flood

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Flood -- Flood rastport like areafill.
SYNOPSIS

```c
    error = Flood( rp, mode, x, y)
    d0            a1   d2  d0  d1

    BOOL Flood(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, ULONG, SHORT, SHORT);
```
FUNCTION

```c
    Search the [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) starting at (x,y).
    Fill all adjacent pixels if they are:
        Mode 0: not the same color as AOLPen
        Mode 1: the same color as the pixel at (x,y)

    When actually doing the fill use the modes that apply to
    standard areafill routine such as drawmodes and patterns.
```
INPUTS

```c
    rp - pointer to [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    (x,y) - coordinate in [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) to start the flood fill at.
    mode -  0 fill all adjacent pixels searching for border.
            1 fill all adjacent pixels that have same pen number
            as the one at (x,y).
```
NOTES

```c
    In order to use Flood, the destination [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) must
    have a valid [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) raster whose size is as large as
    that of the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SEE ALSO

```c
    [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [InitTmpRas()](autodocs-2.0/graphics-library-inittmpras.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [InitTmpRas — graphics.library](../autodocs/graphics.library.md#inittmpras)
