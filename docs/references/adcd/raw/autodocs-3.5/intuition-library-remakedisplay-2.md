# intuition.library/RemakeDisplay



    NAME
	RemakeDisplay -- Remake the entire Intuition display.

    SYNOPSIS
	failure = RemakeDisplay()
	D0 (V39)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RemakeDisplay( VOID );
	/* Returns [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) in V39 and greater */

    FUNCTION
	This is the big one.

	This procedure remakes the entire [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure for the
	Intuition display.  It does the equivalent of [MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html) for
	every screen in the system, and then it calls the internal
	equivalent of [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html).

	WARNING:  This routine can take many milliseconds to run, so
	do not use it lightly.

	Calling [MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html) followed by [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html) is typically
	a more efficient method for affecting changes to a single
	screen's [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46).

    INPUTS
	None

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html)
	or of [graphics.library/MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS

    SEE ALSO
	[MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html), [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html), [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html)
	[graphics.library/MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html), [graphics.library/LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html)

