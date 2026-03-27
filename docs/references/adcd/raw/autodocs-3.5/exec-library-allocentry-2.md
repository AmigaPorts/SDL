# exec.library/AllocEntry



   NAME
	AllocEntry -- allocate many regions of memory

   SYNOPSIS
	memList = AllocEntry(memList)
	D0		     A0

	struct [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) *AllocEntry(struct [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) *);

   FUNCTION
	This function takes a memList structure and allocates enough memory
	to hold the required memory as well as a [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) structure to keep
	track of it.

	These [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) structures may be linked together in a task control
	block to keep track of the total memory usage of this task. (See
	the description of TC_MEMENTRY under RemTask).

   INPUTS
	memList -- A [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) structure filled in with [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39) structures.

   RESULTS
	memList -- A different [MemList](../Includes_and_Autodocs_3._guide/node062D.html#line55) filled in with the actual memory
	    allocated in the me_Addr field, and their sizes in me_Length.
	    If enough memory cannot be obtained, then the requirements of
	    the allocation that failed is returned and bit 31 is set.

	    WARNING: The result is unusual!  Bit 31 indicates failure.

   EXAMPLES
	The user wants five regions of 2, 4, 8, 16, and 32 bytes in size
	with requirements of MEMF_CLEAR, MEMF_PUBLIC, MEMF_CHIP!MEMF_CLEAR,
	MEMF_CLEAR, and MEMF_PUBLIC!MEMF_CLEAR respectively.  The
	following code fragment would do that:

	    MemListDecl:
		DS.B	LN_SIZE 	    * reserve space for list node
		DC.W	5		    * number of entries
		DC.L	MEMF_CLEAR		    * entry #0
		DC.L	2
		DC.L	MEMF_PUBLIC		    * entry #1
		DC.L	4
		DC.L	MEMF_CHIP!MEMF_CLEAR	    * entry #2
		DC.L	8
		DC.L	MEMF_CLEAR	   	    * entry #3
		DC.L	16
		DC.L	MEMF_PUBLIC!MEMF_CLEAR	    * entry #4
		DC.L	32

	    start:
		LEA.L	MemListDecl(PC),A0
		JSR	_LVOAllocEntry(a6)
		BCLR.L	#31,D0
		BEQ.S	success

		------- Type of memory that we failed on is in D0

   BUGS
	If any one of the allocations fails, this function fails to back
	out fully.  This is fixed by the "SetPatch" program on V1.3
	Workbench disks.

   SEE ALSO
	[exec/memory.h](../Includes_and_Autodocs_3._guide/node062D.html)

