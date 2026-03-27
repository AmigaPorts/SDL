# dos.library/FPuts



   NAME
	FPuts -- Writes a string the the specified output (buffered) (V36)

   SYNOPSIS
	error = FPuts(fh, str)
	D0            D1  D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FPuts(BPTR, STRPTR)

   FUNCTION
	This routine writes an unformatted string to the filehandle.  No
	newline is appended to the string.  This routine is buffered.

   INPUTS
	fh    - filehandle to use for buffered I/O
	str   - Null-terminated string to be written to default output

   RESULT
	error - 0 normally, otherwise -1.  Note that this is opposite of
		most other Dos functions, which return success.

   SEE ALSO
	[FGets()](../Includes_and_Autodocs_3._guide/node0163.html), [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html), [FWrite()](../Includes_and_Autodocs_3._guide/node0173.html), [PutStr()](../Includes_and_Autodocs_3._guide/node019F.html)

