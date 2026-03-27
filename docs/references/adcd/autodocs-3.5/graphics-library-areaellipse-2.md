---
title: graphics.library/AreaEllipse
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-areaellipse-2
functions: [AreaCircle, AreaDraw, AreaEnd, AreaMove, InitArea]
libraries: [graphics.library]
---

# graphics.library/AreaEllipse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AreaEllipse -- add a ellipse to areainfo list for areafill.


    SYNOPSIS
	error = AreaEllipse( rp, cx,   cy,   a,    b    )
	d0		     a1  d0:16 d1:16 d2:16 d3:16

	[LONG](autodocs-3.5/include-exec-types-h.md) AreaEllipse( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT)

    FUNCTION
	Add an ellipse to the vector buffer. It will be draw when [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) is
	called.

    INPUTS
	rp - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	cx - x coordinate of the centerpoint relative to the rastport.
	cy - y coordinate of the centerpoint relative to the rastport.
	a  - the horizontal radius of the ellipse (note: a must be > 0)
	b  - the vertical radius of the ellipse (note: b must be > 0)

    RESULT
	error - zero for success, or -1 if there is no space left in the
		vector list

    SEE ALSO
	[AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) [AreaCircle()](autodocs-3.5/graphics-library-areacircle-2.md) [InitArea()](autodocs-3.5/graphics-library-initarea-2.md) [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md)
	[graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
