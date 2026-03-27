---
title: graphics.library/ClearEOL
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cleareol-2
functions: [ClearScreen, SetRast, Text]
libraries: [graphics.library]
---

# graphics.library/ClearEOL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ClearEOL -- Clear from current position to end of line.

   SYNOPSIS
	ClearEOL(rp)
	         A1

	void ClearEOL(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Clear a rectangular swath from the current position to the
	right edge of the rastPort.  The height of the swath is taken
	from that of the current text font, and the vertical
	positioning of the swath is adjusted by the text baseline,
	such that text output at this position would lie wholly on
	this newly cleared area.
	Clearing consists of setting the color of the swath to zero,
	or, if the DrawMode is 2, to the BgPen.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

   RESULT

   NOTES
	o   This function may use the blitter.

   SEE ALSO
	[Text()](autodocs-3.5/graphics-library-text-2.md)  [ClearScreen()](autodocs-3.5/graphics-library-clearscreen-2.md)  [SetRast()](autodocs-3.5/graphics-library-setrast-2.md)
	[graphics/text.h](autodocs-3.5/include-graphics-text-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [ClearScreen — graphics.library](../autodocs/graphics.library.md#clearscreen)
- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
