---
title: graphics.library/DisposeRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-disposeregion
functions: [NewRegion]
libraries: [graphics.library]
---

# graphics.library/DisposeRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DisposeRegion -- Return all space for this region to free
                     memory pool.
SYNOPSIS

```c
    DisposeRegion(region)
                  a0

    void DisposeRegion( struct [Region](autodocs-2.0/includes-graphics-regions-h.md) * );
```
FUNCTION

```c
    Free all RegionRectangles for this [Region](autodocs-2.0/includes-graphics-regions-h.md) then
    free the [Region](autodocs-2.0/includes-graphics-regions-h.md) itself.
```
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
