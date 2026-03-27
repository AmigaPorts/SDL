# intuition.library/IntuiTextLength



    NAME
	IntuiTextLength -- Return the length (pixel-width) of an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655).

    SYNOPSIS
	Length = IntuiTextLength( IText )
	D0                        A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) IntuiTextLength( struct [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) * );

    FUNCTION
	This routine accepts a pointer to an instance of an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure,
	and returns the length (the pixel-width) of the string which that
	instance of the structure represents.

	NOTE: if the Font pointer of your [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure is set to NULL,
	you'll get the pixel-width of your text in terms of the current system
	default font.  You may wish to be sure that the field IText->ITextFont
	for 'default font' text is equal to the Font field of the screen it is
	being measured for.

    INPUTS
	IText = pointer to an instance of an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure

    RESULT
	Returns the pixel-width of the text specified by the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) data

    BUGS
	Would do better to take a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) as argument, so that a NULL in
	the Font pointer would lead automatically to the font for the
	intended target [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), rather than the system default font.

    SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)

