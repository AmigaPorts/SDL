---
title: graphics.library/AddVSprite
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-addvsprite-2
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/AddVSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddVSprite -- Add a [VSprite](autodocs-3.5/include-graphics-gels-h.md) to the current gel list.

   SYNOPSIS
	AddVSprite(vs, rp)
	           A0  A1

	void AddVSprite(struct [VSprite](autodocs-3.5/include-graphics-gels-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Sets up the system [VSprite](autodocs-3.5/include-graphics-gels-h.md) flags
	Links this [VSprite](autodocs-3.5/include-graphics-gels-h.md) into the current gel list using its Y,X

   INPUTS
	vs = pointer to the [VSprite](autodocs-3.5/include-graphics-gels-h.md) structure to be added to the gel list
	rp = pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
