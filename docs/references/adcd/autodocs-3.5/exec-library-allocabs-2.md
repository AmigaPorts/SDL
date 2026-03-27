---
title: exec.library/AllocAbs
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-allocabs-2
functions: [AllocMem, FreeMem]
libraries: [exec.library]
---

# exec.library/AllocAbs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocAbs -- allocate at a given location

   SYNOPSIS
	memoryBlock = AllocAbs(byteSize, location)
	D0		       D0	 A1

	void *AllocAbs(ULONG, APTR);

   FUNCTION
	This function attempts to allocate memory at a given absolute
	memory location.  Often this is used by boot-surviving entities
	such as recoverable ram-disks.	If the memory is already being
	used, or if there is not enough memory to satisfy the request,
	AllocAbs will return NULL.

	This block may not be exactly the same as the requested block
	because of rounding, but if the return value is non-zero, the block
	is guaranteed to contain the requested range.

   INPUTS
	byteSize - the size of the desired block in bytes
		   This number is rounded up to the next larger
		   block size for the actual allocation.
	location - the address where the memory MUST be.


   RESULT
	memoryBlock - a pointer to the newly allocated memory block, or
		      NULL if failed.

   NOTE
	If the free list is corrupt, the system will panic with alert
	AN_MemCorrupt, $01000005.

	The 8 bytes past the end of an AllocAbs will be changed by Exec
	relinking the next block of memory.  Generally you can't trust
	the first 8 bytes of anything you AllocAbs.

   SEE ALSO
	[AllocMem()](autodocs-3.5/exec-library-allocmem-2.md), [FreeMem()](autodocs-3.5/exec-library-freemem-2.md)

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
