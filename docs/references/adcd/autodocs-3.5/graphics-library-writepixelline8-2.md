---
title: graphics.library/WritePixelLine8
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-writepixelline8-2
functions: [WritePixel]
libraries: [graphics.library]
---

# graphics.library/WritePixelLine8

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WritePixelLine8 -- write the pen number value of a horizontal line
	of pixels starting at a specified x,y location and continuing
	right for count pixels. (V36)

   SYNOPSIS
	count = WritePixelLine8(rp,xstart,ystart,width,array,temprp)
	D0                      A0 D0:16  D1:16  D2    A2    A1

	[LONG](autodocs-3.5/include-exec-types-h.md) WritePixelLine8(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md),
	     [UWORD](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *);

   FUNCTION
	For each pixel in a horizontal region, decode the pen number selector
	from a linear array of pen numbers into the bit-planes used to describe
	a particular rastport.

   INPUTS
	rp    -  pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	(x,y) - a point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	width - count of horizontal pixels to write
	array - pointer to an array of UBYTEs from which to fetch the pixel data
	        allocate at least (((width+15)>>4)<<4) bytes.
	temprp - temporary rastport (copy of rp with [Layer](autodocs-3.5/include-graphics-clip-h.md) set == NULL,
	         temporary memory allocated for
	         temprp->BitMap with Rows set == 1,
	         temprp->BitMap BytesPerRow == (((width+15)>>4)<<1),
	         and temporary memory allocated for
	         temprp->BitMap->Planes[])

   RESULT
	Count will be set to the number of pixels plotted

   NOTE
	width must be non negative

   BUGS

   SEE ALSO
	[WritePixel()](autodocs-3.5/graphics-library-writepixel-2.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
