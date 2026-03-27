# graphics.library/WritePixelLine8



   NAME
	WritePixelLine8 -- write the pen number value of a horizontal line
	of pixels starting at a specified x,y location and continuing
	right for count pixels. (V36)

   SYNOPSIS
	count = WritePixelLine8(rp,xstart,ystart,width,array,temprp)
	D0                      A0 D0:16  D1:16  D2    A2    A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WritePixelLine8(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43),
	     [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	For each pixel in a horizontal region, decode the pen number selector
	from a linear array of pen numbers into the bit-planes used to describe
	a particular rastport.

   INPUTS
	rp    -  pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	(x,y) - a point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	width - count of horizontal pixels to write
	array - pointer to an array of UBYTEs from which to fetch the pixel data
	        allocate at least (((width+15)>>4)<<4) bytes.
	temprp - temporary rastport (copy of rp with [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) set == NULL,
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
	[WritePixel()](../Includes_and_Autodocs_3._guide/node033D.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

