---
title: graphics.library/PolyDraw
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-polydraw-2
functions: [Draw, Move]
libraries: [graphics.library]
---

# graphics.library/PolyDraw

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PolyDraw -- [Draw](autodocs-3.5/graphics-library-draw-2.md) lines from table of (x,y) values.

   SYNOPSIS
	PolyDraw( rp, count , array )
		  a1   d0      a0

	void PolyDraw( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD * );

   FUNCTION
	starting with the first pair in the array, draw connected lines to
	it and every successive pair.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	count -  number of (x,y) pairs in the array
	array - pointer to first (x,y) pair

   BUGS

   SEE ALSO
	[Draw()](autodocs-3.5/graphics-library-draw-2.md) [Move()](autodocs-3.5/graphics-library-move-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [Move — graphics.library](../autodocs/graphics.library.md#move)
