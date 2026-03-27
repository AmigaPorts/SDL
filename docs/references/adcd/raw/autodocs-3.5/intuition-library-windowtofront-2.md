# intuition.library/WindowToFront



    NAME
	WindowToFront -- Ask Intuition to bring a window to the front.

    SYNOPSIS
	WindowToFront( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
	               A0

	VOID WindowToFront( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	This routine sends a request to Intuition asking to bring the window
	in front of all other windows in the screen.

	Note that the window will not be depth-arranged immediately, but rather
	will be arranged the next time Intuition receives an input event,
	which happens currently at a minimum rate of ten times per second,
	and a maximum of sixty times a second.

	[Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) that WFLG_BACKDROP windows cannot be depth-arranged.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the structure of the window to be brought to front

    RESULT
	None

    BUGS

    SEE ALSO
	[MoveWindow()](../Includes_and_Autodocs_3._guide/node03C8.html), [SizeWindow()](../Includes_and_Autodocs_3._guide/node03FA.html), [WindowToBack()](../Includes_and_Autodocs_3._guide/node0405.html), [MoveWindowInFrontOf()](../Includes_and_Autodocs_3._guide/node03C9.html)

