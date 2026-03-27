# intuition.library/CloseScreen



    NAME
	CloseScreen -- [Close](../Includes_and_Autodocs_3._guide/node0149.html) an Intuition screen.

    SYNOPSIS
	Success = CloseScreen( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) )
	D0 (V36)               A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CloseScreen( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) * );
	/* returns [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) in V36 and greater */

    FUNCTION
	Unlinks the screen, unlinks the viewport, deallocates everything that
	Intuition allocated when the screen was opened (using [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)).
	Doesn't care whether or not there are still any windows attached to the
	screen.  Doesn't try to close any attached windows; in fact, ignores
	them altogether (but see below for changes in V36).

	If this is the last screen to go, attempts to reopen Workbench.

	New for V36: this function will refuse to close the screen
	if there are windows open on the screen or if there are any
	outstanding screen locks (see [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html)) when
	CloseScreen() is called.  This avoids the almost certain crash
	when a screen is closed out from under a window.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to the screen to be closed.

    RESULT
	New for V36: returns TRUE (1) if screen is closed,
	returns FALSE (0) if screen had open windows when
	called.

    BUGS

    SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)

