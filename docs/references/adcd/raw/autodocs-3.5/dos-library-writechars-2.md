# dos.library/WriteChars



   NAME
	WriteChars -- Writes bytes to the the default output (buffered) (V36)

   SYNOPSIS
	count = WriteChars(buf, buflen)
	D0                 D1   D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) WriteChars(STRPTR, LONG)

   FUNCTION
	This routine writes a number of bytes to the default output.  The
	length is returned.  This routine is buffered.

   INPUTS
	buf    - buffer of characters to write
	buflen - number of characters to write

   RESULT
	count - Number of bytes written.  -1 (EOF) indicates an error

   SEE ALSO
	[FPuts()](../Includes_and_Autodocs_3._guide/node016D.html), [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html), [FWrite()](../Includes_and_Autodocs_3._guide/node0173.html), [PutStr()](../Includes_and_Autodocs_3._guide/node019F.html)

