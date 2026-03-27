# battmem.resource/WriteBattMem



   NAME
	WriteBattMem -- [Write](../Includes_and_Autodocs_3._guide/node01D1.html) a bitstring to nonvolatile ram.  (V36)

   SYNOPSIS
	Error = WriteBattMem( Buffer, Offset, Len )
	D0                    A0      D0      D1

	ULONG WriteBattMem( [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG, ULONG );

   FUNCTION
	[Write](../Includes_and_Autodocs_3._guide/node01D1.html) a bitstring to the nonvolatile ram.

   INPUTS
	Buffer          Where to get the bitstring.
	Offset          Bit offset of first bit to write.
	Len             Length of bitstring to write.

   RESULTS
	Error           Zero if no error.

   NOTES
	The battery-backed memory is checksummed. If a checksum error
	is detected, all bits in the battery-backed memory are
	silently set to zero.

	Partial byte writes (less than 8 bits) result in the bits
	written being read from the low-order bits of the source byte.

   SEE ALSO

   BUGS

