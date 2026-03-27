# intuition.library/MoveWindowInFrontOf



    NAME
	MoveWindowInFrontOf -- Arrange the relative depth of a window. (V36)

    SYNOPSIS
	MoveWindowInFrontOf( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), BehindWindow )
			     A0      A1

	VOID MoveWindowInFrontOf( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Depth-arranges a window in front of an another window.
	Brings out the layers.library [MoveLayerInFrontOf()](../Includes_and_Autodocs_3._guide/node042B.html) to the
	Intuition user.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) =  window to re-position in front of another window
	BehindWindow =  window to re-position in front of

    RESULT
	Repositions window.

    BUGS
	Doesn't respect backdrop windows.

    SEE ALSO
	[WindowToFront()](../Includes_and_Autodocs_3._guide/node0406.html), [WindowToBack()](../Includes_and_Autodocs_3._guide/node0405.html), [layers.library/MoveLayerInFrontOf()](../Includes_and_Autodocs_3._guide/node042B.html)

