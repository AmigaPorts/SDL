# graphics.library/WritePixelArray8



   NAME
	WritePixelArray8 -- write the pen number value of a rectangular array
	of pixels starting at a specified x,y location and continuing
	through to another x,y location within a certain [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53). (V36)

   SYNOPSIS
	count = WritePixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
	D0                       A0 D0:16  D1:16  D2:16 D3:16  A2   A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WritePixelArray8(struct  [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43),
	     [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct  [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	For each pixel in a rectangular region, decode the pen number selector
	from a linear array of pen numbers into the bit-planes used to describe
	a particular rastport.

   INPUTS
	rp     -  pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	(xstart,ystart) -  starting point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	(xstop,ystop)   -  stopping point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	array  - pointer to an array of UBYTEs from which to fetch the
	         pixel data. [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) at least
	         ((((width+15)>>4)<<4)*(ystop-ystart+1)) bytes.
	temprp - temporary rastport (copy of rp with [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) set == NULL,
	         temporary memory allocated for
	         temprp->BitMap with Rows set == 1,
	         temprp->BitMap with BytesPerRow == (((width+15)>>4)<<1),
	         and temporary memory allocated for
	         temprp->BitMap->Planes[])

   RESULT
	count will be set to the number of pixels plotted.

   NOTE
	xstop must be >= xstart
	ystop must be >= ystart

   BUGS

   SEE ALSO
	[WritePixel()](../Includes_and_Autodocs_3._guide/node033D.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

