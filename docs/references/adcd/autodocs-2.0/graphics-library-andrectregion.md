---
title: graphics.library/AndRectRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-andrectregion
functions: [AndRectRegion, AndRegionRegion, OrRectRegion]
libraries: [graphics.library]
---

# graphics.library/AndRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AndRectRegion -- Perform 2d AND operation of rectangle
                     with region, leaving result in region.
SYNOPSIS

```c
    AndRectRegion(region,rectangle)
                    a0      a1

    void AndRectRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) * );
```
FUNCTION

    Clip away any portion of the region that exists outside
    of the rectangle. Leave the result in region.
INPUTS

```c
    region - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
    rectangle - pointer to [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) structure
```
NOTES

```c
    Unlike the other rect-region primitives, AndRectRegion() cannot
    fail.
```
BUGS

SEE ALSO

```c
    [AndRegionRegion()](autodocs-2.0/graphics-library-andregionregion.md) [OrRectRegion()](autodocs-2.0/graphics-library-orrectregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
