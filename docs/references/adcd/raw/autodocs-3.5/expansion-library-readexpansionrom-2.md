# expansion.library/ReadExpansionRom



   NAME
	ReadExpansionRom - read a boards configuration ROM space

   SYNOPSIS
	error = ReadExpansionRom( board, configDev )
	D0                        A0     A1

   FUNCTION
	(Not typically called by user code)

	ReadExpansionRom reads a the ROM portion of an expansion
	device in to cd_Rom portion of a [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure.
	This routine knows how to detect whether or not there is
	actually a board there,

	In addition, the ROM portion of a new style expansion board
	is encoded in ones-complement format (except for the first
	two nybbles -- the er_Type field).  ReadExpansionRom knows
	about this and un-complements the appropriate fields.

   INPUTS
	board - a pointer to the base of a new style expansion board.
	configDev - the [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure that will be read in.
	offset - a logical offset from the configdev base

   RESULTS
	error - If the board address does not contain a valid new style
		expansion board, then error will be non-zero.

   EXAMPLES

	configDev = AllocConfigDev();
	if( ! configDev ) panic();

	error = ReadExpansionBoard( board, configDev );
	if( ! error ) {
		configDev->cd_BoardAddr = board;
		ConfigBoard( configDev );
	}

   SEE ALSO
	[ReadExpansionByte()](../Includes_and_Autodocs_3._guide/node0268.html), [WriteExpansionByte()](../Includes_and_Autodocs_3._guide/node026D.html)

