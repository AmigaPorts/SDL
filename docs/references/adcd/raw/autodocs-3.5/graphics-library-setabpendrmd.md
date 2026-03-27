# graphics.library/SetABPenDrMd



   NAME   
 	SetABPenDrMd -- Set pen colors and draw mode for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53). (V39)

   SYNOPSIS
	SetABPenDrMd( rp, apen, bpen, mode )
		 		  a1  d0     d1    d2

	void SetABPenDrMd( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, ULONG, ULONG, ULONG );

   FUNCTION
	Set the pen values and drawing mode for lines, fills and text.
	Get the bit definitions from rastport.h

   INPUTS
	rp - pointer to [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
	apen - primary pen value
	bpen - secondary pen value
	mode - 0-255, some combinations may not make much sense.

   RESULT
	The mode set is dependent on the bits selected.
	Changes minterms to reflect new drawing mode and colors.
	Sets line drawer to restart pattern.

	NOTES
	This call is essentially the same as a sequence of
	SetAPen()/SetBPen()/SetDrMD() calls, except that it is
	significantly faster. The minterms will only be generated
	once, or not at all if nothing changed (warning to illegal
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) pokers!).

   BUGS

   SEE ALSO
	[SetAPen()](../Includes_and_Autodocs_3._guide/node031E.html) [SetBPen()](../Includes_and_Autodocs_3._guide/node031F.html) [SetDrMd()](../Includes_and_Autodocs_3._guide/node0322.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

