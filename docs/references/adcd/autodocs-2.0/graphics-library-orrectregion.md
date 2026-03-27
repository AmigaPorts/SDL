---
title: graphics.library/OrRectRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-orrectregion
functions: [AndRectRegion, OrRegionRegion]
libraries: [graphics.library]
---

# graphics.library/OrRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OrRectRegion -- Perform 2d OR operation of rectangle
                   with region, leaving result in region.
SYNOPSIS

```c
    status = OrRectRegion(region,rectangle)
      d0                    a0      a1

    BOOL OrRectRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) * );
```
FUNCTION

    If any portion of rectangle is not in the region then add
    that portion to the region.
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
    [AndRectRegion()](autodocs-2.0/graphics-library-andrectregion.md) [OrRegionRegion()](autodocs-2.0/graphics-library-orregionregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
