# intuition.library/LockPubScreen



    NAME
	LockPubScreen -- Prevent a public screen from closing. (V36)

    SYNOPSIS
	screen = LockPubScreen( Name )
	D0                      A0

	struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *LockPubScreen( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) * );

    FUNCTION
	Prevents a public screen (or the Workbench) from closing
	while you examine it in preparation of opening a visitor window.

	The sequence you use to open a visitor window that needs to
	examine fields in the screen it is about to open on is:
		LockPubScreen()
		... examine fields ...
		[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) on public screen
		[UnlockPubScreen()](../Includes_and_Autodocs_3._guide/node03FE.html)
		... use your window ...
		[CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)

    NOTE 
	You needn't hold the "pubscreen lock" for the duration that
	your window is opened.  LockPubScreen() basically has the
	same effect as an open visitor window: it prevents the
	screen from being closed.

	If you pass the string "Workbench" or you pass NULL and there
	is no default public screen, the Workbench screen will
	be automatically opened if it is not already present.

    INPUTS
	Name = name string for public screen or NULL for default public
	screen.  The string "Workbench" indicates the Workbench
	screen.

    RESULT
	Returns pointer to a screen, if successful, else NULL.
	The call can fail for reasons including that the named
	public screen doesn't exist or is in private state.

    BUGS

    SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html), [UnlockPubScreen()](../Includes_and_Autodocs_3._guide/node03FE.html), [GetScreenData()](../Includes_and_Autodocs_3._guide/node03B9.html)

