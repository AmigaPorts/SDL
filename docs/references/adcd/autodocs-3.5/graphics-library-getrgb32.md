---
title: graphics.library/GetRGB32
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getrgb32
functions: [GetColorMap, LoadRGB32, LoadRGB4, SetRGB32CM]
libraries: [graphics.library]
---

# graphics.library/GetRGB32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetRGB32 -- Set a series of color registers for this Viewport. (V39)

   SYNOPSIS
	GetRGB32(  cm,  firstcolor, ncolors, table )
	           a0   d0   		d1    a1


```c
       void GetRGB32( struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, ULONG, ULONG, ULONG *);
```
   INPUTS
	cm = colormap
	firstcolor = the first color register to get
	ncolors = the number of color registers to set.
	table=a pointer to a series of 32-bit RGB triplets.

   RESULT
	The ULONG data pointed to by 'table' will be filled with the 32 bit
	fractional RGB values from the colormap.
   BUGS

   NOTES
	'Table' should point to at least ncolors*3 longwords.

   SEE ALSO
	[LoadRGB4()](autodocs-3.5/graphics-library-loadrgb4-2.md) [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [LoadRGB32()](autodocs-3.5/graphics-library-loadrgb32.md) [SetRGB32CM()](autodocs-3.5/graphics-library-setrgb32cm.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [LoadRGB32 — graphics.library](../autodocs/graphics.library.md#loadrgb32)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB32CM — graphics.library](../autodocs/graphics.library.md#setrgb32cm)
