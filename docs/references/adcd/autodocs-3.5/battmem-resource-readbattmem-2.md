---
title: battmem.resource/ReadBattMem
manual: autodocs-3.5
chapter: autodocs-3.5
section: battmem-resource-readbattmem-2
functions: []
libraries: []
---

# battmem.resource/ReadBattMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadBattMem -- [Read](autodocs-3.5/dos-library-read-2.md) a bitstring from nonvolatile ram.  (V36)

   SYNOPSIS
	Error = ReadBattMem( Buffer, Offset, Len )
	D0                   A0      D0      D1

	ULONG ReadBattMem( [APTR](autodocs-3.5/include-exec-types-h.md), ULONG, ULONG );

   FUNCTION
	[Read](autodocs-3.5/dos-library-read-2.md) a bitstring from nonvolatile ram.

   INPUTS
	Buffer          Where to put the bitstring.
	Offset          Bit offset of first bit to read.
	Len             Length of bitstring to read.

   RESULTS
	Error           Zero if no error.

   NOTES
	The battery-backed memory is checksummed. If a checksum error
	is detected, all bits in the battery-backed memory are
	silently set to zero.

	Bits in the battery-backed memory that do not exist are read
	as zero.

	Partial byte reads (less than 8 bits) result in the bits read
	being put in the low-order bits of the destination byte.

   SEE ALSO

   BUGS

