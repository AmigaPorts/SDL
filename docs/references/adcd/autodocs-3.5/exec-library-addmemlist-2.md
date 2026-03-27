---
title: exec.library/AddMemList
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addmemlist-2
functions: [AllocMem]
libraries: [exec.library]
---

# exec.library/AddMemList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddMemList - add memory to the system free pool

   SYNOPSIS
	AddMemList( size, attributes, pri, base, name )

                     D0      D1        D2   A0    A1
	void AddMemList(ULONG, ULONG, [LONG](autodocs-3.5/include-exec-types-h.md), [APTR](autodocs-3.5/include-exec-types-h.md), STRPTR);

   FUNCTION
	Add a new region of memory to the system free pool.  The first few
	bytes will be used to hold the [MemHeader](autodocs-3.5/include-exec-memory-h.md) structure.  The remainder
	will be made available to the rest of the world.

   INPUTS
	size - the size (in bytes) of the memory area
	attributes - the attributes word that the memory pool will have
	pri  - the priority for this memory.  CHIP memory has a pri of -10,
	       16 bit expansion memory has a priority of 0.  The higher the
	       priority, the closer to the head of the memory list it will
	       be placed.
	base - the base of the new memory area
	name - the name that will be used in the memory header, or NULL
	       if no name is to be provided.  This name is not copied, so it
	       must remain valid for as long as the memory header is in the
	       system.

   NOTES
	*DO NOT* add memory to the system with the attribute of MEMF_KICK.
	EXEC will mark your memory as such if it is of the right type.

   SEE ALSO
	[AllocMem()](autodocs-3.5/exec-library-allocmem-2.md), [exec/memory.h](autodocs-3.5/include-exec-memory-h.md)

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
