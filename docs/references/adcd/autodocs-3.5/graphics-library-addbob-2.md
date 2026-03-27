---
title: graphics.library/AddBob
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-addbob-2
functions: [AddVSprite, InitGels]
libraries: [graphics.library]
---

# graphics.library/AddBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddBob -- Adds a [Bob](autodocs-3.5/include-graphics-gels-h.md) to current gel list.

   SYNOPSIS
	AddBob(Bob, rp)
	       A0   A1

	void AddBob(struct [Bob](autodocs-3.5/include-graphics-gels-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Sets up the system [Bob](autodocs-3.5/include-graphics-gels-h.md) flags, then links this gel into the list
	via [AddVSprite](autodocs-3.5/graphics-library-addvsprite-2.md).

   INPUTS
	[Bob](autodocs-3.5/include-graphics-gels-h.md) = pointer to the [Bob](autodocs-3.5/include-graphics-gels-h.md) structure to be added to the gel list
	rp  = pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [AddVSprite()](autodocs-3.5/graphics-library-addvsprite-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
