---
title: graphics.library/InitGMasks
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initgmasks-2
functions: [InitMasks]
libraries: [graphics.library]
---

# graphics.library/InitGMasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitGMasks -- Initialize all of the masks of an [AnimOb](autodocs-3.5/include-graphics-gels-h.md).

   SYNOPSIS
	InitGMasks(anOb)
	           A0

	void InitGMasks(struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) *);

   FUNCTION
	For every sequence of every component call [InitMasks](autodocs-3.5/graphics-library-initmasks-2.md).

   INPUTS
	anOb = pointer to the [AnimOb](autodocs-3.5/include-graphics-gels-h.md)

   BUGS

   SEE ALSO
	[InitMasks()](autodocs-3.5/graphics-library-initmasks-2.md) [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
