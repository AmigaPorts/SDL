# graphics.library/SetOPen



   NAME
	SetOPen -- Change the Area OutLine pen and turn on Outline
			mode for areafills.

   SYNOPSIS
	SetOPen(rp, pen)

	void SetOPen( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

   FUNCTION
	This is implemented as a c-macro.
	Pen is the pen number that will be used to draw a border
	around an areafill during [AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html).

   INPUTS
	rp = pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
	pen = number  between 0-255

   BUGS

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

