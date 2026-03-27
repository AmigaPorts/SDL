# graphics.library/ClearEOL



   NAME
	ClearEOL -- Clear from current position to end of line.

   SYNOPSIS
	ClearEOL(rp)
	         A1

	void ClearEOL(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Clear a rectangular swath from the current position to the
	right edge of the rastPort.  The height of the swath is taken
	from that of the current text font, and the vertical
	positioning of the swath is adjusted by the text baseline,
	such that text output at this position would lie wholly on
	this newly cleared area.
	Clearing consists of setting the color of the swath to zero,
	or, if the DrawMode is 2, to the BgPen.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

   RESULT

   NOTES
	o   This function may use the blitter.

   SEE ALSO
	[Text()](../Includes_and_Autodocs_3._guide/node0332.html)  [ClearScreen()](../Includes_and_Autodocs_3._guide/node02C2.html)  [SetRast()](../Includes_and_Autodocs_3._guide/node0327.html)
	[graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

