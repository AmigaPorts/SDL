---
title: graphics.library/CBump
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cbump-2
functions: [CEND, CINIT, CMOVE, CWAIT]
libraries: [graphics.library]
---

# graphics.library/CBump

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CBump -  increment user copper list pointer (bump to next position in list).

   SYNOPSIS
	CBump( c )
	      a1

	void CBump( struct [UCopList](autodocs-3.5/include-graphics-copper-h.md) * );

   FUNCTION
	Increment pointer to space for next instruction in user copper list.

   INPUTS
	c - pointer to [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure

   RESULTS
	User copper list pointer is incremented to next position.
	Pointer is repositioned to next user copperlist instruction block
	if the current block is full.

	    Note: CBump is usually invoked for the programmer as part of the
	          macro definitions [CWAIT](autodocs-3.5/graphics-library-cwait-2.md) or [CMOVE](autodocs-3.5/graphics-library-cmove-2.md).

   BUGS

   SEE ALSO
	CINIT() CWAIT() CMOVE() CEND() [graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

---

## See Also

- [CEND — graphics.library](../autodocs/graphics.library.md#cend)
- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CMOVE — graphics.library](../autodocs/graphics.library.md#cmove)
- [CWAIT — graphics.library](../autodocs/graphics.library.md#cwait)
