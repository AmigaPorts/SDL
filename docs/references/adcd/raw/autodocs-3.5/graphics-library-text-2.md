# graphics.library/Text



   NAME
	Text -- [Write](../Includes_and_Autodocs_3._guide/node01D1.html) text characters (no formatting).

   SYNOPSIS
	Text(rp, string, length)
	     A1  A0      D0-0:16

	void Text(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), WORD);

   FUNCTION
	This graphics function writes printable text characters to the
	specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) at the current position.  No control meaning
	is applied to any of the characters, thus only text on the
	current line is output.

	The current position in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) is updated to the next
	character position.
	If the characters displayed run past the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) boundary,
	the current position is truncated to the boundary, and
	thus does not equal the old position plus the text length.

   INPUTS
	rp     - a pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) which describes where the
	         text is to be output
	string - the address of string to output
	length - the number of characters in the string.
	         If zero, there are no characters to be output.

   NOTES
	o   This function may use the blitter.
	o   Changing the text direction with RastPort->TxSpacing is
	    not supported.

   BUGS
	For V34 and earlier:
	o   The maximum string length (in pixels) is limited to
	    (1024 - 16 = 1008) pixels wide.
	o   A text string whose last character(s) have a
	    tf_CharLoc size component that extends to the right of
	    the rightmost of the initial and final CP positions
	    will be (inappropriately) clipped.

   SEE ALSO
	[Move()](../Includes_and_Autodocs_3._guide/node0301.html)  [TextLength()](../Includes_and_Autodocs_3._guide/node0335.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

