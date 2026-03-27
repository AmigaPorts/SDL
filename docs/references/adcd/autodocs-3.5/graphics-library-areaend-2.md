---
title: graphics.library/AreaEnd
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-areaend-2
functions: [AreaDraw, AreaEllipse, AreaMove, InitArea, InitTmpRas]
libraries: [graphics.library]
---

# graphics.library/AreaEnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AreaEnd -- [Process](autodocs-3.5/include-dos-dosextens-h.md) table of vectors and ellipses and produce areafill.


   SYNOPSIS
	error = AreaEnd(rp)
	  d0  	        A1

	[LONG](autodocs-3.5/include-exec-types-h.md) AreaEnd( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) * );

   FUNCTION
	Trigger the filling operation.
	[Process](autodocs-3.5/include-dos-dosextens-h.md) the vector buffer and generate required
	fill into the raster planes. After the fill is complete, reinitialize
	for the next [AreaMove](autodocs-3.5/graphics-library-areamove-2.md) or [AreaEllipse](autodocs-3.5/graphics-library-areaellipse-2.md). Use the raster set up by
	[InitTmpRas](autodocs-3.5/graphics-library-inittmpras-2.md) when generating an areafill mask.

   RESULT
	error - zero for success, or -1 if an error occurred anywhere.

   INPUTS
	rp - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure which specifies where the filled
	     regions will be rendered to.

   BUGS

   SEE ALSO
	[InitArea()](autodocs-3.5/graphics-library-initarea-2.md) [AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) [AreaEllipse()](autodocs-3.5/graphics-library-areaellipse-2.md)  [InitTmpRas()](autodocs-3.5/graphics-library-inittmpras-2.md)
	[graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
- [InitTmpRas — graphics.library](../autodocs/graphics.library.md#inittmpras)
