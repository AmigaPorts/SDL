---
title: graphics.library/SetABPenDrMd
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setabpendrmd
functions: [SetAPen, SetBPen, SetDrMd]
libraries: [graphics.library]
---

# graphics.library/SetABPenDrMd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
 	SetABPenDrMd -- Set pen colors and draw mode for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md). (V39)

   SYNOPSIS
	SetABPenDrMd( rp, apen, bpen, mode )
		 		  a1  d0     d1    d2

	void SetABPenDrMd( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, ULONG, ULONG, ULONG );

   FUNCTION
	Set the pen values and drawing mode for lines, fills and text.
	Get the bit definitions from rastport.h

   INPUTS
	rp - pointer to [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
	apen - primary pen value
	bpen - secondary pen value
	mode - 0-255, some combinations may not make much sense.

   RESULT
	The mode set is dependent on the bits selected.
	Changes minterms to reflect new drawing mode and colors.
	Sets line drawer to restart pattern.

	NOTES
	This call is essentially the same as a sequence of
	SetAPen()/SetBPen()/SetDrMD() calls, except that it is
	significantly faster. The minterms will only be generated
	once, or not at all if nothing changed (warning to illegal
	[RastPort](autodocs-3.5/include-graphics-rastport-h.md) pokers!).

   BUGS

   SEE ALSO
	[SetAPen()](autodocs-3.5/graphics-library-setapen-2.md) [SetBPen()](autodocs-3.5/graphics-library-setbpen-2.md) [SetDrMd()](autodocs-3.5/graphics-library-setdrmd-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
- [SetDrMd — graphics.library](../autodocs/graphics.library.md#setdrmd)
