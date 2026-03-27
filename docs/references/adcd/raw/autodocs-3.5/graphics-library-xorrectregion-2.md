# graphics.library/XorRectRegion



   NAME

       XorRectRegion -- Perform 2d XOR operation of rectangle
                       with region, leaving result in region
   SYNOPSIS

```c
       status = XorRectRegion(region,rectangle)
         d0                     a0      a1
```
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) XorRectRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) * );

   FUNCTION
	Add portions of rectangle to region if they are not in
	the region.
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) portions of rectangle from region if they are
	in the region.

   INPUTS

```c
       region - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
       rectangle - pointer to [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) structure
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS

   SEE ALSO
	[OrRegionRegion()](../Includes_and_Autodocs_3._guide/node030B.html) [AndRegionRegion()](../Includes_and_Autodocs_3._guide/node02A5.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

