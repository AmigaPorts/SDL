# expansion.library/FreeExpansionMem



   NAME
	FreeExpansionMem - allocate standard device expansion memory

   SYNOPSIS
	FreeExpansionMem( startSlot, numSlots )
	                  D0         D1

   FUNCTION
	(Not typically called by user code)

	This function allocates numslots of expansion space (each slot
	is E_SLOTSIZE bytes).  It is the inverse function of
	[AllocExpansionMem()](../Includes_and_Autodocs_3._guide/node0260.html).

   INPUTS
	startSlot - the slot number that was allocated, or -1 for error.
	numSlots - the number of slots to be freed.

   RESULTS

   EXAMPLES

   EXCEPTIONS
	If the caller tries to free a slot that is already in the
	free list, FreeExpansionMem will [Alert()](../Includes_and_Autodocs_3._guide/node01E3.html) (e.g. crash the
	system).

   SEE ALSO
	[AllocExpansionMem()](../Includes_and_Autodocs_3._guide/node0260.html)

   BUGS

