---
title: graphics.library/SetAPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setapen-2
functions: [SetBPen]
libraries: [graphics.library]
---

# graphics.library/SetAPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
	SetAPen -- Set the primary pen for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   SYNOPSIS
	SetAPen( rp, pen )
		 a1  d0

	void SetAPen( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Set the primary drawing pen for lines, fills, and text.

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
	pen - (0-255)

   RESULT
	Changes the minterms in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to reflect new primary pen.
	Sets line drawer to restart pattern.

   BUGS

   SEE ALSO
	[SetBPen()](autodocs-3.5/graphics-library-setbpen-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
