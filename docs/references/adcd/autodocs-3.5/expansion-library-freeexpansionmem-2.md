---
title: expansion.library/FreeExpansionMem
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-freeexpansionmem-2
functions: [Alert]
libraries: [exec.library]
---

# expansion.library/FreeExpansionMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeExpansionMem - allocate standard device expansion memory

   SYNOPSIS
	FreeExpansionMem( startSlot, numSlots )
	                  D0         D1

   FUNCTION
	(Not typically called by user code)

	This function allocates numslots of expansion space (each slot
	is E_SLOTSIZE bytes).  It is the inverse function of
	[AllocExpansionMem()](autodocs-3.5/expansion-library-allocexpansionmem-2.md).

   INPUTS
	startSlot - the slot number that was allocated, or -1 for error.
	numSlots - the number of slots to be freed.

   RESULTS

   EXAMPLES

   EXCEPTIONS
	If the caller tries to free a slot that is already in the
	free list, FreeExpansionMem will [Alert()](autodocs-3.5/exec-library-alert-2.md) (e.g. crash the
	system).

   SEE ALSO
	[AllocExpansionMem()](autodocs-3.5/expansion-library-allocexpansionmem-2.md)

   BUGS

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
