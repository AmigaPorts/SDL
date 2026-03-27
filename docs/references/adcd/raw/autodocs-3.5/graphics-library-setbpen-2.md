# graphics.library/SetBPen



   NAME   
	SetBPen -- Set secondary pen for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   SYNOPSIS
	SetBPen( rp, pen )
		 a1  d0

	void SetBPen( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION
	Set the secondary drawing pen for lines, fills, and text.

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
	pen - (0-255)

   RESULT
	Changes the minterms in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to reflect new secondary pen.
	Sets line drawer to restart pattern.

   BUGS

    SEE ALSO
	[SetAPen()](../Includes_and_Autodocs_3._guide/node031E.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

