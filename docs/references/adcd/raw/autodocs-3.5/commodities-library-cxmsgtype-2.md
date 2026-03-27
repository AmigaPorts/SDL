# commodities.library/CxMsgType



   NAME
	CxMsgType -- obtain the type of a commodity message. (V36)

   SYNOPSIS
	type = CxMsgType(cxm);
	D0		 A0

	ULONG CxMsgType(struct CxMsg *);

   FUNCTION
	This function returns the type of a commodity message. Possible values
	of 'type' are defined in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html). Most commodity
	messages are of type CXM_IEVENT.

   INPUTS
	cxm - the commodity message to inquire about (must NOT be NULL)

   RESULTS
   	type - the type of the commodity message, possible values are defined
	       in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html)

