# graphics.library/FreeCopList



   NAME
	FreeCopList -- deallocate intermediate copper list

   SYNOPSIS
```c
       FreeCopList(coplist)
```
		      a0

	void FreeCopList( struct [CopList](../Includes_and_Autodocs_3._guide/node05F3.html#line61) *);

   FUNCTION
	[Deallocate](../Includes_and_Autodocs_3._guide/node01FE.html) all memory associated with this copper list.

   INPUTS

```c
       coplist	- pointer to structure [CopList](../Includes_and_Autodocs_3._guide/node05F3.html#line61)
```
   RESULTS
	memory returned to memory manager

   BUGS

   SEE ALSO
	[graphics/copper.h](../Includes_and_Autodocs_3._guide/node05F3.html)

