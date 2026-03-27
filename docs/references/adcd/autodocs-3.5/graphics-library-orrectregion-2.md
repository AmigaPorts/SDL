---
title: graphics.library/OrRectRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-orrectregion-2
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
```
	[BOOL](autodocs-3.5/include-exec-types-h.md) OrRectRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) * );

   FUNCTION 

       If any portion of rectangle is not in the region then add
       that portion to the region.
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
	[AndRectRegion()](autodocs-3.5/graphics-library-andrectregion-2.md) [OrRegionRegion()](autodocs-3.5/graphics-library-orregionregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
