---
title: exec.library/AllocVec
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-allocvec-2
functions: [AllocMem, FreeVec]
libraries: [exec.library]
---

# exec.library/AllocVec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocVec -- allocate memory and keep track of the size  (V36)

   SYNOPSIS
	memoryBlock = AllocVec(byteSize, attributes)
	D0		       D0	 D1

	void *AllocVec(ULONG, ULONG);

   FUNCTION
	This function works identically to [AllocMem()](autodocs-3.5/exec-library-allocmem-2.md), but tracks the size
	of the allocation.

	See the [AllocMem()](autodocs-3.5/exec-library-allocmem-2.md) documentation for details.

   WARNING
	The result of any memory allocation MUST be checked, and a viable
	error handling path taken.  ANY allocation may fail if memory has
	been filled.

   SEE ALSO
	[FreeVec()](autodocs-3.5/exec-library-freevec-2.md), [AllocMem()](autodocs-3.5/exec-library-allocmem-2.md)

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [FreeVec — exec.library](../autodocs/exec.library.md#freevec)
