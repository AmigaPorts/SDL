# graphics.library/ClearRegion



   NAME 

```c
       ClearRegion -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) all rectangles from region.
```
   SYNOPSIS 

```c
       ClearRegion(region)
                     a0
```
	viod ClearRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) * );

   FUNCTION 

       Clip away all rectangles in the region leaving nothing.
   INPUTS 

```c
       region - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
```
   BUGS 

   SEE ALSO
	[NewRegion()](../Includes_and_Autodocs_3._guide/node0304.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

