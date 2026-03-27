# graphics.library/SetDrMd



   NAME   
 	SetDrMd -- Set drawing mode for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   SYNOPSIS
	SetDrMd( rp, mode )
		 a1  d0:8

	void SetDrMd( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION
	Set the drawing mode for lines, fills and text.
	Get the bit definitions from rastport.h

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
	mode - 0-255, some combinations may not make much sense.

   RESULT
	The mode set is dependent on the bits selected.
	Changes minterms to reflect new drawing mode.
	Sets line drawer to restart pattern.

   BUGS

   SEE ALSO
	[SetAPen()](../Includes_and_Autodocs_3._guide/node031E.html) [SetBPen()](../Includes_and_Autodocs_3._guide/node031F.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

