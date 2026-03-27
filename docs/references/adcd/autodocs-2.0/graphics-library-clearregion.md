---
title: graphics.library/ClearRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-clearregion
functions: [NewRegion]
libraries: [graphics.library]
---

# graphics.library/ClearRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ClearRegion -- Remove all rectangles from region.
SYNOPSIS

```c
    ClearRegion(region)
                 a0

    void ClearRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) * );
```
FUNCTION

    Clip away all rectangles in the region leaving nothing.
INPUTS

```c
    region - pointer to [Region](autodocs-2.0/includes-graphics-regions-h.md) structure
```
BUGS

SEE ALSO

```c
    [NewRegion()](autodocs-2.0/graphics-library-newregion.md) [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
