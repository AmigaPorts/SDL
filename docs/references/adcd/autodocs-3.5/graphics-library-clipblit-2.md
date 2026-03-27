---
title: graphics.library/ClipBlit
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-clipblit-2
functions: [BltBitMap]
libraries: [graphics.library]
---

# graphics.library/ClipBlit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ClipBlit  --  Calls [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md) after accounting for windows

   SYNOPSIS
	ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)
	         A0   D0    D1    A1    D2     D3     D4     D5     D6

	void ClipBlit
	     (struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD,
	      WORD, WORD, UBYTE);

   FUNCTION
	Performs the same function as [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md), except that it
	takes into account the Layers and ClipRects of the layer library,
	all of which are (and should be) transparent to you.  So, whereas
	[BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md) requires pointers to BitMaps, ClipBlit requires pointers to
	the RastPorts that contain the Bitmaps, Layers, etcetera.

	If you are going to blit blocks of data around via the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) of your
	Intuition [Window](autodocs-3.5/include-intuition-intuition-h.md), you must call this routine (rather than [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md)).

	Either the Src [RastPort](autodocs-3.5/include-graphics-rastport-h.md), the Dest [RastPort](autodocs-3.5/include-graphics-rastport-h.md), both, or neither, can have
	Layers. This routine takes care of all cases.

	See [BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md) for a thorough explanation.

   INPUTS
	Src          = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) of the source for your blit
	SrcX, SrcY   = the topleft offset into Src for your data
	Dest         = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to receive the blitted data
	DestX, DestY = the topleft offset into the destination [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	XSize        = the width of the blit (must be ta least 1)
	YSize        = the height of the blit (must be at least 1)
	Minterm      = the boolean blitter function, where SRCB is associated
	               with the Src [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and SRCC goes to the Dest [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   RESULT

   BUGS

   SEE ALSO
	[BltBitMap()](autodocs-3.5/graphics-library-bltbitmap-2.md)

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
