# graphics.library/ReadPixelLine8



   NAME
	ReadPixelLine8 -- read the pen number value of a horizontal line
	of pixels starting at a specified x,y location and continuing
	right for count pixels. (V36)

   SYNOPSIS
	count = ReadPixelLine8(rp,xstart,ystart,width,array,temprp)
	D0                     A0 D0:16  D1:16  D2    A2    A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ReadPixelLine8(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43),
	     [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) * );

   FUNCTION
	For each pixel in a rectangular region, combine the bits from each
	of the bit-planes used to describe a particular [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) into the pen
	number selector which that bit combination normally forms for the
	system hardware selection of pixel color.

   INPUTS
	rp    - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	(x,y) - a point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	width - count of horizontal pixels to read
	array - pointer to an array of UBYTEs from which to fetch the pixel data
	        allocate at least (((width+15)>>4)<<4) bytes.
	temprp - temporary rastport (copy of rp with [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) set == NULL,
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
	[ReadPixel()](../Includes_and_Autodocs_3._guide/node0310.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

