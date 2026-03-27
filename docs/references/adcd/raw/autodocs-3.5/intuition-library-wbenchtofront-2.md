# intuition.library/WBenchToFront



    NAME 
	WBenchToFront -- Bring the Workbench screen in front of all screens.

    SYNOPSIS 
	Success = WBenchToFront()
	D0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) WBenchToFront( VOID );

    FUNCTION 
	Causes the Workbench [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), if it's currently opened, to come to
	the foreground.  This does not 'move' the screen up or down, instead
	only affects the depth-arrangement of the screen.

    INPUTS 
	None

    RESULT 
	If the Workbench screen was opened, this function returns TRUE,
	otherwise it returns FALSE.

    BUGS 

    SEE ALSO 
	[WBenchToBack()](../Includes_and_Autodocs_3._guide/node0402.html), [ScreenToBack()](../Includes_and_Autodocs_3._guide/node03EA.html)

