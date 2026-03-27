# expansion.library/ReadExpansionByte



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

	In general, this routine will only be called by [ReadExpansionRom](../Includes_and_Autodocs_3._guide/node0269.html).

	The offset is a byte offset, as if into a [ExpansionRom](../Includes_and_Autodocs_3._guide/node05FE.html#line45) structure.
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
	[WriteExpansionByte()](../Includes_and_Autodocs_3._guide/node026D.html), [ReadExpansionRom()](../Includes_and_Autodocs_3._guide/node0269.html)

