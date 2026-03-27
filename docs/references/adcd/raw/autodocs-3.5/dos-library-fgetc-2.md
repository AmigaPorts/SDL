# dos.library/FGetC



   NAME
	FGetC -- [Read](../Includes_and_Autodocs_3._guide/node01A0.html) a character from the specified input (buffered) (V36)

   SYNOPSIS
	char = FGetC(fh)
	D0	     D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FGetC(BPTR)

   FUNCTION
	Reads the next character from the input stream.  A -1 is
	returned when EOF or an error is encountered.  This call is buffered.
	Use [Flush()](../Includes_and_Autodocs_3._guide/node016A.html) between buffered and unbuffered I/O on a filehandle.

   INPUTS
	fh - filehandle to use for buffered I/O

   RESULT
	char - character read (0-255) or -1

   BUGS
	In V36, after an EOF was read, EOF would always be returned from
	FGetC() from then on.  Starting in V37, it tries to read from the
	handler again each time (unless UnGetC(fh,-1) was called).

   SEE ALSO
	[FPutC()](../Includes_and_Autodocs_3._guide/node016C.html), [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), [Flush()](../Includes_and_Autodocs_3._guide/node016A.html)

