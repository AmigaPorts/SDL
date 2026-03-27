# intuition.library/SetPubScreenModes



    NAME
	SetPubScreenModes -- Establish global public screen behavior. (V36)

    SYNOPSIS
	OldModes = SetPubScreenModes( Modes )
	D0                            D0

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) SetPubScreenModes( [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

    FUNCTION
    	Sets GLOBAL Intuition public screen modes.	

    INPUTS
	Modes = new global modes flags.  Values for flag bits are:
	  SHANGHAI: workbench windows are to be opened on the
		default public screen
	  POPPUBSCREEN: when a visitor window is opened, the public
		screen it opens on is to be brought to the front.

    RESULT
	OldModes = previous global mode settings

    BUGS

    SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), Intuition V36 update documentation

