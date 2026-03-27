---
title: expansion.library/ReadExpansionByte
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-readexpansionbyte-2
functions: []
libraries: []
---

# expansion.library/ReadExpansionByte

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadExpansionByte - read a byte nybble by nybble.

   SYNOPSIS
	byte = ReadExpansionByte( board, offset )
	D0                        A0     D0

   FUNCTION
	(Not typically called by user code)

 	ReadExpansionByte reads a byte from a new-style expansion
	board.  These boards have their readable data organized
	as a series of nybbles in memory.  This routine reads
	two nybbles and returns the byte value.

	In general, this routine will only be called by [ReadExpansionRom](autodocs-3.5/expansion-library-readexpansionrom-2.md).

	The offset is a byte offset, as if into a [ExpansionRom](autodocs-3.5/include-libraries-configregs-h.md) structure.
	The actual memory address read will be four times larger.
	The macros EROFFSET and ECOFFSET are provided to help get
	these offsets from C.

   INPUTS
	board - a pointer to the base of a new style expansion board.
	offset - a logical offset from the board base

   RESULTS
	byte - a byte of data from the expansion board.

   EXAMPLES
	byte = ReadExpansionByte( cd->BoardAddr, EROFFSET( er_Type ) );
	ints = ReadExpansionByte( cd->BoardAddr, ECOFFSET( ec_Interrupt ) );

   SEE ALSO
	[WriteExpansionByte()](autodocs-3.5/expansion-library-writeexpansionbyte-2.md), [ReadExpansionRom()](autodocs-3.5/expansion-library-readexpansionrom-2.md)

