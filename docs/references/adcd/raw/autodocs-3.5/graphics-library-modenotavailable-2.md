# graphics.library/ModeNotAvailable



   NAME
	ModeNotAvailable -- check to see if a DisplayID isn't available. (V36)

   SYNOPSIS
	error =  ModeNotAvailable( modeID )
	d0		           d0

	ULONG	ModeNotAvailable( ULONG);

   FUNCTION
	returns an error code, indicating why this modeID is not available,
	or NULL if there is no reason known why this mode should not be there.

   INPUTS
	modeID -- a 32 bit DisplayInfoRecord identifier.

   RESULT
	error -- a general indication of why this modeID is not available,
		 or NULL if there is no reason why it shouldn't be available.

   NOTE
	ULONG return values from this function are a proper superset of the
	DisplayInfo.NotAvailable field (defined in [graphics/displayinfo.h)](../Includes_and_Autodocs_3._guide/node05FF.html).

	ModeNotAvailable() will return INVALID_ID when given a non-existant
	moe ID.

   BUGS

   SEE ALSO
	[graphics/displayinfo.h](../Includes_and_Autodocs_3._guide/node05FF.html), [GetVPModeID()](../Includes_and_Autodocs_3._guide/node02ED.html)

