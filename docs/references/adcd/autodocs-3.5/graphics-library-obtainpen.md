---
title: graphics.library/ObtainPen
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-obtainpen
functions: [AttachPalExtra, GetColorMap, ObtainBestPenA, ReleasePen]
libraries: [graphics.library]
---

# graphics.library/ObtainPen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainPen -- Obtain a free palette entry for use by your program. (V39)


   SYNOPSIS
	n = ObtainPen( cm, n, r, g, b, flags)
	d0	       a0 d0  d1 d2 d3  d4

	[LONG](autodocs-3.5/include-exec-types-h.md) ObtainPen(struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *,ULONG,ULONG,ULONG,ULONG,ULONG);

   FUNCTION
	Attempt to allocate an entry in the colormap for use by the application.
	If successful, you should [ReleasePen()](autodocs-3.5/graphics-library-releasepen.md) this entry after you have finished
	with it.

	Applications needing exclusive use of a color register (say for color
	cycling) will typically call this function with n=-1. Applications needing
	only the shared use of a color will typically use [ObtainBestPenA()](autodocs-3.5/graphics-library-obtainbestpena.md) instead.
	Other uses of this function are rare.

   INPUTS
	cm  =  A pointer to a color map created by [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md).
	n   =  The index of the desired entry, or -1 if any one is acceptable
	rgb =  The RGB values (32 bit left justified fractions) to set the new
	       palette entry to.
	flags= PEN_EXCLUSIVE - tells the system that you want exclusive
	       (non-shared) use of this pen value. Default is shared access.

	       PEN_NO_SETCOLOR - tells the system to not change the rgb values
	       for the selected pen. Really only makes sense for exclusive pens.


   RESULTS

	n   =  The allocated pen. -1 will be returned if there is no pen available
	       for you.

   BUGS

   NOTES
	When you allocate a palette entry in non-exclusive mode, you
	should not change it (via SetRGB32), because other programs on the
	same screen may be using it. With PEN_EXCLUSIVE mode, you can
	change the returned entry at will.

	To avoid visual artifacts, you should not free up a palette
	entry until you are sure that your application is not displaying
	any pixels in that color at the time you free it. Otherwise, another
	task could allocate and set that color index, thus changing the colors
	of your pixels.

	Generally, for shared access, you should use [ObtainBestPenA()](autodocs-3.5/graphics-library-obtainbestpena.md)
	instead, since it will not allocate a new color if there is one
	"close enough" to the one you want already.
	If there is no Palextra attached to the colormap, then this
	routine will always fail.

   SEE ALSO
	[GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [ReleasePen()](autodocs-3.5/graphics-library-releasepen.md) [AttachPalExtra()](autodocs-3.5/graphics-library-attachpalextra.md) [ObtainBestPenA()](autodocs-3.5/graphics-library-obtainbestpena.md)

---

## See Also

- [AttachPalExtra — graphics.library](../autodocs/graphics.library.md#attachpalextra)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [ObtainBestPenA — graphics.library](../autodocs/graphics.library.md#obtainbestpena)
- [ReleasePen — graphics.library](../autodocs/graphics.library.md#releasepen)
