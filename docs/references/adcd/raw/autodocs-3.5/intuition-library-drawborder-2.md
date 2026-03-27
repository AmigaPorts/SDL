# intuition.library/DrawBorder



    NAME
	DrawBorder -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) the specified [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) structure into a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

    SYNOPSIS
	DrawBorder( [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683), LeftOffset, TopOffset )
		    A0        A1      D0          D1

	VOID DrawBorder( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) *, WORD, WORD );

    FUNCTION
	First, sets up the draw mode and pens in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) according to the
	arguments of the [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) structure.  Then, draws the vectors of
	the border argument into the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), offset by the left and top
	offsets.

	As with all graphics rendering routines, the border will be clipped to
	to the boundaries of the RastPort's layer, if it exists.  This is
	the case with window RastPorts.

	This routine will draw all borders in the NULL-terminated list linked
	by the NextBorder field of the border argument.

    INPUTS
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to receive the border rendering
	[Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) = pointer to a [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) structure
	LeftOffset = the offset to be added to each vector's x coordinate
	TopOffset = the offset to be added to each vector's y coordinate

    RESULT
	None


    BUGS

    SEE ALSO
