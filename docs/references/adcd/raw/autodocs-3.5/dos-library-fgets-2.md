# dos.library/FGets



   NAME
	FGets -- Reads a line from the specified input (buffered) (V36)

   SYNOPSIS
	buffer = FGets(fh, buf, len)
	D0             D1  D2   D3

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) FGets(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ULONG)

   FUNCTION
	This routine reads in a single line from the specified input stopping
	at a NEWLINE character or EOF.  In either event, UP TO the number of
	len specified bytes minus 1 will be copied into the buffer.  Hence if
	a length of 50 is passed and the input line is longer than 49 bytes,
	it will return 49 characters.  It returns the buffer pointer normally,
	or NULL if EOF is the first thing read.

	If terminated by a newline, the newline WILL be the last character in
	the buffer.  This is a buffered read routine.  The string read in IS
	null-terminated.

   INPUTS
	fh  - filehandle to use for buffered I/O
	buf - Area to read bytes into.
	len - Number of bytes to read, must be > 0.

   RESULT
	buffer - Pointer to buffer passed in, or NULL for immediate EOF or for
		 an error.  If NULL is returnd for an EOF, [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) will return
		 0.

   BUGS
	In V36 and V37, it copies one more byte than it should if it doesn't
	hit an EOF or newline.  In the example above, it would copy 50 bytes
	and put a null in the 51st.  This is fixed in dos V39.  Workaround
	for V36/V37: pass in buffersize-1.

   SEE ALSO
	[FRead()](../Includes_and_Autodocs_3._guide/node016E.html), [FPuts()](../Includes_and_Autodocs_3._guide/node016D.html), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html)

