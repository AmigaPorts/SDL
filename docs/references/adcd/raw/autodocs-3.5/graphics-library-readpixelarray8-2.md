# graphics.library/ReadPixelArray8



   NAME
	ReadPixelArray8 -- read the pen number value of a rectangular array
	of pixels starting at a specified x,y location and continuing
	through to another x,y location within a certain [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53). (V36)

   SYNOPSIS
	count = ReadPixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
	D0                      A0 D0:16  D1:16  D2:16 D3:16 A2    A1

```c
     [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ReadPixelArray8(struct  [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43),
```
	   [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	For each pixel in a rectangular region, combine the bits from each
	of the bit-planes used to describe a particular [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) into the pen
	number selector which that bit combination normally forms for the
	system hardware selection of pixel color.

   INPUTS
	rp    -  pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	(xstart,ystart) - starting point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	(xstop,ystop)   - stopping point in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	array - pointer to an array of UBYTEs from which to fetch the pixel data
	        allocate at least ((((width+15)>>4)<<4)*(ystop-ystart+1)) bytes.
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
	xstop must be >= xstart
	ystop must be >= ystart

   BUGS

   SEE ALSO
	[ReadPixel()](../Includes_and_Autodocs_3._guide/node0310.html)  [ReadPixelLine8()](../Includes_and_Autodocs_3._guide/node0312.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

