# graphics.library/DisposeRegion



   NAME
       DisposeRegion -- Return all space for this region to free
			 memory pool.

   SYNOPSIS

```c
       DisposeRegion(region)
                      a0
```
	void DisposeRegion( struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) * );

   FUNCTION
```c
       Free all RegionRectangles for this [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) then
```
	free the [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) itself.

   INPUTS

```c
       region - pointer to [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure
```
   BUGS

   SEE ALSO
	[NewRegion()](../Includes_and_Autodocs_3._guide/node0304.html) [graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

