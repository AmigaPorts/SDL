# exec.library/FreeEntry



   NAME
	FreeEntry -- free many regions of memory

   SYNOPSIS
	FreeEntry(memList)
		  A0
	void FreeEntry(struct [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) *);

   FUNCTION
	This function takes a memList structure (as returned by AllocEntry)
	and frees all the entries.

   INPUTS
	memList -- pointer to structure filled in with [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39)
		   structures

   SEE ALSO
	[AllocEntry()](../Includes_and_Autodocs_3._guide/node01E6.html)

