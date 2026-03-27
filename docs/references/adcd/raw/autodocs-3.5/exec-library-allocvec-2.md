# exec.library/AllocVec



   NAME
	AllocVec -- allocate memory and keep track of the size  (V36)

   SYNOPSIS
	memoryBlock = AllocVec(byteSize, attributes)
	D0		       D0	 D1

	void *AllocVec(ULONG, ULONG);

   FUNCTION
	This function works identically to [AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html), but tracks the size
	of the allocation.

	See the [AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html) documentation for details.

   WARNING
	The result of any memory allocation MUST be checked, and a viable
	error handling path taken.  ANY allocation may fail if memory has
	been filled.

   SEE ALSO
	[FreeVec()](../Includes_and_Autodocs_3._guide/node0212.html), [AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html)

