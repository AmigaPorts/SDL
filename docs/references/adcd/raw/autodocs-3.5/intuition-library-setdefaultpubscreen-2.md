# intuition.library/SetDefaultPubScreen



    NAME
	SetDefaultPubScreen -- Choose a new default public screen. (V36)

    SYNOPSIS
	SetDefaultPubScreen( Name )
			     A0

	VOID SetDefaultPubScreen( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) * );

    FUNCTION
	Establishes a new default public screen for visitor windows.

	This screen is used by windows asking for a named public screen
	that doesn't exist and the FALLBACK option is selected, and for
	windows asking for the default public screen directly.

    INPUTS
	Name = name of chosen public screen to be the new default.
	A value of NULL means that the Workbench screen is to
	be the default public screen.

    RESULT
	None

    BUGS

    SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html), [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), Intuition V36 update documentation

