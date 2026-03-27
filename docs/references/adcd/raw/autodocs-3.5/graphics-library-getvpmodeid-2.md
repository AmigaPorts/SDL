# graphics.library/GetVPModeID



   NAME
	GetVPModeID -- get the 32 bit DisplayID from a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46). (V36)

   SYNOPSIS
	modeID =  GetVPModeID( vp )
	d0		       a0

	ULONG GetVPModeID( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION
	returns the normal display modeID, if one is currently  associated
	with this [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46).

   INPUTS
	vp -- pointer to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure.

   RESULT

	modeID -- a 32 bit DisplayInfoRecord identifier associated with
		  this [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46), or INVALID_ID.

   NOTES
	Test the return value of this function against INVALID_ID, not NULL.
	(INVALID_ID is defined in [graphics/displayinfo.h)](../Includes_and_Autodocs_3._guide/node05FF.html).

   BUGS

   SEE ALSO
	[graphics/displayinfo.h](../Includes_and_Autodocs_3._guide/node05FF.html), [ModeNotAvailable()](../Includes_and_Autodocs_3._guide/node0300.html)

