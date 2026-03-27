---
title: graphics.library/AllocRaster
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-allocraster-2
functions: [AllocBitMap, FreeRaster]
libraries: [graphics.library]
---

# graphics.library/AllocRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocRaster -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) space for a bitplane.

   SYNOPSIS
	planeptr = AllocRaster( width, height )
	   d0                    d0     d1

	[PLANEPTR](autodocs-3.5/include-graphics-gfx-h.md) AllocRaster(ULONG,ULONG);

   FUNCTION
	This function calls the memory allocation routines
	to allocate memory space for a bitplane "width" bits
	wide and "height" bits high.

   INPUTS
	width	- number of columns in bitplane
	height	- number of rows in bitplane

   RESULT
	planeptr - pointer to first word in bitplane, or NULL if
		   it was not possible to allocate the desired
		   amount of memory.

   NOTES
	In order to assure proper alignment of display memory, the
	[AllocBitMap()](autodocs-3.5/graphics-library-allocbitmap.md) function should be used instead of AllocRaster
	when you wish to allocate display memory (rasters which are
	attached to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) or Screen).

   BUGS

   SEE ALSO
	[FreeRaster()](autodocs-3.5/graphics-library-freeraster-2.md) [graphics/gfx.h](autodocs-3.5/include-graphics-gfx-h.md)

---

## See Also

- [AllocBitMap — graphics.library](../autodocs/graphics.library.md#allocbitmap)
- [FreeRaster — graphics.library](../autodocs/graphics.library.md#freeraster)
