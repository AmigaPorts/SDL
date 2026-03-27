---
title: graphics.library/CWAIT
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cwait-2
functions: [CEND, CINIT, CMOVE]
libraries: [graphics.library]
---

# graphics.library/CWAIT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CWAIT -- Append copper wait instruction to user copper list.

   SYNOPSIS
	CWAIT( c , v , h )

	CWait( c , v , h )
	       a1  d0  d1
	CBump( c )
	      a1

	void CWait( struct [UCopList](autodocs-3.5/include-graphics-copper-h.md) *, WORD, WORD)

   FUNCTION
	Add instruction to wait for vertical beam position v and
	horizontal position h to this intermediate copper list.

   INPUTS
	c - pointer to [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure
	v - vertical beam position (relative to top of viewport)
	h - horizontal beam position

   RESULTS
	this is actually a macro that calls CWait(c,v,h)
	and then calls CBump(c) to bump the local pointer
	to the next instruction.

   BUGS
	User waiting for horizontal values of greater than 222 decimal
	is illegal.

   SEE ALSO
 	CINIT() CMOVE() CEND() [graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

---

## See Also

- [CEND — graphics.library](../autodocs/graphics.library.md#cend)
- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CMOVE — graphics.library](../autodocs/graphics.library.md#cmove)
