# intuition.library/ScreenPosition



    NAME
	ScreenPosition -- [Move](../Includes_and_Autodocs_3._guide/node0301.html) screens with greater control. (V39)

    SYNOPSIS
	ScreenPosition( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), flags, x1, y1, x2, y2 )
	                A0      D0     D1  D2  D3  D4

	VOID ScreenPosition( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, ULONG, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) );

    FUNCTION
	Moves the screen to the specified position or by the specified
	increment, in screen pixel resolution coordinates.

	If the x1 and y1 variables you specify would move the screen in
	a way that violates any restrictions, the screen will be moved
	as far as possible.  You may examine the LeftEdge and TopEdge
	fields of the [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) structure after this function returns to
	see where the screen really ended up.

	Note that negative values for screen LeftEdge and TopEdge are
	valid for screens bigger than their display clip.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to a [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) structure
	flags = Set to one of SPOS_RELATIVE, SPOS_ABSOLUTE, or
		SPOS_MAKEVISIBLE.   You may additionally set SPOS_FORCEDRAG
		if you need.  Use SPOS_RELATIVE (zero) for normal use
		(move screen a relative amount expressed by x1,y1).  Set
		the SPOS_ABSOLUTE flag if you wish x1 and y1 to be absolute
		coordinates to move the screen to.  Set SPOS_MAKEVISIBLE to
		position an oversized scrolling screen so that the rectangle
		described by (x1,y1)-(x2,y2) is on the visible part of
		the display. (A word-processor may wish to support
		autoscrolling as the user types.  In that case, it could
		call ScreenPosition() with the SPOS_MAKEVISIBLE flag and
		a rectangle that encompasses the cursor with some space
		around it.

		In addition to any one of the above choices, you can
		additionally set SPOS_FORCEDRAG if you wish to reposition
		a screen that was opened with the {SA_Draggable,FALSE}
		attribute.

	x1,y1 = Absolute position or change in position you wish to apply
		to the screen, when using SPOS_ABSOLUTE or SPOS_RELATIVE.
		When using SPOS_MAKEVISIBLE, these variables describe
		the upper-left corner of the rectangle you would like to
		ensure is on the visible part of a scrolling screen.
	x2,y2 = Ignored when using SPOS_ABSOLUTE or SPOS_RELATIVE.
		When using SPOS_MAKEVISIBLE, these variables describe
		the lower-right corner of the rectangle you would like to
		ensure is on the visible part of a scrolling screen.

		Note that these coordinates are in the same resolution
		as the screen (such as HIRES or INTERLACE)

    RESULT
	None

    NOTES
	ONLY the owner of the screen should use SPOS_FORCEDRAG.
	It is incorrect style (and against the intentions of the
	screen opener) for programs such as commodities or
	mouse-helpers to move non-draggable screens.


    BUGS

    SEE ALSO
	[MoveScreen()](../Includes_and_Autodocs_3._guide/node03C7.html), [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html)

