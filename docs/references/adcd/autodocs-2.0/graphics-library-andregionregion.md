---
title: graphics.library/AndRegionRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-andregionregion
functions: [AndRectRegion, OrRegionRegion]
libraries: [graphics.library]
---

# graphics.library/AndRegionRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AndRegionRegion -- Perform 2d AND operation of one region
                      with second region, leaving result in second region.
SYNOPSIS

```c
    status = AndRegionRegion(region1,region2)
      d0                       a0      a1

    BOOL AndRegionRegion(struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Region](autodocs-2.0/includes-graphics-regions-h.md) * );
```
FUNCTION

    Remove any portion of region2 that is not in region1.
INPUTS

```c
    region1 - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
    region2 - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure to use and for result
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [OrRegionRegion()](autodocs-2.0/graphics-library-orregionregion.md) [AndRectRegion()](autodocs-2.0/graphics-library-andrectregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
