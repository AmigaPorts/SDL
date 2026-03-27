---
title: graphics.library/XorRectRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-xorrectregion-2
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
```
	[BOOL](autodocs-3.5/include-exec-types-h.md) XorRectRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) * );

   FUNCTION
	Add portions of rectangle to region if they are not in
	the region.
	[Remove](autodocs-3.5/exec-library-remove-2.md) portions of rectangle from region if they are
	in the region.

   INPUTS

```c
       region - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
       rectangle - pointer to [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) structure
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS

   SEE ALSO
	[OrRegionRegion()](autodocs-3.5/graphics-library-orregionregion-2.md) [AndRegionRegion()](autodocs-3.5/graphics-library-andregionregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
