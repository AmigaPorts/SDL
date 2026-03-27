# dos.library/Input



    NAME
	Input -- Identify the program's initial input file handle

    SYNOPSIS
	file = Input()
	D0

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) Input(void)

    FUNCTION
	Input() is used to identify the initial input stream allocated when
	the program was initiated.  Never close the filehandle returned by
	Input!

    RESULTS
	file - BCPL pointer to a file handle

    SEE ALSO
	[Output()](../Includes_and_Autodocs_3._guide/node0198.html), [SelectInput()](../Includes_and_Autodocs_3._guide/node01AE.html)

