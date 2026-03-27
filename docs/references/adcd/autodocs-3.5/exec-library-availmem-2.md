---
title: exec.library/AvailMem
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-availmem-2
functions: []
libraries: []
---

# exec.library/AvailMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AvailMem -- memory available given certain requirements

   SYNOPSIS
	size = AvailMem(attributes)
	D0		D1

	ULONG AvailMem(ULONG);

   FUNCTION
	This function returns the amount of free memory given certain
	attributes.

	To find out what the largest block of a particular type is, add
	MEMF_LARGEST into the requirements argument.  Returning the largest
	block is a slow operation.

   WARNING
	Due to the effect of multitasking, the value returned may not
	actually be the amount of free memory available at that instant.

   INPUTS
	requirements - a requirements mask as specified in [AllocMem](autodocs-3.5/exec-library-allocmem-2.md).  Any
		       of the [AllocMem](autodocs-3.5/exec-library-allocmem-2.md) bits are valid, as is MEMF_LARGEST
		       which returns the size of the largest block matching
		       the requirements.

   RESULT
	size - total free space remaining (or the largest free block).

   NOTE
	For V36 Exec, AvailMem(MEMF_LARGEST) does a consistency check on
	the memory list.  [Alert](autodocs-3.5/exec-library-alert-2.md) AN_MemoryInsane will be pulled if any mismatch
	is noted.

   EXAMPLE
	AvailMem(MEMF_CHIP|MEMF_LARGEST);
	/* return size of largest available chip memory chunk */

   SEE ALSO
	[exec/memory.h](autodocs-3.5/include-exec-memory-h.md)

