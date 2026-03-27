# graphics.library/OrRegionRegion



   NAME 

       OrRegionRegion -- Perform 2d OR operation of one region
                       with second region, leaving result in second region
   SYNOPSIS 

```c
       status = OrRegionRegion(region1,region2)
         d0                       a0      a1
```
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) OrRegionRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) * );

   FUNCTION 

       If any portion of region1  is not in the region then add
       that portion to the region2
   INPUTS 

```c
       region1 - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
       region2 - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS 

   SEE ALSO
 	[OrRectRegion()](../Includes_and_Autodocs_3._guide/node030A.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

