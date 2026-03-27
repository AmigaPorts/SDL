# exec.library/AddMemList



   NAME
	AddMemList - add memory to the system free pool

   SYNOPSIS
	AddMemList( size, attributes, pri, base, name )

                     D0      D1        D2   A0    A1
	void AddMemList(ULONG, ULONG, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), STRPTR);

   FUNCTION
	Add a new region of memory to the system free pool.  The first few
	bytes will be used to hold the [MemHeader](../Includes_and_Autodocs_3._guide/node062D.html#line27) structure.  The remainder
	will be made available to the rest of the world.

   INPUTS
	size - the size (in bytes) of the memory area
	attributes - the attributes word that the memory pool will have
	pri  - the priority for this memory.  CHIP memory has a pri of -10,
	       16 bit expansion memory has a priority of 0.  The higher the
	       priority, the closer to the head of the memory list it will
	       be placed.
	base - the base of the new memory area
	name - the name that will be used in the memory header, or NULL
	       if no name is to be provided.  This name is not copied, so it
	       must remain valid for as long as the memory header is in the
	       system.

   NOTES
	*DO NOT* add memory to the system with the attribute of MEMF_KICK.
	EXEC will mark your memory as such if it is of the right type.

   SEE ALSO
	[AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html), [exec/memory.h](../Includes_and_Autodocs_3._guide/node062D.html)

