# battmem.resource/ReadBattMem



   NAME
	ReadBattMem -- [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a bitstring from nonvolatile ram.  (V36)

   SYNOPSIS
	Error = ReadBattMem( Buffer, Offset, Len )
	D0                   A0      D0      D1

	ULONG ReadBattMem( [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG, ULONG );

   FUNCTION
	[Read](../Includes_and_Autodocs_3._guide/node01A0.html) a bitstring from nonvolatile ram.

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

