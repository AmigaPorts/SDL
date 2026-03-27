# graphics.library/SetAPen



   NAME   
	SetAPen -- Set the primary pen for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   SYNOPSIS
	SetAPen( rp, pen )
		 a1  d0

	void SetAPen( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION
	Set the primary drawing pen for lines, fills, and text.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
	pen - (0-255)

   RESULT
	Changes the minterms in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to reflect new primary pen.
	Sets line drawer to restart pattern.

   BUGS

   SEE ALSO
	[SetBPen()](../Includes_and_Autodocs_3._guide/node031F.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

