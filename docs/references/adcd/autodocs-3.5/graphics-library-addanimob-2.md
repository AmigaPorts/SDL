---
title: graphics.library/AddAnimOb
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-addanimob-2
functions: [Animate]
libraries: [graphics.library]
---

# graphics.library/AddAnimOb

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddAnimOb  --  Add an [AnimOb](autodocs-3.5/include-graphics-gels-h.md) to the linked list of AnimObs.

   SYNOPSIS
	AddAnimOb(anOb, anKey, rp)
	          A0    A1     A2

	void AddAnimOb(struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) *,struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) **, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Links this [AnimOb](autodocs-3.5/include-graphics-gels-h.md) into the current list pointed to by animKey.
	Initializes all the Timers of the AnimOb's components.
	Calls [AddBob](autodocs-3.5/graphics-library-addbob-2.md) with each component's [Bob](autodocs-3.5/include-graphics-gels-h.md).
	rp->GelsInfo must point to an initialized [GelsInfo](autodocs-3.5/include-graphics-rastport-h.md) structure.

   INPUTS
	anOb  = pointer to the [AnimOb](autodocs-3.5/include-graphics-gels-h.md) structure to be added to the list
	anKey = address of a pointer to the first [AnimOb](autodocs-3.5/include-graphics-gels-h.md) in the list
	        (anKey = NULL if there are no AnimObs in the list so far)
	rp    = pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md)

   RESULT

   BUGS

   SEE ALSO
	[Animate()](autodocs-3.5/graphics-library-animate-2.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md) [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
