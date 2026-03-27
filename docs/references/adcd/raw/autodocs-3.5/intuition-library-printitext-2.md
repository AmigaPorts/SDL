# intuition.library/PrintIText



    NAME
	PrintIText -- Print text described by the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) argument.

    SYNOPSIS
	PrintIText( [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), IText, LeftOffset, TopOffset )
		    A0        A1     D0          D1

	VOID PrintIText( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) *, WORD, WORD );

    FUNCTION
	Prints the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) into the specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  Sets up the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	as specified by the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) values, then prints the text into the
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) at the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) x/y coordinates offset by the left/top
	arguments.  Note, though, that the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure itself
	may contain further text position coordinates: those coordinates
	and the Left/TopOffsets are added to obtain the true position of
	the text to be rendered.

	This routine does window layer clipping as appropriate -- if you
	print text outside of your window, your characters will be
	clipped at the window's edge, providing you pass your window's
	(layered) [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

	If the NextText field of the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) argument is non-NULL,
	the next [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) is rendered as well, and so on until some
	NextText field is NULL.

	[IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) with the ITextFont field NULL are displayed in the
	font of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  If the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) font is also NULL, the
	system default font, as set via the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57) tool, will be used.

    INPUTS
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) = the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) destination of the text
	IText = pointer to an instance of the structure [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655)
	LeftOffset = left offset of the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) into the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	TopOffset = top offset of the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) into the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

    RESULT
	None


    BUGS

    SEE ALSO
