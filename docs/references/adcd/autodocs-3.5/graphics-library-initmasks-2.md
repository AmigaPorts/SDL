---
title: graphics.library/InitMasks
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initmasks-2
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/InitMasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InitMasks -- Initialize the BorderLine and CollMask masks of a [VSprite](autodocs-3.5/include-graphics-gels-h.md).

   SYNOPSIS
	InitMasks(vs)
	          A0

	void InitMasks(struct [VSprite](autodocs-3.5/include-graphics-gels-h.md) *);

   FUNCTION
	Creates the appropriate BorderLine and CollMask masks of the [VSprite](autodocs-3.5/include-graphics-gels-h.md).
	Correctly detects if the [VSprite](autodocs-3.5/include-graphics-gels-h.md) is actually a [Bob](autodocs-3.5/include-graphics-gels-h.md) definition, handles
	the image data accordingly.

   INPUTS
	vs = pointer to the [VSprite](autodocs-3.5/include-graphics-gels-h.md) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
