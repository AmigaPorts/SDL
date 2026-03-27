---
title: mathffp.library/SPCeil
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathffp-library-spceil-2
functions: [SPFloor]
libraries: [mathffp.library]
---

# mathffp.library/SPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SPCeil -- Compute Ceil function of a number.

   SYNOPSIS
	x = SPCeil(y)
	D0         D0

	float SPCeil(float y);

   FUNCTION
	Calculate the least integer greater than or equal to x and return it.
	This identity is true.  Ceil(x) = -Floor(-x).

   INPUTS
	y 	- Motorola Fast Floating Point [Format](autodocs-3.5/dos-library-format-2.md) Number.

   RESULT
	x 	- Motorola Fast Floating Point [Format](autodocs-3.5/dos-library-format-2.md) Number.

   BUGS
	None.

   SEE ALSO
	[SPFloor()](autodocs-3.5/mathffp-library-spfloor-2.md)

---

## See Also

- [SPFloor — mathffp.library](../autodocs/mathffp.library.md#spfloor)
