# commodities.library/DisposeCxMsg



   NAME
	DisposeCxMsg -- delete a commodity message. (V36)

   SYNOPSIS
	DisposeCxMsg(cxm);
		     A0

	VOID DisposeCxMsg(struct CxMsg *);

   FUNCTION
	This function eliminates the commodity message pointed to by 'cxm'.
	Can be used to 'swallow' input events by disposing of every commodity
	message of type CXM_IEVENT.

	This function can only be called from within a custom object running
	on the input handler's context. It cannot be called from code running
	on a commodities' context, such as when receiving a CXM_IEVENT message
	from a sender object. CxMsg sent to a commodity program from a sender
	object must be sent back using [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html).

   INPUTS
	cxm - the commodity message to delete (must NOT be NULL)

