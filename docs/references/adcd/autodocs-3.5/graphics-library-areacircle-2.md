---
title: graphics.library/AreaCircle
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-areacircle-2
functions: [AreaCircle, AreaDraw, AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaCircle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AreaCircle -- add a circle to areainfo list for areafill.


    SYNOPSIS
	error = (int) AreaCircle( rp,  cx,  cy, radius)
	D0			  A1   D0   D1	D2

	ULONG AreaCircle(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD, UWORD);

    FUNCTION
	Add circle to the vector buffer. It will be drawn to the rastport when
	[AreaEnd](autodocs-3.5/graphics-library-areaend-2.md) is executed.

    INPUTS
	rp	 - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

	cx, cy   - the coordinates of the center of the desired circle.

	radius	 - is the radius of the circle to draw around the centerpoint.

    RESULTS
	0 if no error
	-1 if no space left in vector list

    NOTES
	This function is actually a macro which calls
	    AreaEllipse(rp,cx,cy,radius,radius).

    SEE ALSO
	[AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) AreaCircle() [InitArea()](autodocs-3.5/graphics-library-initarea-2.md) [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md)
	[graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md) [graphics/gfxmacros.h](autodocs-3.5/include-graphics-gfxmacros-h.md)

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
