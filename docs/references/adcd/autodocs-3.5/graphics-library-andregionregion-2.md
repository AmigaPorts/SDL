---
title: graphics.library/AndRegionRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-andregionregion-2
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
```
	[BOOL](autodocs-3.5/include-exec-types-h.md) AndregionRegion(struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Region](autodocs-3.5/include-graphics-regions-h.md) * );

   FUNCTION 

```c
       [Remove](autodocs-3.5/exec-library-remove-2.md) any portion of region2 that is not in region1.
```
   INPUTS 

```c
       region1 - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
       region2 - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure to use and for result
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS 

   SEE ALSO
	[OrRegionRegion()](autodocs-3.5/graphics-library-orregionregion-2.md) [AndRectRegion()](autodocs-3.5/graphics-library-andrectregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [OrRegionRegion — graphics.library](../autodocs/graphics.library.md#orregionregion)
