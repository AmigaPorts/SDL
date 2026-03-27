# dos.library/PrintFault



   NAME
	PrintFault -- Returns the text associated with a DOS error code (V36)

   SYNOPSIS
	success = PrintFault(code, header)
	D0                    D1     D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) PrintFault(LONG, STRPTR)

   FUNCTION
	This routine obtains the error message text for the given error code.
	This is similar to the [Fault()](../Includes_and_Autodocs_3._guide/node0161.html) function, except that the output is
	written to the default output channel with buffered output.
	The value returned by [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) is set to the code passed in.

   INPUTS
	code   - Error code
	header - header to output before error text

   RESULT
	success - Success/failure code.

   SEE ALSO
	[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html), [Fault()](../Includes_and_Autodocs_3._guide/node0161.html), [SetIoErr()](../Includes_and_Autodocs_3._guide/node01B8.html), [Output()](../Includes_and_Autodocs_3._guide/node0198.html), [FPuts()](../Includes_and_Autodocs_3._guide/node016D.html)

