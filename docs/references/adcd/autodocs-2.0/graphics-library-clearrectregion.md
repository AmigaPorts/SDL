---
title: graphics.library/ClearRectRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-clearrectregion
functions: [AndRectRegion]
libraries: [graphics.library]
---

# graphics.library/ClearRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ClearRectRegion -- Perform 2d CLEAR operation of rectangle
                    with region, leaving result in region.
SYNOPSIS

```c
    status = ClearRectRegion(region,rectangle)
     d0                       a0      a1

    BOOL ClearRectRegion(struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *, struct [Rectangle](autodocs-2.0/includes-graphics-gfx-h.md) * );
```
FUNCTION

    Clip away any portion of the region that exists inside
    of the rectangle. Leave the result in region.
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
    [AndRectRegion()](autodocs-2.0/graphics-library-andrectregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
