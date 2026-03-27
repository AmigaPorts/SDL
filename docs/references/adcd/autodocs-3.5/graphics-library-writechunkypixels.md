---
title: graphics.library/WriteChunkyPixels
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-writechunkypixels
functions: [OwnBlitter, WritePixel]
libraries: [graphics.library]
---

# graphics.library/WriteChunkyPixels

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WriteChunkyPixels -- write the pen number value of a rectangular array
	of pixels starting at a specified x,y location and continuing
	through to another x,y location within a certain [RastPort](autodocs-3.5/include-graphics-rastport-h.md). (V40)

   SYNOPSIS
	WriteChunkyPixels(rp,xstart,ystart,xstop,ystop,array,bytesperrow)
	                  A0 D0     D1     D2    D3    A2     D4

	VOID WriteChunkyPixels(struct  [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md),
	     [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [UBYTE](autodocs-3.5/include-exec-types-h.md) *, LONG);

   FUNCTION
	For each pixel in a rectangular region, decode the pen number selector
	from a linear array of pen numbers into the bit-planes used to describe
	a particular rastport.

   INPUTS
	rp     -  pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) structure
	(xstart,ystart) -  starting point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	(xstop,ystop)   -  stopping point in the [RastPort](autodocs-3.5/include-graphics-rastport-h.md)
	array  - pointer to an array of UBYTEs from which to fetch the
	         pixel data.
	bytesperrow - The number of bytes per row in the source array.
		This should be at least as large as the number of pixels
		being written per line.

   RESULT

   NOTE
	xstop must be >= xstart
	ystop must be >= ystart
	The source array can be in fast RAM.

   ===chunky-to-planar conversion HW:

   GfxBase->ChunkyToPlanarPtr is either NULL, or a pointer to a HW
   register used to aid in the process of converting 8-bit chunky 
   pixel data into the bit-plane format used by the Amiga custom
   display chips. If NULL, then such hardware is not present.

   If an expansion device provides hardware which operates compatibly,
   than it can install the HW address into this pointer at boot time,
   and the system will use it.

   This pointer may be used for direct access to the chunky-to-planar
   conversion HW, if more is desired than the straight chunky-pixel
   copy that is performed by WriteChunkyPixels().

   If using the hardware directly, it should only be accessed when
   the task using it has control of the blitter (via [OwnBlitter()](autodocs-3.5/graphics-library-ownblitter-2.md)),
   since this is the locking used to arbitrate usage of this device.

   The hardware may be viewed as a device which accepts 32 8-bit
   chunky pixels and outputs 8 longwords of bitplane data.

   For proper operation, exactly 8 longwords (containing 32 pixels)
   of chunky data should be written to *(GfxBase->ChunkyToPlanarPtr).
   After the data is written, bitplane data (starting with plane 0)
   can be read back a longword at a time. There is no need to read
   back all 8 longwords if the high-order bitplanes are not needed.

   Since WriteChunkyPixels is not (currently) particularly fast on 
   systems without the chunky-to-planar hardware, time critical
   applications (games, etc) may want to use their own custom conversion
   routine if GfxBase->ChunkyToPlanarPtr is NULL, and call
   WriteChunkyPixels() otherwise.

   This pointer is only present in [GfxBase](autodocs-3.5/include-graphics-gfxbase-h.md) in versions of graphics.library
   >= 40, so this should be checked before the pointer is read.

   BUGS
	Not very fast on systems without chunky-to-planar conversion
	hardware.

   SEE ALSO
	[WritePixel()](autodocs-3.5/graphics-library-writepixel-2.md)  [graphics/rastport.h](autodocs-3.5/include-graphics-rastport-h.md)

---

## See Also

- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
