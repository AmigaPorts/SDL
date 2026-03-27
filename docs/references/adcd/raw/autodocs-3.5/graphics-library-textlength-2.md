# graphics.library/TextLength



   NAME
	TextLength -- Determine raster length of text data.

   SYNOPSIS
	length = TextLength(rp, string, count)
	D0                  A1  A0      D0:16

	WORD TextLength(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), WORD);

   FUNCTION
	This graphics function determines the length that text data
	would occupy if output to the specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) with the
	current attributes.  The length is specified as the number of
	raster dots: to determine what the current position would be
	after a [Text()](../Includes_and_Autodocs_3._guide/node0332.html) using this string, add the length to cp_x
	(cp_y is unchanged by [Text()](../Includes_and_Autodocs_3._guide/node0332.html)).  Use the newer [TextExtent()](../Includes_and_Autodocs_3._guide/node0333.html) to
	get more information.

   INPUTS
	rp     - a pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) which describes where the
	         text attributes reside.
	string - the address of string to determine the length of
	count  - the string length.  If zero, there are no characters
	         in the string.

   RESULTS
	length - the number of pixels in x this text would occupy, not
	         including any negative kerning that may take place at
	         the beginning of the text string, nor taking into
	         account the effects of any clipping that may take
	         place.

   NOTES
	Prior to V36, the result length occupied only the low word of
	d0 and was not sign extended into the high word.

   BUGS
	A length that would overflow single word arithmetic is not
	calculated correctly.

   SEE ALSO
	[TextExtent()](../Includes_and_Autodocs_3._guide/node0333.html)  [Text()](../Includes_and_Autodocs_3._guide/node0332.html)  [TextFit()](../Includes_and_Autodocs_3._guide/node0334.html)
	[graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

