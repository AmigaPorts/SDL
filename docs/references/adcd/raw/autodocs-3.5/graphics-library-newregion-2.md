# graphics.library/NewRegion



   NAME 

       NewRegion -- Get an empty region.
   SYNOPSIS 
```c
       region = NewRegion()
```
	d0

	struct [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) *NewRegion();

   FUNCTION 
	Create a [Region](../Includes_and_Autodocs_3._guide/node0642.html#line26) structure, initialize it to empty, and return
	a pointer it.

   RESULTS
	region - pointer to initialized region. If it could not allocate
		required memory region = NULL.

   INPUTS 
	none

   BUGS 

   SEE ALSO
	[graphics/regions.h](../Includes_and_Autodocs_3._guide/node0642.html)

