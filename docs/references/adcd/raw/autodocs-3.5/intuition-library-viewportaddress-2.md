# intuition.library/ViewPortAddress



    NAME
	ViewPortAddress -- Return the address of a window's viewport.

    SYNOPSIS
	[ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) = ViewPortAddress( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
	D0                          A0

	struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *ViewPortAddress( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Returns the address of the viewport associated with the specified
	window.  The viewport is actually the viewport of the screen within
	which the window is displayed.  If you want to use any of the graphics,
	text, or animation primitives in your window and that primitive
	requires a pointer to a viewport, you can use this call.

	This pointer is only valid as long as your window's screen remains
	open, which is ensured by keeping your window open.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window for which you want the viewport address

    RESULT
	Returns the address of the Intuition [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure for
	your window's screen .

    BUGS
	This routine is unnecessary: you can just use the expression
	&Window->WScreen->ViewPort.

    SEE ALSO
	graphics.library

