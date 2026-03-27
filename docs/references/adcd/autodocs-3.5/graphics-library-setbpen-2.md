---
title: graphics.library/SetBPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setbpen-2
functions: [SetAPen]
libraries: [graphics.library]
---

# graphics.library/SetBPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
	SetBPen -- Set secondary pen for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   SYNOPSIS
	SetBPen( rp, pen )
		 a1  d0

	void SetBPen( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Set the secondary drawing pen for lines, fills, and text.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
	pen - (0-255)

   RESULT
	Changes the minterms in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to reflect new secondary pen.
	Sets line drawer to restart pattern.

   BUGS

    SEE ALSO
	[SetAPen()](autodocs-3.5/graphics-library-setapen-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
