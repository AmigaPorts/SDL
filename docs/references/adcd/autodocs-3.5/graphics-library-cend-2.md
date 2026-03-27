---
title: graphics.library/CEND
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cend-2
functions: [CINIT, CMOVE, CWAIT]
libraries: [graphics.library]
---

# graphics.library/CEND

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CEND -- Terminate user copper list.

   SYNOPSIS
	CEND( c )

	struct [UCopList](autodocs-3.5/include-graphics-copper-h.md) *c;

   FUNCTION
	Add instruction to terminate user copper list.

   INPUTS
	c - pointer to [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure

   RESULTS
	This is actually a macro that calls the macro CWAIT(c,10000,255)
	10000 is a magical number that the graphics.library uses.
	I hope display technology doesn't catch up too fast!

   BUGS

   SEE ALSO
	CINIT() CWAIT() CMOVE() [graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

---

## See Also

- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CMOVE — graphics.library](../autodocs/graphics.library.md#cmove)
- [CWAIT — graphics.library](../autodocs/graphics.library.md#cwait)
