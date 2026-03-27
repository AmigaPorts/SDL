# graphics.library/ClearRectRegion



   NAME
	ClearRectRegion -- Perform 2d CLEAR operation of rectangle
			with region, leaving result in region.

   SYNOPSIS
	status = ClearRectRegion(region,rectangle)
	 d0	 	 	  a0 	  a1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ClearRectRegion(struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) * );

   FUNCTION
	Clip away any portion of the region that exists inside
	of the rectangle. Leave the result in region.

   INPUTS
	region - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
	rectangle - pointer to [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) structure

   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS

   SEE ALSO
	[AndRectRegion()](../Includes_and_Autodocs_3._guide/node02A4.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

