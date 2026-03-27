# misc.resource/FreeMiscResource



   NAME
	FreeMiscResource - make a resource available for reallocation

   SYNOPSIS
	FreeMiscResource( unitNum )
			  D0

	void FreeMiscResource(ULONG);

   FUNCTION
	This routine frees one of the resources allocated
	by [AllocMiscResource](../Includes_and_Autodocs_3._guide/node04CE.html).  The resource is made available
	for reuse.

	FreeMiscResource must be called from the same task that
	called [AllocMiscResource](../Includes_and_Autodocs_3._guide/node04CE.html).  This function may not be called from
	interrupt code.

    INPUTS
	unitNum - the number of the miscellaneous resource to be freed.

    RESULTS
	Frees the appropriate resource.

    BUGS

    SEE ALSO
	resources/misc.i, [AllocMiscResource()](../Includes_and_Autodocs_3._guide/node04CE.html)

