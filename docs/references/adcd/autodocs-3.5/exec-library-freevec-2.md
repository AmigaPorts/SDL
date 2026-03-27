---
title: exec.library/FreeVec
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-freevec-2
functions: [AllocVec]
libraries: [exec.library]
---

# exec.library/FreeVec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeVec -- return [AllocVec()](autodocs-3.5/exec-library-allocvec-2.md) memory to the system  (V36)

   SYNOPSIS
	FreeVec(memoryBlock)
		A1

	void FreeVec(void *);

   FUNCTION
	Free an allocation made by the [AllocVec()](autodocs-3.5/exec-library-allocvec-2.md) call.  The memory will
	be returned to the system pool from which it came.

   NOTE
	If a block of memory is freed twice, the system will Guru. The
	[Alert](autodocs-3.5/exec-library-alert-2.md) is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
	you will probably see AN_MemCorrupt $01000005.  Future versions may
	add more sanity checks to the memory lists.

   INPUTS
	memoryBlock - pointer to the memory block to free, or NULL.

   SEE ALSO
	[AllocVec()](autodocs-3.5/exec-library-allocvec-2.md)

---

## See Also

- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
