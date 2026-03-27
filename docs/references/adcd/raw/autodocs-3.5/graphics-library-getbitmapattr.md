# graphics.library/GetBitMapAttr



   NAME
	GetBitMapAttr -- Returns information about a bitmap (V39)


   SYNOPSIS
	value=GetBitMapAttr(bitmap,attribute_number);
	  d0	                 a0       d1

	ULONG GetBitMapAttr(struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *,ULONG);

   FUNCTION
	Determines information about a bitmap. This function should be used
	instead of reading the bitmap structure fields directly. This will
	provide future compatibility.

   INPUTS
	bm  =  A pointer to a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) structure.

	attribute_number = A number telling graphics which attribute
	                   of the bitmap should be returned:

	                BMA_HEIGHT returns the height in pixels
	                BMA_WIDTH  returns the width in pixels.
	                BMA_DEPTH  returns the depth. This is the number of
	                        bits which are required to store the information
	                        for one pixel in the bitmap.
	                BMA_FLAGS  returns a longword bitfield describing
	                        various attributes which the bitmap may have.
	                        Currently defined flags are BMF_DISPLAYABLE,
	                        BMF_INTERLEAVED (see AllocBitMap()). The flag
	                        BMF_STANDARD returns will be set if the
	                        bitmap is represented as planar data in Amiga
	                        Chip RAM.

   BUGS

   NOTES

	Unknown attributes are reserved for future use, and return zero.

	BMF_DISPLAYABLE will only be set if the source bitmap meets all of the
	required alignment restrictions. A bitmap which does not meet these
	restrictions may still be displayable at some loss of efficiency.

	Size values returned by this function may not exactly match the values
	which were passed to [AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html), due to alignment restrictions.

   SEE ALSO
	[AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html)

