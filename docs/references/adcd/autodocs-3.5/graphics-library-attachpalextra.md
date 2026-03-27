---
title: graphics.library/AttachPalExtra
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-attachpalextra
functions: [FreeColorMap, GetColorMap, ObtainBestPenA, ObtainPen]
libraries: [graphics.library]
---

# graphics.library/AttachPalExtra

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       AttachPalExtra -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) and attach a palette sharing structure to a
```
	                  colormap. (V39)


   SYNOPSIS
```c
       status=AttachPalExtra( cm, vp)
```
	                       a0  a1

	[LONG](autodocs-3.5/include-exec-types-h.md) AttachPalExtra( Struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *, struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	Allocates and attaches a PalExtra structure to a [ColorMap](autodocs-3.5/include-graphics-view-h.md).
	This is necessary for color palette sharing to work. The
	PalExtra structure will be freed by [FreeColorMap()](autodocs-3.5/graphics-library-freecolormap-2.md).
	The set of available colors will be determined by the mode
	and depth of the viewport.

   INPUTS
	cm  =  A pointer to a color map created by [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md).

	vp   = A pointer to the viewport structure associated with
	       the [ColorMap](autodocs-3.5/include-graphics-view-h.md).

   RESULTS
	status - 0 if sucessful, else an error number. The only currently
	         defined error number is out of memory (1).

   BUGS

   NOTES
	This function is for use with custom ViewPorts and custom ColorMaps,
	as Intuition attaches a PalExtra to all of its Screens.
	If there is already a PalExtra associated with the [ColorMap](autodocs-3.5/include-graphics-view-h.md), then
	this function will do nothing.

   SEE ALSO
	[GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [FreeColorMap()](autodocs-3.5/graphics-library-freecolormap-2.md) [ObtainPen()](autodocs-3.5/graphics-library-obtainpen.md) [ObtainBestPenA()](autodocs-3.5/graphics-library-obtainbestpena.md)

---

## See Also

- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [ObtainBestPenA — graphics.library](../autodocs/graphics.library.md#obtainbestpena)
- [ObtainPen — graphics.library](../autodocs/graphics.library.md#obtainpen)
