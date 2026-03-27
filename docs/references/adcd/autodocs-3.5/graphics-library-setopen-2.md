---
title: graphics.library/SetOPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setopen-2
functions: [AreaEnd]
libraries: [graphics.library]
---

# graphics.library/SetOPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetOPen -- Change the Area OutLine pen and turn on Outline
			mode for areafills.

   SYNOPSIS
	SetOPen(rp, pen)

	void SetOPen( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	This is implemented as a c-macro.
	Pen is the pen number that will be used to draw a border
	around an areafill during [AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md).

   INPUTS
	rp = pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	pen = number  between 0-255

   BUGS

   SEE ALSO
	[AreaEnd()](autodocs-3.5/graphics-library-areaend-2.md) [graphics/gfxmacros.h](autodocs-3.5/include-graphics-gfxmacros-h.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
