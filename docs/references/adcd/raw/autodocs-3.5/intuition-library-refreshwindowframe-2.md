# intuition.library/RefreshWindowFrame



    NAME
	RefreshWindowFrame -- Ask Intuition to redraw your window border.

    SYNOPSIS
	RefreshWindowFrame( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
			    A0

	VOID RefreshWindowFrame( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Refreshes the border of a window, including title region and all
	of the window's gadgets.

	You may use this call if you wish to update the display of your borders.
	The expected use of this is to correct unavoidable corruption.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = a pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure

    RESULT
	None


    BUGS

    SEE ALSO
