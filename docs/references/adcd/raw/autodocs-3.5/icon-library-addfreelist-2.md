# icon.library/AddFreeList



   NAME
	AddFreeList - add memory to a free list.

   SYNOPSIS
	status = AddFreeList(free, mem, len)
	  D0                  A0    A1   A2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AddFreeList(struct [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG);

   FUNCTION
	This routine adds the specified memory to the free list.
	The free list will be extended (if required).  If there
	is not enough memory to complete the call, NULL is returned.

	Note that AddFreeList() does NOT allocate the requested memory.
	It only records the memory in the free list.

   INPUTS
	free -- a pointer to a [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) structure
	mem -- the base of the memory to be recorded
	len -- the length of the memory to be recorded

   RESULTS
	status -- TRUE if the call succeeded else FALSE;

   SEE ALSO
	[exec.library/AllocEntry](../Includes_and_Autodocs_3._guide/node01E6.html)
	[exec.library/FreeEntry](../Includes_and_Autodocs_3._guide/node020D.html)
	[icon.library/FreeFreeList](../Includes_and_Autodocs_3._guide/node034B.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)

