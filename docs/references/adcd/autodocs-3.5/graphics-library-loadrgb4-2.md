---
title: graphics.library/LoadRGB4
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-loadrgb4-2
functions: [GetColorMap, GetRGB4, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/LoadRGB4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LoadRGB4 -- Load RGB color values from table.

   SYNOPSIS
	LoadRGB4( vp, colors , count )

                 a0  	a1     d0:16
	void LoadRGB4( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) *, WORD);

   FUNCTION
   	load the count words of the colormap from table starting at
	entry 0.

   INPUTS
	vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md), whose colors you wish to change
	colors - pointer to table of RGB values set up as an array
	         of USHORTS
		 	background--  0x0RGB
			color1	  --  0x0RGB
			color2    --  0x0RGB
			 etc.         [UWORD](autodocs-3.5/include-exec-types-h.md) per value.
		The colors are interpreted as 15 = maximum intensity.
		                              0 = minimum intensity.
	count	= number of UWORDs in the table to load into the
	  colormap starting at color 0(background) and proceeding
	  to the next higher color number

   RESULTS
	The [ViewPort](autodocs-3.5/include-graphics-view-h.md) should have a pointer to a valid [ColorMap](autodocs-3.5/include-graphics-view-h.md) to store
	the colors in.
	Updates the hardware copperlist to reflect the new colors.
	Updates the intermediate copperlist with the new colors.

   BUGS

	NOTE: Under V36 and up, it is not safe to call this function
	from an interrupt, due to semaphore protection of graphics
	copper lists.

   SEE ALSO
	[SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md) [GetRGB4()](autodocs-3.5/graphics-library-getrgb4-2.md) [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
