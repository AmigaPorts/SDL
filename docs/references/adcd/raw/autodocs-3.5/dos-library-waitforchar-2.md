# dos.library/WaitForChar



    NAME
	WaitForChar -- Determine if chars arrive within a time limit

    SYNOPSIS
	status = WaitForChar( file, timeout )
	D0		      D1    D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) WaitForChar(BPTR, LONG)

    FUNCTION
	If a character is available to be read from 'file' within the
	time (in microseconds) indicated by 'timeout', WaitForChar()
	returns -1 (TRUE). If a character is available, you can use [Read()](../Includes_and_Autodocs_3._guide/node01A0.html)
	to read it.  Note that WaitForChar() is only valid when the I/O
	stream is connected to a virtual terminal device. If a character is
	not available within 'timeout', a 0 (FALSE) is returned.

    BUGS
	Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
	of zero for WaitForChar() can cause the unreliable timer & floppy
	disk operation.

    INPUTS
	file - BCPL pointer to a file handle
	timeout - integer

    RESULTS
	status - boolean

    SEE ALSO
	[Read()](../Includes_and_Autodocs_3._guide/node01A0.html), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html)

