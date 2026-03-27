---
title: graphics.library/ReadPixelLine8
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-readpixelline8-2
functions: [ReadPixel]
libraries: [graphics.library]
---

# graphics.library/ReadPixelLine8

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadPixelLine8 -- read the pen number value of a horizontal line
	of pixels starting at a specified x,y location and continuing
	right for count pixels. (V36)

   SYNOPSIS
	count = ReadPixelLine8(rp,xstart,ystart,width,array,temprp)
	D0                     A0 D0:16  D1:16  D2    A2    A1

	[LONG](autodocs-3.5/include-exec-types-h.md) ReadPixelLine8(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md),
	     [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) * );

   FUNCTION
	For each pixel in a rectangular region, combine the bits from each
	of the bit-planes used to describe a particular [RastPort](autodocs-3.5/include-graphics-rastport-h.md) into the pen
	number selector which that bit combination normally forms for the
	system hardware selection of pixel color.

   INPUTS
	rp    - pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	(x,y) - a point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	width - count of horizontal pixels to read
	array - pointer to an array of UBYTEs from which to fetch the pixel data
	        allocate at least (((width+15)>>4)<<4) bytes.
	temprp - temporary rastport (copy of rp with [Layer](autodocs-3.5/include-graphics-clip-h.md) set == NULL,
	         temporary memory allocated for
	         temprp->BitMap with Rows set == 1,
	         temprp->BytesPerRow == (((width+15)>>4)<<1),
	         and temporary memory allocated for
	         temprp->BitMap->Planes[])

   RESULT
	For each pixel in the array:
	    Pen - (0..255) number at that position is returned
	count   - the number of pixels read.

   NOTE
	width must be non negative

   BUGS

   SEE ALSO
	[ReadPixel()](autodocs-3.5/graphics-library-readpixel-2.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
