---
title: graphics.library/GetAPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getapen
functions: [SetAPen]
libraries: [graphics.library]
---

# graphics.library/GetAPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       GetAPen -- Get the A Pen value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       pen = GetAPen  ( rp )
```
	 d0		 a0

	ULONG GetAPen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *)

   FUNCTION
	Return the current value of the A pen for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently, for instance, using more bits.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetAPen()](autodocs-3.5/graphics-library-setapen-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
