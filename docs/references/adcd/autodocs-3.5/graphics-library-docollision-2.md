---
title: graphics.library/DoCollision
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-docollision-2
functions: [InitGels, SortGList]
libraries: [graphics.library]
---

# graphics.library/DoCollision

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoCollision -- Test every gel in gel list for collisions.

   SYNOPSIS
	DoCollision(rp)
	            A1

	void DoCollision(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Tests each gel in gel list for boundary and gel-to-gel collisions.
	On detecting one of these collisions, the appropriate collision-
	handling routine is called. See the documentation for a thorough
	description of which collision routine is called. This routine
	expects to find the gel list correctly sorted in Y,X order.
	The system routine [SortGList](autodocs-3.5/graphics-library-sortglist-2.md) performs this function for the user.

   INPUTS
	rp = pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [SortGList()](autodocs-3.5/graphics-library-sortglist-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
