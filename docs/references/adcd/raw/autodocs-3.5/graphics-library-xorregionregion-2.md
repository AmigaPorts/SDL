# graphics.library/XorRegionRegion



   NAME 

       XorRegionRegion -- Perform 2d XOR operation of one region
                       with second region, leaving result in second region
   SYNOPSIS 

```c
       status = XorRegionRegion(region1,region2)
         d0                        a0      a1
```
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) XorRegionRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) * );

   FUNCTION 
	Join the regions together. If any part of region1 overlaps
	region2 then remove that from the new region.

   INPUTS 

```c
       region1      = pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
       region2      = pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS 

