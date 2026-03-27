---
title: graphics.library/InitArea
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initarea-2
functions: [AreaDraw, AreaEllipse, AreaEnd, AreaMove]
libraries: [graphics.library]
---

# graphics.library/InitArea

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   

	InitArea -- Initialize vector collection matrix

   SYNOPSIS

   	InitArea( areainfo, buffer, maxvectors )
		    a0          a1      d0

	void InitArea(struct [AreaInfo](autodocs-3.5/include-graphics-rastport-h.md) *, void *, SHORT);

   FUNCTION
	This function provides initialization for the vector collection matrix
	such that it has a size of (max vectors ).  The size of the region
	pointed to by buffer (short pointer) should be five (5) times as large
	as maxvectors. This size is in bytes.  Areafills done by using [AreaMove](autodocs-3.5/graphics-library-areamove-2.md),
	[AreaDraw](autodocs-3.5/graphics-library-areadraw-2.md), and [AreaEnd](autodocs-3.5/graphics-library-areaend-2.md) must have enough space allocated in this table to
	store all the points of the largest fill. [AreaEllipse](autodocs-3.5/graphics-library-areaellipse-2.md) takes up two
	vectors for every call. If AreaMove/Draw/Ellipse detect too many
	vectors going into the buffer they will return -1.

   INPUTS
	areainfo - pointer to [AreaInfo](autodocs-3.5/include-graphics-rastport-h.md) structure
	buffer - pointer to chunk of memory to collect vertices
	maxvectors - max number of vectors this buffer can hold

   RESULT
	Pointers are set up to begin storage of vectors done by
	[AreaMove](autodocs-3.5/graphics-library-areamove-2.md), [AreaDraw](autodocs-3.5/graphics-library-areadraw-2.md), and [AreaEllipse](autodocs-3.5/graphics-library-areaellipse-2.md).

   BUGS

   SEE ALSO
	[AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [AreaMove()](autodocs-3.5/graphics-library-areamove-2.md) [AreaDraw()](autodocs-3.5/graphics-library-areadraw-2.md) [AreaEllipse()](autodocs-3.5/graphics-library-areaellipse-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
