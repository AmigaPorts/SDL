---
title: graphics.library/SetDrMd
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setdrmd-2
functions: [SetAPen, SetBPen]
libraries: [graphics.library]
---

# graphics.library/SetDrMd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
 	SetDrMd -- Set drawing mode for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   SYNOPSIS
	SetDrMd( rp, mode )
		 a1  d0:8

	void SetDrMd( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Set the drawing mode for lines, fills and text.
	Get the bit definitions from rastport.h

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
	mode - 0-255, some combinations may not make much sense.

   RESULT
	The mode set is dependent on the bits selected.
	Changes minterms to reflect new drawing mode.
	Sets line drawer to restart pattern.

   BUGS

   SEE ALSO
	[SetAPen()](autodocs-3.5/graphics-library-setapen-2.md) [SetBPen()](autodocs-3.5/graphics-library-setbpen-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
