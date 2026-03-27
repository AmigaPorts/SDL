# dos.library/Fault



   NAME
	Fault -- Returns the text associated with a DOS error code (V36)

   SYNOPSIS
	len = Fault(code, header, buffer, len)
	D0           D1     D2      D3    D4

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Fault(LONG, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), LONG)

   FUNCTION
	This routine obtains the error message text for the given error code.
	The header is prepended to the text of the error message, followed
	by a colon.  Puts a null-terminated string for the error message into
	the buffer.  By convention, error messages should be no longer than 80
	characters (+1 for termination), and preferably no more than 60.
	The value returned by [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) is set to the code passed in.  If there
	is no message for the error code, the message will be "Error code
	<number>n".

	The number of characters put into the buffer is returned, which will
	be 0 if the code passed in was 0.

   INPUTS
	code   - Error code
	header - header to output before error text
	buffer - Buffer to receive error message.
	len    - Length of the buffer.

   RESULT
	len    - number of characters put into buffer (may be 0)

   SEE ALSO
	[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html), [SetIoErr()](../Includes_and_Autodocs_3._guide/node01B8.html), [PrintFault()](../Includes_and_Autodocs_3._guide/node019E.html)

   BUGS
	In older documentation, the return was shown as [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) success.  This
	was incorrect, it has always returned the length.

