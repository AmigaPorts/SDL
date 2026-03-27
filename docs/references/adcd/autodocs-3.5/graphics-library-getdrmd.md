---
title: graphics.library/GetDrMd
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getdrmd
functions: [SetDrMd]
libraries: [graphics.library]
---

# graphics.library/GetDrMd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       GetDrMd -- Get the draw mode value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       mode = GetDrMd  ( rp )
```
	d0                a0

	ULONG GetDrMd(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *)

   FUNCTION
	Return the current value of the draw mode for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetDrMd()](autodocs-3.5/graphics-library-setdrmd-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [SetDrMd — graphics.library](../autodocs/graphics.library.md#setdrmd)
