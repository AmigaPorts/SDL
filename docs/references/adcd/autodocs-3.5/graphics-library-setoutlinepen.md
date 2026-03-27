---
title: graphics.library/SetOutlinePen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setoutlinepen
functions: []
libraries: []
---

# graphics.library/SetOutlinePen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME


```c
       SetOutlinePen -- Set the Outline Pen value for a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) (V39).
```
   SYNOPSIS
```c
       old_pen=SetOutlinePen  ( rp, pen )
```
	  d0	                 a0   d0

	ULONG SetOutlinePen(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *,ULONG)

   FUNCTION
	Set the current value of the O pen for the rastport and turn on area outline
	mode. This function should be used instead of poking the structure directly,
	because future graphics devices may store it differently, for instance,
	using more bits.

   INPUTS
```c
       rp  =  a pointer to a valid [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure.
```
	pen =  a longword pen number

	returns the previous outline pen
   BUGS

   NOTES

   SEE ALSO
	[GetOPen()](autodocs-3.5/graphics-library-getopen.md) [graphics/gfxmacros.h](autodocs-3.5/include-graphics-gfxmacros-h.md)

