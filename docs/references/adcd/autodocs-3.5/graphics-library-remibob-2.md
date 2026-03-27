---
title: graphics.library/RemIBob
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-remibob-2
functions: [InitGels, RemVSprite]
libraries: [graphics.library]
---

# graphics.library/RemIBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemIBob -- Immediately remove a [Bob](autodocs-3.5/include-graphics-gels-h.md) from the gel list and the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   SYNOPSIS
	RemIBob(bob, rp, vp)
	        A0   A1  A2

	void RemIBob(struct [Bob](autodocs-3.5/include-graphics-gels-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	Removes a [Bob](autodocs-3.5/include-graphics-gels-h.md) immediately by uncoupling it from the gel list and
	erases it from the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   INPUTS
	bob = pointer to the [Bob](autodocs-3.5/include-graphics-gels-h.md) to be removed
	rp  = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) if the [Bob](autodocs-3.5/include-graphics-gels-h.md) is to be erased
	vp  = pointer to the [ViewPort](autodocs-3.5/include-graphics-view-h.md) for beam-synchronizing

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [RemVSprite()](autodocs-3.5/graphics-library-remvsprite-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [RemVSprite — graphics.library](../autodocs/graphics.library.md#remvsprite)
