# intuition.library/ScreenDepth



    NAME
	ScreenDepth -- Depth arrange a screen with extra control. (V39)

    SYNOPSIS
	ScreenDepth( screen, flags, reserved )
	             A0      D0     A1

	VOID ScreenDepth( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) );

    FUNCTION
	Brings the specified screen to the front or back, based on
	the supplied flags.  Also allows control of screen
	depth-arranging within screen families.

    INPUTS
	screen = a pointer to the screen to move
	flags = one of SDEPTH_TOFRONT or SDEPTH_TOBACK (bringing the
	    screen to front or back respectively).  If the screen
	    is an attached screen, then you may also specify
	    SDEPTH_INFAMILY to move the screen within the screen
	    family.  If the screen is an attached screen and
	    SDEPTH_INFAMILY is not specified, then the whole family
	    will move, which is also the behavior of the [ScreenToFront()](../Includes_and_Autodocs_3._guide/node03EB.html)
	    and [ScreenToBack()](../Includes_and_Autodocs_3._guide/node03EA.html) functions, as well as the user-interface
	    controls.
	reserved = must be NULL for now.

    RESULT
	None

    NOTES
	ONLY the application which owns the screen should use
	SDEPTH_INFAMILY.  It is incorrect style (and against the
	intentions of the screen opener) for programs such as
	commodities or mouse-helpers to move child screens around
	in their family.  (Note that this is a style-behavior
	requirement;  there is no technical requirement that the
	task calling this function need be the task which opened
	the screen).

    BUGS

    SEE ALSO
	[ScreenToFront()](../Includes_and_Autodocs_3._guide/node03EB.html), [ScreenToBack()](../Includes_and_Autodocs_3._guide/node03EA.html),
	SA_Parent, SA_FrontChild, SA_BackChild

