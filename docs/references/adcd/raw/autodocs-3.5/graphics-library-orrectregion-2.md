# graphics.library/OrRectRegion



   NAME 

       OrRectRegion -- Perform 2d OR operation of rectangle
                       with region, leaving result in region.
   SYNOPSIS 

```c
       status = OrRectRegion(region,rectangle)
         d0                    a0      a1
```
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) OrRectRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Rectangle](../Includes_and_Autodocs_3._guide/node05DC.html#line26) * );

   FUNCTION 

       If any portion of rectangle is not in the region then add
       that portion to the region.
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
	[AndRectRegion()](../Includes_and_Autodocs_3._guide/node02A4.html) [OrRegionRegion()](../Includes_and_Autodocs_3._guide/node030B.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

