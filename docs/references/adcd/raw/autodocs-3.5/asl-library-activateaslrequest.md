# asl.library/ActivateAslRequest



   NAME
	ActivateAslRequest -- attempt to activate an asl requester. (V44)

   SYNOPSIS
	ActivateAslRequest(requester);
	                      A0

	VOID ActivateAslRequest(APTR requester);

   FUNCTION
	The different types of asl requesters are modal (as of V44). Yet at
	times it may be necessary to activate a modal requester from a different
	task context.

   INPUTS
	requester - requester obtained from [AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AslRequest()](../Includes_and_Autodocs_3._guide/node005B.html)

