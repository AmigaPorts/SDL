---
title: exec.library/Deallocate
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-deallocate-2
functions: [Allocate]
libraries: [exec.library]
---

# exec.library/Deallocate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Deallocate -- deallocate a block of memory

   SYNOPSIS
	Deallocate(memHeader, memoryBlock, byteSize)
		   A0	      A1	   D0

	void Deallocate(struct [MemHeader](autodocs-3.5/include-exec-memory-h.md) *,[APTR](autodocs-3.5/include-exec-types-h.md),ULONG);

   FUNCTION
	This function deallocates memory by returning it to the appropriate
	private free memory pool.  This function can be used to free an
	entire block allocated with the above function, or it can be used
	to free a sub-block of a previously allocated block.  Sub-blocks
	must be an even multiple of the memory chunk size (currently 8
	bytes).

	This function can even be used to add a new free region to an
	existing [MemHeader](autodocs-3.5/include-exec-memory-h.md), however the extent pointers in the [MemHeader](autodocs-3.5/include-exec-memory-h.md)
	will no longer be valid.

	If memoryBlock is not on a block boundary (MEM_BLOCKSIZE) then it
	will be rounded down in a manner compatible with [Allocate()](autodocs-3.5/exec-library-allocate-2.md).  Note
	that this will work correctly with all the memory allocation
	functions, but may cause surprises if one is freeing only part of a
	region.  The size of the block will be rounded up, so the freed
	block will fill to an even memory block boundary.

   INPUTS
	memHeader - points to the memory header this block is part of.
	memoryBlock - address of memory block to free.
	byteSize - the size of the block in bytes. If NULL, nothing
		   happens.

   SEE ALSO
	[Allocate()](autodocs-3.5/exec-library-allocate-2.md), [exec/memory.h](autodocs-3.5/include-exec-memory-h.md)

---

## See Also

- [Allocate — exec.library](../autodocs/exec.library.md#allocate)
