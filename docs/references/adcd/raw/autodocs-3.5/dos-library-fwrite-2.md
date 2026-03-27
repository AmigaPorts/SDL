# dos.library/FWrite



   NAME
	FWrite -- Writes a number of blocks to an output (buffered) (V36)

   SYNOPSIS
	count = FWrite(fh, buf, blocklen, blocks)
	D0	       D1  D2     D3        D4

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FWrite(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ULONG, ULONG)

   FUNCTION
	Attempts to write a number of blocks, each blocklen long, from the
	specified buffer to the output stream.  May return less than the
	number of blocks requested, if there is some error such as a full
	disk or r/w error.  This call is buffered.

   INPUTS
	fh	 - filehandle to use for buffered I/O
	buf      - Area to write bytes from.
	blocklen - number of bytes per block.  Must be > 0.
	blocks	 - number of blocks to write.  Must be > 0.

   RESULT
	count - Number of _blocks_ written.  On an error, the number of
		blocks actually written is returned.

   BUGS
	Doesn't clear [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) before starting.  If you want to find out
	about errors, use SetIoErr(0L) before calling.

   SEE ALSO
	[FPutC()](../Includes_and_Autodocs_3._guide/node016C.html), [FRead()](../Includes_and_Autodocs_3._guide/node016E.html), [FPuts()](../Includes_and_Autodocs_3._guide/node016D.html)

