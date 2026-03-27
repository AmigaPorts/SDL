# graphics.library/WaitBOVP



   NAME
	WaitBOVP -- [Wait](../Includes_and_Autodocs_3._guide/node0246.html) till vertical beam reached bottom of
		    this viewport.

   SYNOPSIS
	WaitBOVP( vp )
		  a0

	void WaitBOVP( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) * );

   FUNCTION
	Returns when the vertical beam has reached the bottom of this viewport

   INPUTS
	vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure

   RESULT
	This function will return sometime after the beam gets beyond
	the bottom of the viewport.  Depending on the multitasking load
	of the system, the actual beam position may be different than
	what would be expected in a lightly loaded system.

   BUGS
	Horrors! This function currently busy waits waiting for the
	beam to get to the right place.  It should use the copper
	interrupt to trigger and send signals like [WaitTOF](../Includes_and_Autodocs_3._guide/node033B.html) does.

   SEE ALSO
	[WaitTOF()](../Includes_and_Autodocs_3._guide/node033B.html) [VBeamPos()](../Includes_and_Autodocs_3._guide/node0337.html)

