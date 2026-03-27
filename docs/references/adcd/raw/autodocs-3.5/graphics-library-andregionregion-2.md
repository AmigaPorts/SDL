# graphics.library/AndRegionRegion



   NAME 

       AndRegionRegion -- Perform 2d AND operation of one region
                       with second region, leaving result in second region.
   SYNOPSIS 

```c
       status = AndRegionRegion(region1,region2)
          d0                       a0      a1
```
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AndregionRegion(struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *, struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) * );

   FUNCTION 

```c
       [Remove](../Includes_and_Autodocs_3._guide/node022F.html) any portion of region2 that is not in region1.
```
   INPUTS 

```c
       region1 - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
       region2 - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure to use and for result
```
   RESULTS
	status - return TRUE if successful operation
		 return FALSE if ran out of memory

   BUGS 

   SEE ALSO
	[OrRegionRegion()](../Includes_and_Autodocs_3._guide/node030B.html) [AndRectRegion()](../Includes_and_Autodocs_3._guide/node02A4.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

