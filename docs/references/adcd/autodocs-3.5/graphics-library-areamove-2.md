---
title: graphics.library/AreaMove
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-areamove-2
functions: [AreaDraw, AreaEllipse, AreaEnd, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaMove

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AreaMove -- Define a new starting point for a new
	            shape in the vector list.


   SYNOPSIS
	error =  AreaMove( rp,   x,     y)
	 d0                a1  d0:16  d1:16

	[LONG](autodocs-3.5/include-exec-types-h.md) AreaMove( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	[Close](autodocs-3.5/dos-library-close-2.md)  the last polygon and start another polygon
	at  (x,y). Add the necessary  points  to  vector
	buffer. Closing a polygon may result in the generation
	of another [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) to close previous polygon.
	[Remember](autodocs-3.5/include-intuition-intuition-h.md) to have an initialized [AreaInfo](autodocs-3.5/include-graphics-rastport-h.md) structure attached
	to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   INPUTS
	rp  - points to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	x,y - positions in the raster

   RETURNS
	error - zero for success, or -1 if there is no space left in the
	vector list

   BUGS

   SEE ALSO
	[InitArea()](autodocs-3.5/graphics-library-initarea-2.md) [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) [AreaEllipse()](autodocs-3.5/graphics-library-areaellipse-2.md) [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
