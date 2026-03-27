---
title: graphics.library/SetRGB32
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-setrgb32
functions: [GetColorMap, GetRGB32, LoadRGB32, SetRGB32CM]
libraries: [graphics.library]
---

# graphics.library/SetRGB32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetRGB32 -- Set one color register for this Viewport. (V39)

   SYNOPSIS
	SetRGB32(  vp,  n,   r,    g,    b)
	           a0  d0   d1    d2    d3

	void SetRGB32( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, ULONG, ULONG, ULONG, ULONG );

   INPUTS
	vp = viewport
	n = the number of the color register to set.
	r = red level   (32 bit left justified fraction)
	g = green level (32 bit left justified fraction)
	b = blue level  (32 bit left justified fraction)

   RESULT
	If there is a [ColorMap](autodocs-3.5/include-graphics-view-h.md) for this viewport, then the value will
	be stored in the [ColorMap](autodocs-3.5/include-graphics-view-h.md).
	The selected color register is changed to match your specs.
	If the color value is unused then nothing will happen.

   BUGS

   NOTES
	Lower order bits of the palette specification will be discarded,
	depending on the color palette resolution of the target graphics
	device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
	etc. You can find out the palette range for your screen by
	querying the graphics data base.

   SEE ALSO
	[GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [GetRGB32()](autodocs-3.5/graphics-library-getrgb32.md) [SetRGB32CM()](autodocs-3.5/graphics-library-setrgb32cm.md) [LoadRGB32()](autodocs-3.5/graphics-library-loadrgb32.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB32 — graphics.library](../autodocs/graphics.library.md#getrgb32)
- [LoadRGB32 — graphics.library](../autodocs/graphics.library.md#loadrgb32)
- [SetRGB32CM — graphics.library](../autodocs/graphics.library.md#setrgb32cm)
