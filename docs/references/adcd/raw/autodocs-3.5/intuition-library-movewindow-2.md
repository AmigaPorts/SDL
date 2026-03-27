# intuition.library/MoveWindow



    NAME
	MoveWindow -- Ask Intuition to move a window.

    SYNOPSIS
	MoveWindow( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), DeltaX, DeltaY )
		    A0      D0      D1

	VOID MoveWindow( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, WORD, WORD );

    FUNCTION
	This routine sends a request to Intuition asking to move the window
	the specified distance.  The delta arguments describe how far to
	move the window along the respective axes.

	Note that the window will not be moved immediately, but rather
	will be moved the next time Intuition receives an input event,
	which happens currently at a minimum rate of ten times per second,
	and a maximum of sixty times a second.

	Interactions with other arbitration of Intuition data structures
	may defer this operation longer.  For V36, you can use the new
	IDCMP class IDCMP_CHANGEWINDOW to detect when this operation has
	completed.

	New for V36: Intuition now will do validity checking on the final
	position.  To send absolute movements, or to move and size a
	window in one step, use [ChangeWindowBox()](../Includes_and_Autodocs_3._guide/node039B.html).

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the structure of the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) to be moved
	DeltaX = how far to move the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) on the x-axis
	DeltaY = how far to move the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) on the y-axis

    RESULT
	None

    BUGS

    SEE ALSO
	[ChangeWindowBox()](../Includes_and_Autodocs_3._guide/node039B.html), [SizeWindow()](../Includes_and_Autodocs_3._guide/node03FA.html), [WindowToFront()](../Includes_and_Autodocs_3._guide/node0406.html), [WindowToBack()](../Includes_and_Autodocs_3._guide/node0405.html)

