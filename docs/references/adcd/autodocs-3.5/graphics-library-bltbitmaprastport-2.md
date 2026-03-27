---
title: graphics.library/BltBitMapRastPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-bltbitmaprastport-2
functions: [BltMaskBitMapRastPort]
libraries: [graphics.library]
---

# graphics.library/BltBitMapRastPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	BltBitMapRastPort -- Blit from source bitmap to destination rastport.

   SYNOPSIS
	error = BltBitMapRastPort
	        (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY, minterm)
	 D0      A0     D0    D1    A1      D2     D3     D4     D5     D6

	[BOOL](autodocs-3.5/include-exec-types-h.md) BltBitMapRastPort
	     (struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *, WORD, WORD, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD,
	      WORD, WORD, UBYTE);

   FUNCTION
	Blits from source bitmap to position specified in destination rastport
	using minterm.

   INPUTS
	srcbm   - a pointer to the source bitmap
	srcx    - x offset into source bitmap
	srcy    - y offset into source bitmap
	destrp  - a pointer to the destination rastport
	destX   - x offset into dest rastport
	destY   - y offset into dest rastport
	sizeX   - width of blit in pixels
	sizeY   - height of blit in rows
	minterm - minterm to use for this blit

   RESULT
	TRUE

   BUGS

   SEE ALSO
	[BltMaskBitMapRastPort()](autodocs-3.5/graphics-library-bltmaskbitmaprastport-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [BltMaskBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltmaskbitmaprastport)
