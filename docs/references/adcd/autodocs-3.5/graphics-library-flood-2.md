---
title: graphics.library/Flood
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-flood-2
functions: [AreaEnd, InitTmpRas]
libraries: [graphics.library]
---

# graphics.library/Flood

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Flood -- Flood rastport like areafill.

   SYNOPSIS
	error = Flood( rp, mode, x, y)

        d0            a1   d2  d0  d1
	[BOOL](autodocs-3.5/include-exec-types-h.md) Flood(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, ULONG, [SHORT](autodocs-3.5/include-exec-types-h.md), SHORT);

   FUNCTION
	Search the [BitMap](autodocs-3.5/include-graphics-gfx-h.md) starting at (x,y).
	Fill all adjacent pixels if they are:
	    Mode 0: not the same color as AOLPen
	    Mode 1: the same color as the pixel at (x,y)

	When actually doing the fill use the modes that apply to
	standard areafill routine such as drawmodes and patterns.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	(x,y) - coordinate in [BitMap](autodocs-3.5/include-graphics-gfx-h.md) to start the flood fill at.
	mode -  0 fill all adjacent pixels searching for border.
		1 fill all adjacent pixels that have same pen number
		as the one at (x,y).

   NOTES
	In order to use Flood, the destination [RastPort](autodocs-3.5/include-graphics-rastport-h.md) must
	have a valid [TmpRas](autodocs-3.5/include-graphics-rastport-h.md) raster whose size is as large as
	that of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   SEE ALSO
	[AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [InitTmpRas()](autodocs-3.5/graphics-library-inittmpras-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [InitTmpRas — graphics.library](../autodocs/graphics.library.md#inittmpras)
