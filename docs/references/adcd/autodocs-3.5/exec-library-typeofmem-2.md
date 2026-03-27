---
title: exec.library/TypeOfMem
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-typeofmem-2
functions: [AllocMem]
libraries: [exec.library]
---

# exec.library/TypeOfMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TypeOfMem -- determine attributes of a given memory address

   SYNOPSIS
	attributes = TypeOfMem(address)
	D0		       A1

	ULONG TypeOfMem(void *);

   FUNCTION
	Given a RAM memory address, search the system memory lists and
	return its memory attributes.  The memory attributes are similar to
	those specified when the memory was first allocated: (eg. MEMF_CHIP
	and MEMF_FAST).

	This function is usually used to determine if a particular block of
	memory is within CHIP space.

	If the address is not in known-space, a zero will be returned.
	(Anything that is not RAM, like the ROM or expansion area, will
	return zero.  Also the first few bytes of a memory area are used up
	by the MemHeader.)

   INPUT
	address - a memory address

   RESULT
	attributes - a long word of memory attribute flags.
	If the address is not in known RAM, zero is returned.

   SEE ALSO
	[AllocMem()](autodocs-3.5/exec-library-allocmem-2.md)

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
