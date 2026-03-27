---
title: graphics.library/ClearScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-clearscreen-2
functions: [ClearEOL, SetRast, Text]
libraries: [graphics.library]
---

# graphics.library/ClearScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ClearScreen -- Clear from current position to end of [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   SYNOPSIS
	ClearScreen(rp)
	            A1

	void ClearScreen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Clear a rectangular swath from the current position to the
	right edge of the rastPort with [ClearEOL](autodocs-3.5/graphics-library-cleareol-2.md), then clear the rest
	of the screen from just beneath the swath to the bottom of
	the rastPort.
	Clearing consists of setting the color of the swath to zero,
	or, if the DrawMode is 2, to the BgPen.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

   NOTES
	o   This function may use the blitter.

   SEE ALSO
	[ClearEOL()](autodocs-3.5/graphics-library-cleareol-2.md)  [Text()](autodocs-3.5/graphics-library-text-2.md)  [SetRast()](autodocs-3.5/graphics-library-setrast-2.md)
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [ClearEOL — graphics.library](../autodocs/graphics.library.md#cleareol)
- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
