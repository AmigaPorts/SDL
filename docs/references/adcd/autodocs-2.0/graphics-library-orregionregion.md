---
title: graphics.library/OrRegionRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-orregionregion
functions: [OrRectRegion]
libraries: [graphics.library]
---

# graphics.library/OrRegionRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OrRegionRegion -- Perform 2d OR operation of one region
                   with second region, leaving result in second region
SYNOPSIS

```c
    status = OrRegionRegion(region1,region2)
      d0                       a0      a1

    BOOL OrRegionRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Region](autodocs-2.0/includes-graphics-regions-h.md) * );
```
FUNCTION

    If any portion of region1  is not in the region then add
    that portion to the region2
INPUTS

```c
    region1 - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
    region2 - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [OrRectRegion()](autodocs-2.0/graphics-library-orrectregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
