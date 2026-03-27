---
title: graphics.library/GetOPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getopen
functions: [SetOutlinePen]
libraries: [graphics.library]
---

# graphics.library/GetOPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       GetOPen -- Get the O Pen value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       pen = GetOPen  ( rp )
```
	d0		 a0

	ULONG GetOPen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *)

   FUNCTION
	Return the current value of the O pen for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently, for instance, using more bits.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetOutlinePen()](autodocs-3.5/graphics-library-setoutlinepen.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [SetOutlinePen — graphics.library](../autodocs/graphics.library.md#setoutlinepen)
