---
title: graphics.library/AndRectRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-andrectregion-2
functions: [AndRectRegion, AndRegionRegion, OrRectRegion]
libraries: [graphics.library]
---

# graphics.library/AndRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AndRectRegion -- Perform 2d AND operation of rectangle
			 with region, leaving result in region.

   SYNOPSIS
	AndRectRegion(region,rectangle)
 			a0	a1

	void AndRectRegion( struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) * );

   FUNCTION
	Clip away any portion of the region that exists outside
	of the rectangle. Leave the result in region.

   INPUTS
	region - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
	rectangle - pointer to [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) structure

   NOTES
	Unlike the other rect-region primitives, AndRectRegion() cannot
	fail.

   BUGS

   SEE ALSO
	[AndRegionRegion()](autodocs-3.5/graphics-library-andregionregion-2.md) [OrRectRegion()](autodocs-3.5/graphics-library-orrectregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
- [AndRegionRegion — graphics.library](../autodocs/graphics.library.md#andregionregion)
- [OrRectRegion — graphics.library](../autodocs/graphics.library.md#orrectregion)
