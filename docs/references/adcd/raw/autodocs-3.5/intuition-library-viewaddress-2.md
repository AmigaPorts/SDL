# intuition.library/ViewAddress



    NAME
	ViewAddress -- Return the address of the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure.

    SYNOPSIS
	view = ViewAddress()
	D0

	struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) *ViewAddress( VOID );

    FUNCTION
	Returns the address of the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure.  If you
	want to use any of the graphics, text, or animation primitives
	in your window and that primitive requires a pointer to a view,
	this routine will return the address of the view for you.

    INPUTS
	None

    RESULT
	Returns the address of the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure

    BUGS

    SEE ALSO
	graphics.library

