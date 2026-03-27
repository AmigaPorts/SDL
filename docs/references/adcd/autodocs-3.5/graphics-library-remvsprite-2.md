---
title: graphics.library/RemVSprite
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-remvsprite-2
functions: [InitGels, RemIBob]
libraries: [graphics.library]
---

# graphics.library/RemVSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemVSprite -- [Remove](autodocs-3.5/exec-library-remove-2.md) a [VSprite](autodocs-3.5/include-graphics-gels-h.md) from the current gel list.

   SYNOPSIS
	RemVSprite(vs)
	           A0

	void RemVSprite(struct [VSprite](autodocs-3.5/include-graphics-gels-h.md) *);

   FUNCTION
	Unlinks the [VSprite](autodocs-3.5/include-graphics-gels-h.md) from the current gel list.

   INPUTS
	vs = pointer to the [VSprite](autodocs-3.5/include-graphics-gels-h.md) structure to be removed from the gel list

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [RemIBob()](autodocs-3.5/graphics-library-remibob-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
