# asl.library/FreeAslRequest



   NAME
	FreeAslRequest -- frees resources allocated by [AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html). (V36)

   SYNOPSIS
	FreeAslRequest(requester);
		       A0

	VOID FreeAslRequest(APTR);

   FUNCTION
	FreeAslRequest() frees any system resources allocated by
	[AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html). Once a requester has been freed, it can no
	longer be used with other calls to [AslRequest()](../Includes_and_Autodocs_3._guide/node005B.html).

   INPUTS
	requester - requester obtained from [AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html)

