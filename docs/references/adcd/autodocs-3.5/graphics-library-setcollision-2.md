---
title: graphics.library/SetCollision
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setcollision-2
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/SetCollision

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetCollision -- Set a pointer to a user collision routine.

   SYNOPSIS
	SetCollision(num, routine, GInfo)
	             D0   A0       A1

	void SetCollision(ULONG, VOID (*)(), struct [GelsInfo](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	Sets a specified entry (num) in the user's collision vectors table
	equal to the address of the specified collision routine.

   INPUTS
	num     = collision vector number
	routine = pointer to the user's collision routine
	GInfo   = pointer to a [GelsInfo](autodocs-3.5/include-graphics-rastport-h.md) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](autodocs-3.5/graphics-library-initgels-2.md)  [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
