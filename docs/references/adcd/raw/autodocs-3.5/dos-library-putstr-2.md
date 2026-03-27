# dos.library/PutStr



   NAME
	PutStr -- Writes a string the the default output (buffered) (V36)

   SYNOPSIS
	error = PutStr(str)
	D0             D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PutStr(STRPTR)

   FUNCTION
	This routine writes an unformatted string to the default output.  No
	newline is appended to the string and any error is returned.  This
	routine is buffered.

   INPUTS
	str   - Null-terminated string to be written to default output

   RESULT
	error - 0 for success, -1 for any error.  NOTE: this is opposite
		most Dos function returns!

   SEE ALSO
	[FPuts()](../Includes_and_Autodocs_3._guide/node016D.html), [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html), [FWrite()](../Includes_and_Autodocs_3._guide/node0173.html), [WriteChars()](../Includes_and_Autodocs_3._guide/node01D2.html)

