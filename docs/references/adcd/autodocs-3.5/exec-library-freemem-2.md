---
title: exec.library/FreeMem
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-freemem-2
functions: [AllocMem]
libraries: [exec.library]
---

# exec.library/FreeMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeMem -- deallocate with knowledge

   SYNOPSIS
	FreeMem(memoryBlock, byteSize)
		A1	     D0

	void FreeMem(void *,ULONG);

   FUNCTION
	Free a region of memory, returning it to the system pool from which
	it came.  Freeing partial blocks back into the system pool is
	unwise.

   NOTE
	If a block of memory is freed twice, the system will Guru. The
	[Alert](autodocs-3.5/exec-library-alert-2.md) is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
	you will probably see AN_MemCorrupt $01000005.  Future versions may
	add more sanity checks to the memory lists.

   INPUTS
	memoryBlock - pointer to the memory block to free
	byteSize - the size of the desired block in bytes.  (The operating
		system will automatically round this number to a multiple of
		the system memory chunk size)

   SEE ALSO
	[AllocMem()](autodocs-3.5/exec-library-allocmem-2.md)

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
