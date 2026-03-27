---
title: graphics.library/RemBob
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-rembob-2
functions: [DrawGList, RemIBob]
libraries: [graphics.library]
---

# graphics.library/RemBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemBob -- Macro to remove a [Bob](autodocs-3.5/include-graphics-gels-h.md) from the gel list.

   SYNOPSIS
	RemBob(bob)

	RemBob(struct [Bob](autodocs-3.5/include-graphics-gels-h.md) *);

   FUNCTION
	Marks a [Bob](autodocs-3.5/include-graphics-gels-h.md) as no-longer-required.  The gels internal code then
	removes the [Bob](autodocs-3.5/include-graphics-gels-h.md) from the list of active gels the next time
	[DrawGList](autodocs-3.5/graphics-library-drawglist-2.md) is executed. This is implemented as a macro.
	If the user is double-buffering the [Bob](autodocs-3.5/include-graphics-gels-h.md), it could take two
	calls to [DrawGList](autodocs-3.5/graphics-library-drawglist-2.md) before the [Bob](autodocs-3.5/include-graphics-gels-h.md) actually disappears from
	the [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   INPUTS
	[Bob](autodocs-3.5/include-graphics-gels-h.md) = pointer to the [Bob](autodocs-3.5/include-graphics-gels-h.md) to be removed

   RESULT

   BUGS

   SEE ALSO
	[RemIBob()](autodocs-3.5/graphics-library-remibob-2.md)  [DrawGList()](autodocs-3.5/graphics-library-drawglist-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)  [graphics/gfxmacros.h](autodocs-3.5/include-graphics-gfxmacros-h.md)

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
