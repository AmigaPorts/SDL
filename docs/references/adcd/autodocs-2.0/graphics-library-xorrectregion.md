---
title: graphics.library/XorRectRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-xorrectregion
functions: [AndRegionRegion, OrRegionRegion]
libraries: [graphics.library]
---

# graphics.library/XorRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    XorRectRegion -- Perform 2d XOR operation of rectangle
                     with region, leaving result in region
SYNOPSIS

```c
    status = XorRectRegion(region,rectangle)
    d0                     a0      a1

    BOOL XorRectRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) * );
```
FUNCTION

    Add portions of rectangle to region if they are not in
    the region.
    Remove portions of rectangle from region if they are
    in the region.
INPUTS

```c
    region - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
    rectangle - pointer to [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) structure
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [OrRegionRegion()](autodocs-2.0/graphics-library-orregionregion.md) [AndRegionRegion()](autodocs-2.0/graphics-library-andregionregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
