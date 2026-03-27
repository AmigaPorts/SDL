# dos.library/Output



    NAME
	Output -- Identify the programs' initial output file handle

    SYNOPSIS
	file = Output()
	D0

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) Output(void)

    FUNCTION
	Output() is used to identify the initial output stream allocated
	when the program was initiated.  Never close the filehandle returned
	by Output().

    RESULTS
	file - BCPL pointer to a file handle

    SEE ALSO
	[Input()](../Includes_and_Autodocs_3._guide/node017F.html)

