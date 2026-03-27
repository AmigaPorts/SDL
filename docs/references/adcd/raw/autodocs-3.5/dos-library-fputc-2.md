# dos.library/FPutC



   NAME
	FPutC -- [Write](../Includes_and_Autodocs_3._guide/node01D1.html) a character to the specified output (buffered) (V36)

   SYNOPSIS
	char = FPutC(fh, char)
	D0           D1   D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FPutC(BPTR, LONG)

   FUNCTION
	Writes a single character to the output stream.  This call is
	buffered.  Use [Flush()](../Includes_and_Autodocs_3._guide/node016A.html) between buffered and unbuffered I/O on a
	filehandle.  Interactive filehandles are flushed automatically
	on a newline, return, '0', or line feed.

   INPUTS
	fh   - filehandle to use for buffered I/O
	char - character to write

   RESULT
	char - either the character written, or EOF for an error.

   BUGS
	Older autodocs indicated that you should pass a [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50).  The
	correct usage is to pass a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) in the range 0-255.

   SEE ALSO
	[FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), [Flush()](../Includes_and_Autodocs_3._guide/node016A.html)

