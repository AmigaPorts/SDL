---
title: graphics.library/Animate
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-animate-2
functions: [AddAnimOb]
libraries: [graphics.library]
---

# graphics.library/Animate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Animate  --  Processes every [AnimOb](autodocs-3.5/include-graphics-gels-h.md) in the current animation list.

   SYNOPSIS
	Animate(anKey, rp)
	        A0     A1

	void Animate(struct [AnimOb](autodocs-3.5/include-graphics-gels-h.md) **, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	For every [AnimOb](autodocs-3.5/include-graphics-gels-h.md) in the list
	    - update its location and velocities
	    - call the AnimOb's special routine if one is supplied
	    - for each component of the [AnimOb](autodocs-3.5/include-graphics-gels-h.md)
	        - if this sequence times out, switch to the new one
	        - call this component's special routine if one is supplied
	        - set the sequence's VSprite's y,x coordinates based
	          on whatever these routines cause

   INPUTS
	ankey = address of the variable that points to the head [AnimOb](autodocs-3.5/include-graphics-gels-h.md)
	rp    = pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure

   RESULT

   BUGS

   SEE ALSO
	[AddAnimOb()](autodocs-3.5/graphics-library-addanimob-2.md) [graphics/gels.h](autodocs-3.5/include-graphics-gels-h.md) [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [AddAnimOb — graphics.library](../autodocs/graphics.library.md#addanimob)
