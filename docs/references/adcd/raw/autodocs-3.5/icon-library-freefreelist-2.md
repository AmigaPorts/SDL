# icon.library/FreeFreeList



   NAME
	FreeFreeList - free all memory in a free list.

   SYNOPSIS
	FreeFreeList(free)
	             A0

	void FreeFreeList(struct [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) *);

   FUNCTION
	This routine frees all memory in a free list, and the
	free list itself.  It is useful for easily getting
	rid of all memory in a series of structures.  There is
	a free list in a Workbench object, and this contains
	all the memory associated with that object.

	A [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) is a list of [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) structures.  See the
	[MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) and [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39) documentation for more information.

	If the [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) itself is in the free list, it must be
	in the first [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) in the [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85).

   INPUTS
	free -- a pointer to a [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) structure; as of V44
	    a NULL free parameter will be ignored.

   SEE ALSO
	[exec.library/AllocEntry](../Includes_and_Autodocs_3._guide/node01E6.html)
	[exec.library/FreeEntry](../Includes_and_Autodocs_3._guide/node020D.html)
	[icon.library/AddFreeList](../Includes_and_Autodocs_3._guide/node0343.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)

