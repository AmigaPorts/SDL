# intuition.library/MoveScreen



    NAME
	MoveScreen -- Attempt to move the screen by the increments provided.

    SYNOPSIS
	MoveScreen( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), DeltaX, DeltaY )
		    A0      D0      D1

	VOID MoveScreen( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, WORD, WORD );

    FUNCTION
	Moves the screen the specified increment, specified in screen
	pixel resolution coordinates.

	New for V36: [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) movement limits have been greatly relaxed,
	to support screen scrolling.  In particular, negative values
	for screen LeftEdge and TopEdge may now be valid.

       If the DeltaX and DeltaY variables you specify would move the screen
       in a way that violates any restrictions, the screen will be moved
       as far as possible.  You may examine the LeftEdge and TopEdge fields
	of the [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) structure after this function returns to see where
	the screen really ended up.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to a [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) structure
	DeltaX = amount to move the screen on the x-axis
		Note that DeltaX no longer (V36) need be set to zero
	DeltaY = amount to move the screen on the y-axis
		Note that these coordinates are in the same resolution
		as the screen (such as HIRES or INTERLACE)

    RESULT
	None

    BUGS

    SEE ALSO
	[ScreenPosition()](../Includes_and_Autodocs_3._guide/node03E9.html), [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html)

