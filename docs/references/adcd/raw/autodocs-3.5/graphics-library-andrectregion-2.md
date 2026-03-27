# graphics.library/AndRectRegion



   NAME
	AndRectRegion -- Perform 2d AND operation of rectangle
			 with region, leaving result in region.

   SYNOPSIS
	AndRectRegion(region,rectangle)
 			a0	a1

	void AndRectRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) * );

   FUNCTION
	Clip away any portion of the region that exists outside
	of the rectangle. Leave the result in region.

   INPUTS
	region - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
	rectangle - pointer to [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) structure

   NOTES
	Unlike the other rect-region primitives, AndRectRegion() cannot
	fail.

   BUGS

   SEE ALSO
	[AndRegionRegion()](../Includes_and_Autodocs_3._guide/node02A5.html) [OrRectRegion()](../Includes_and_Autodocs_3._guide/node030A.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

