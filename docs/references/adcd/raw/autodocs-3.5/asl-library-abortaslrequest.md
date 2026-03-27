# asl.library/AbortAslRequest



   NAME
	AbortAslRequest -- attempt to abort an asl requester. (V44)

   SYNOPSIS
	AbortAslRequest(requester);
	                   A0

	VOID AbortAslRequest(APTR requester);

   FUNCTION
	The different types of asl requesters are modal (as of V44). Yet at
	times it may be necessary to abort a modal requester from a different
	task context. AbortAslRequest() will attempt to tell the modal asl
	requester provided to shut down and perform as if the user had clicked
	on the requester's window close gadget. This may take some time to
	complete; be prepared to handle this.

   INPUTS
	requester - requester obtained from [AllocAslRequest()](../Includes_and_Autodocs_3._guide/node0059.html), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AslRequest()](../Includes_and_Autodocs_3._guide/node005B.html)

