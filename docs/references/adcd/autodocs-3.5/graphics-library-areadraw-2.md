---
title: graphics.library/AreaDraw
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-areadraw-2
functions: [AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaDraw

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AreaDraw -- Add a point to a list of end points for areafill.


   SYNOPSIS
	error = AreaDraw( rp,  x,     y)
	  d0	          A1 D0:16 D1:16

	ULONG AreaDraw( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT);

   FUNCTION
	Add point to the vector buffer.


   INPUTS
	rp	- points to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
	x,y	- are coordinates of a point in the raster.

   RESULT
	error	- zero for success, else -1 if no there was no space
		  left in the vector list.

   BUGS

   SEE ALSO
	[AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) [InitArea()](autodocs-3.5/graphics-library-initarea-2.md) [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
