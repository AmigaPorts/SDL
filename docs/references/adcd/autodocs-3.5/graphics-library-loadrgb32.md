---
title: graphics.library/LoadRGB32
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-loadrgb32
functions: [GetColorMap, GetRGB32, LoadRGB4, SetRGB32CM]
libraries: [graphics.library]
---

# graphics.library/LoadRGB32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LoadRGB32 -- Set a series of color registers for this Viewport. (V39)

   SYNOPSIS
	LoadRGB32(  vp,  table )
	            a0   a1

	void LoadRGB32( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, ULONG *);

   INPUTS
	vp = viewport
	table = a pointer to a series of records which describe which colors to
	        modify.
   RESULT
	The selected color registers are changed to match your specs.
   BUGS

   NOTES

	Passing a NULL "table" is ignored.
	The format of the table passed to this function is a series of records,
	each with the following format:

	        1 Word with the number of colors to load
	        1 Word with the first color to be loaded.
	        3 longwords representing a left justified 32 bit rgb triplet.
	        The list is terminated by a count value of 0.

	   examples:
	        ULONG table[]={1l<<16+0,0xffffffff,0,0,0} loads color register
	                0 with 100% red.
	        ULONG table[]={256l<<16+0,r1,g1,b1,r2,g2,b2,.....0} can be used
	                to load an entire 256 color palette.

	Lower order bits of the palette specification will be discarded,
	depending on the color palette resolution of the target graphics
	device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
	etc. You can find out the palette range for your screen by
	querying the graphics data base.

	LoadRGB32 is faster than [SetRGB32](autodocs-3.5/graphics-library-setrgb32.md), even for one color.

   SEE ALSO
	[LoadRGB4()](autodocs-3.5/graphics-library-loadrgb4-2.md) [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [GetRGB32()](autodocs-3.5/graphics-library-getrgb32.md) [SetRGB32CM()](autodocs-3.5/graphics-library-setrgb32cm.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB32 — graphics.library](../autodocs/graphics.library.md#getrgb32)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB32CM — graphics.library](../autodocs/graphics.library.md#setrgb32cm)
