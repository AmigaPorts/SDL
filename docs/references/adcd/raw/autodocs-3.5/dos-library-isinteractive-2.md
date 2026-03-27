# dos.library/IsInteractive



    NAME
	IsInteractive -- Discover whether a file is "interactive"

    SYNOPSIS
	status = IsInteractive( file )
	D0			D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) IsInteractive(BPTR)

    FUNCTION
	The return value 'status' indicates whether the file associated
	with the file handle 'file' is connected to a virtual terminal.

    INPUTS
	file - BCPL pointer to a file handle

    RESULTS
	status - boolean


    SEE ALSO
