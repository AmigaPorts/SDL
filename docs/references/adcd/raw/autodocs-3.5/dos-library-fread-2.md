# dos.library/FRead



   NAME
	FRead -- Reads a number of blocks from an input (buffered) (V36)

   SYNOPSIS
	count = FRead(fh, buf, blocklen, blocks)
	D0	      D1  D2     D3        D4

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FRead(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ULONG, ULONG)

   FUNCTION
	Attempts to read a number of blocks, each blocklen long, into the
	specified buffer from the input stream.  May return less than
	the number of blocks requested, either due to EOF or read errors.
	This call is buffered.

   INPUTS
	fh	 - filehandle to use for buffered I/O
	buf      - Area to read bytes into.
	blocklen - number of bytes per block.  Must be > 0.
	blocks	 - number of blocks to read.  Must be > 0.

   RESULT
	count - Number of _blocks_ read, or 0 for EOF.  On an error, the
		number of blocks actually read is returned.

   BUGS
	Doesn't clear [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) before starting.  If you want to find out
	about errors, use SetIoErr(0L) before calling.

   SEE ALSO
	[FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), [FWrite()](../Includes_and_Autodocs_3._guide/node0173.html), [FGets()](../Includes_and_Autodocs_3._guide/node0163.html)

