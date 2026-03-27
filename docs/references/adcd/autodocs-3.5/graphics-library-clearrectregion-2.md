---
title: graphics.library/ClearRectRegion
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-clearrectregion-2
functions: [AndRectRegion]
libraries: [graphics.library]
---

# graphics.library/ClearRectRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ClearRectRegion -- Perform 2d CLEAR operation of rectangle
			with region, leaving result in region.

   SYNOPSIS
	status = ClearRectRegion(region,rectangle)
	 d0	 	 	  a0 	  a1

	[BOOL](autodocs-3.5/include-exec-types-h.md) ClearRectRegion(struct [Region](autodocs-3.5/include-graphics-regions-h.md) *, struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) * );

   FUNCTION
	Clip away any portion of the region that exists inside
	of the rectangle. Leave the result in region.

   INPUTS
	region - pointer to [Region](autodocs-3.5/include-graphics-regions-h.md) structure
	rectangle - pointer to [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) structure

   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS

   SEE ALSO
	[AndRectRegion()](autodocs-3.5/graphics-library-andrectregion-2.md) [graphics/regions.h](autodocs-3.5/include-graphics-regions-h.md)

---

## See Also

- [AndRectRegion — graphics.library](../autodocs/graphics.library.md#andrectregion)
