---
title: graphics.library/SortGList
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-sortglist-2
functions: [DoCollision, DrawGList, InitGels]
libraries: [graphics.library]
---

# graphics.library/SortGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SortGList -- Sort the current gel list, ordering its y,x coordinates.

   SYNOPSIS
	SortGList(rp)
	          A1

	void SortGList(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Sorts the current gel list according to the gels' y,x coordinates.
	This sorting is essential before calls to [DrawGList](autodocs-3.5/graphics-library-drawglist-2.md) or [DoCollision](autodocs-3.5/graphics-library-docollision-2.md).

   INPUTS
	rp = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure containing the [GelsInfo](autodocs-3.5/include-graphics-rastport-h.md)

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [DoCollision()](autodocs-3.5/graphics-library-docollision-2.md)  [DrawGList()](autodocs-3.5/graphics-library-drawglist-2.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
