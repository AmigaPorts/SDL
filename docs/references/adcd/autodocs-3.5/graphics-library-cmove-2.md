---
title: graphics.library/CMOVE
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cmove-2
functions: [CEND, CINIT, CWAIT]
libraries: [graphics.library]
---

# graphics.library/CMOVE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMOVE -- append copper move instruction to user copper list.

   SYNOPSIS
	CMOVE( c , a , v )

	CMove( c , a , v )
	      a1  d0  d1
	CBump( c )
	      a1

	void CMove( struct [UCopList](autodocs-3.5/include-graphics-copper-h.md) *, void *, WORD );

   FUNCTION
	Add instruction to move value v to hardware register a.

   INPUTS
	c - pointer to [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure
	a - hardware register
	v - 16 bit value to be written

   RESULTS
	This is actually a macro that calls CMove(c,&a,v)
	and then calls CBump(c) to bump the local pointer
	to the next instruction. Watch out for macro side affects.

   BUGS

   SEE ALSO
	CINIT() CWAIT() CEND() [graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

---

## See Also

- [CEND — graphics.library](../autodocs/graphics.library.md#cend)
- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CWAIT — graphics.library](../autodocs/graphics.library.md#cwait)
