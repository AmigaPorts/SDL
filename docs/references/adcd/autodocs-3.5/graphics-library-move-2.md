---
title: graphics.library/Move
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-move-2
functions: [Draw, Text]
libraries: [graphics.library]
---

# graphics.library/Move

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Move -- Move graphics pen position.

   SYNOPSIS
	Move( rp,   x,    y)
	      a1  d0:16 d1:16

	void Move( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [SHORT](autodocs-3.5/include-exec-types-h.md), [SHORT](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Move graphics pen position to (x,y) relative to upper left (0,0)
	of [RastPort](autodocs-3.5/include-graphics-rastport-h.md). This sets the starting point for subsequent [Draw()](autodocs-3.5/graphics-library-draw-2.md)
	and [Text()](autodocs-3.5/graphics-library-text-2.md) calls.

   INPUTS
	rp - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	x,y - point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   RESULTS

   BUGS

   SEE ALSO
	[Draw()](autodocs-3.5/graphics-library-draw-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
