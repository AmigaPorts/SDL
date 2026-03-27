---
title: graphics.library/SetMaxPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setmaxpen
functions: [SetWriteMask]
libraries: [graphics.library]
---

# graphics.library/SetMaxPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       SetMaxPen -- set maximum pen value for a rastport (V39).
```
   SYNOPSIS
```c
       SetMaxPen ( rp, maxpen)
```
   		    a0   d0

	void SetMaxPen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *,ULONG)

   FUNCTION
	This will instruct the graphics library that the owner of the rastport
	will not be rendering in any colors whose index is >maxpen. If there
	are any speed optimizations which the graphics device can make based
	on this fact (for instance, setting the pixel write mask), they will
	be done.

	Basically this call sets the rastport mask, if this would improve
	speed. On devices where masking would slow things down (like with
	chunky pixels), it will be a no-op.

   INPUTS
```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
	maxpen =  a longword pen value.

   BUGS

   NOTES
	The maximum pen value passed must take into account not only which
	colors you intend to render in the future, but what colors you will
	be rendering on top of.
	SetMaxPen(rp,0) doesn't make much sense.

   SEE ALSO
	[SetWriteMask()](autodocs-3.5/graphics-library-setwritemask.md)

---

## See Also

- [SetWriteMask — graphics.library](../autodocs/graphics.library.md#setwritemask)
