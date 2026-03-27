# exec.library/FreeVec



   NAME
	FreeVec -- return [AllocVec()](../Includes_and_Autodocs_3._guide/node01EB.html) memory to the system  (V36)

   SYNOPSIS
	FreeVec(memoryBlock)
		A1

	void FreeVec(void *);

   FUNCTION
	Free an allocation made by the [AllocVec()](../Includes_and_Autodocs_3._guide/node01EB.html) call.  The memory will
	be returned to the system pool from which it came.

   NOTE
	If a block of memory is freed twice, the system will Guru. The
	[Alert](../Includes_and_Autodocs_3._guide/node01E3.html) is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
	you will probably see AN_MemCorrupt $01000005.  Future versions may
	add more sanity checks to the memory lists.

   INPUTS
	memoryBlock - pointer to the memory block to free, or NULL.

   SEE ALSO
	[AllocVec()](../Includes_and_Autodocs_3._guide/node01EB.html)

