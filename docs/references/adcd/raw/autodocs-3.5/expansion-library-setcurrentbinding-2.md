# expansion.library/SetCurrentBinding



   NAME
	SetCurrentBinding - sets static board configuration area

   SYNOPSIS
	SetCurrentBinding( currentBinding, size )
	                   A0		   D0:16

   FUNCTION
	This function records the contents of the "currentBinding"
	structure in a private place.  It may be read via
	[GetCurrentBinding()](../Includes_and_Autodocs_3._guide/node0265.html).  This is really a kludge, but it is
	the only way to pass extra arguments to a newly configured
	device.

	A [CurrentBinding](../Includes_and_Autodocs_3._guide/node05F1.html#line60) structure has the name of the currently
	loaded file, the product string that was associated with
	this driver, and a pointer to the head of a singly linked
	list of [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structures (linked through the cd_NextCD
	field).

	Many devices may not need this information; they have hard
	coded into themselves their manufacture number.  It is
	recommended that you at least check that you can deal with
	the product code in the linked [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structures.

   INPUTS
	currentBinding - a pointer to a [CurrentBinding](../Includes_and_Autodocs_3._guide/node05F1.html#line60) structure

	size - The size of the user's binddriver structure.  No
	    more than this much data will be copied.  If size is
	    less than the library's idea a [CurrentBinding](../Includes_and_Autodocs_3._guide/node05F1.html#line60) size,
	    then the library's structure will be null padded.

   SEE ALSO
	[GetCurrentBinding()](../Includes_and_Autodocs_3._guide/node0265.html)

