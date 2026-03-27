---
title: graphics.library/DisposeRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-disposeregion-2
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
```
	void DisposeRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) * );

   FUNCTION
```c
       Free all RegionRectangles for this [Region](autodocs-3.5/include-graphics-regions-h.md) then
```
	free the [Region](autodocs-3.5/include-graphics-regions-h.md) itself.

   INPUTS

```c
       region - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
```
   BUGS

   SEE ALSO
	[NewRegion()](autodocs-3.5/graphics-library-newregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
