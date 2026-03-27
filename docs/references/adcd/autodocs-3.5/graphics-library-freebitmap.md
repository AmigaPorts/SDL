---
title: graphics.library/FreeBitMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freebitmap
functions: [AllocBitMap, WaitBlit]
libraries: [graphics.library]
---

# graphics.library/FreeBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeBitMap -- free a bitmap created by [AllocBitMap](autodocs-3.5/graphics-library-allocbitmap.md) (V39)

   SYNOPSIS
	FreeBitMap(bm)
	           a0

	VOID FreeBitMap(struct [BitMap](autodocs-3.5/include-graphics-gfx-h.md) *)

   FUNCTION
	Frees bitmap and all associated bitplanes

   INPUTS
	bm  =  A pointer to a [BitMap](autodocs-3.5/include-graphics-gfx-h.md) structure. Passing a NULL-pointer
	       (meaning "do nothing") is OK.

   BUGS

   NOTES
	Be careful to insure that any rendering done to the bitmap has
	completed (by calling [WaitBlit()](autodocs-3.5/graphics-library-waitblit-2.md)) before you call this function.

   SEE ALSO
	[AllocBitMap()](autodocs-3.5/graphics-library-allocbitmap.md)

---

## See Also

- [AllocBitMap — graphics.library](../autodocs/graphics.library.md#allocbitmap)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
