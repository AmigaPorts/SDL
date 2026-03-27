---
title: graphics.library/GetBPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getbpen
functions: [SetBPen]
libraries: [graphics.library]
---

# graphics.library/GetBPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       GetBPen -- Get the B Pen value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       pen = GetBPen  ( rp )
```
	d0	   	 a0

	ULONG GetBPen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *)

   FUNCTION
	Return the current value of the B pen for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently, using more bits.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetBPen()](autodocs-3.5/graphics-library-setbpen-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
