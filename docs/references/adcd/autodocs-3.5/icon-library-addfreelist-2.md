---
title: icon.library/AddFreeList
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-addfreelist-2
functions: [AddFreeList]
libraries: [icon.library]
---

# icon.library/AddFreeList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddFreeList - add memory to a free list.

   SYNOPSIS
	status = AddFreeList(free, mem, len)
	  D0                  A0    A1   A2

	[BOOL](autodocs-3.5/include-exec-types-h.md) AddFreeList(struct [FreeList](autodocs-3.5/include-workbench-workbench-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), ULONG);

   FUNCTION
	This routine adds the specified memory to the free list.
	The free list will be extended (if required).  If there
	is not enough memory to complete the call, NULL is returned.

	Note that AddFreeList() does NOT allocate the requested memory.
	It only records the memory in the free list.

   INPUTS
	free -- a pointer to a [FreeList](autodocs-3.5/include-workbench-workbench-h.md) structure
	mem -- the base of the memory to be recorded
	len -- the length of the memory to be recorded

   RESULTS
	status -- TRUE if the call succeeded else FALSE;

   SEE ALSO
	[exec.library/AllocEntry](autodocs-3.5/exec-library-allocentry-2.md)
	[exec.library/FreeEntry](autodocs-3.5/exec-library-freeentry-2.md)
	[icon.library/FreeFreeList](autodocs-3.5/icon-library-freefreelist-2.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)

---

## See Also

- [AddFreeList — icon.library](../autodocs/icon.library.md#addfreelist)
