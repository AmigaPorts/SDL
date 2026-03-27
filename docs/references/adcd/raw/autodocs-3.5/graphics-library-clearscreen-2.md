# graphics.library/ClearScreen



   NAME
	ClearScreen -- Clear from current position to end of [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   SYNOPSIS
	ClearScreen(rp)
	            A1

	void ClearScreen(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Clear a rectangular swath from the current position to the
	right edge of the rastPort with [ClearEOL](../Includes_and_Autodocs_3._guide/node02BF.html), then clear the rest
	of the screen from just beneath the swath to the bottom of
	the rastPort.
	Clearing consists of setting the color of the swath to zero,
	or, if the DrawMode is 2, to the BgPen.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

   NOTES
	o   This function may use the blitter.

   SEE ALSO
	[ClearEOL()](../Includes_and_Autodocs_3._guide/node02BF.html)  [Text()](../Includes_and_Autodocs_3._guide/node0332.html)  [SetRast()](../Includes_and_Autodocs_3._guide/node0327.html)
	[graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

