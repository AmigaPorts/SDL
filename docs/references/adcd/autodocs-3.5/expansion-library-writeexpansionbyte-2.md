---
title: expansion.library/WriteExpansionByte
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-writeexpansionbyte-2
functions: []
libraries: []
---

# expansion.library/WriteExpansionByte

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WriteExpansionByte - write a byte nybble by nybble.

   SYNOPSIS
	WriteExpansionByte( board, offset, byte )
			    A0     D0      D1

   FUNCTION
	(Not typically called by user code)

	WriteExpansionByte writes a byte to a new-style expansion
	board.  These boards have their writeable data organized
	as a series of nybbles in memory.  This routine writes
	two nybbles in a very careful manner to work with all
	types of new expansion boards.

	To make certain types of board less expensive, an expansion
	board's write registers may be organized as either a
	byte-wide or nybble-wide register.  If it is nybble-wide
	then it must latch the less significant nybble until the
	more significant nybble is written.  This allows the
	following algorithm to work with either type of board:

		write the low order nybble to bits D15-D12 of
			byte (offset*4)+2

		write the entire byte to bits D15-D8 of
			byte (offset*4)

	The offset is a byte offset into a [ExpansionRom](autodocs-3.5/include-libraries-configregs-h.md) structure.
	The actual memory address read will be four times larger.
	The macros EROFFSET and ECOFFSET are provided to help get
	these offsets from C.

   INPUTS
	board - a pointer to the base of a new style expansion board.
	offset - a logical offset from the configdev base
	byte - the byte of data to be written to the expansion board.

   EXAMPLES
	WriteExpansionByte( cd->BoardAddr, ECOFFSET( ec_Shutup ),  0 );
	WriteExpansionByte( cd->BoardAddr, ECOFFSET( ec_Interrupt ), 1 );

   SEE ALSO
	[ReadExpansionByte()](autodocs-3.5/expansion-library-readexpansionbyte-2.md), [ReadExpansionRom()](autodocs-3.5/expansion-library-readexpansionrom-2.md)

