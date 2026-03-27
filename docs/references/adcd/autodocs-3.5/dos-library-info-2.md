---
title: dos.library/Info
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-info-2
functions: [Info]
libraries: [dos.library]
---

# dos.library/Info

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Info -- Returns information about the disk

    SYNOPSIS
	success = Info( lock, parameterBlock )
	D0		D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) Info(BPTR, struct [InfoData](autodocs-3.5/include-dos-dos-h.md) *)

    FUNCTION
	Info() can be used to find information about any disk in use.
	'lock' refers to the disk, or any file on the disk. The parameter
	block is returned with information about the size of the disk,
	number of free blocks and any soft errors.

    INPUTS
	lock	       - BCPL pointer to a lock
	parameterBlock - pointer to an [InfoData](autodocs-3.5/include-dos-dos-h.md) structure
			 (longword aligned)

    RESULTS
	success - boolean

    SPECIAL NOTE:
	Note that [InfoData](autodocs-3.5/include-dos-dos-h.md) structure must be longword aligned.

---

## See Also

- [Info — dos.library](../autodocs/dos.library.md#info)
