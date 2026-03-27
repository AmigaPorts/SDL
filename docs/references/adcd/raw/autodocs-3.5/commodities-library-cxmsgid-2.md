# commodities.library/CxMsgID



   NAME
	CxMsgID -- obtain the ID of a commodity message. (V36)

   SYNOPSIS
	id = CxMsgID(cxm);
	D0	     A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CxMsgID(struct CxMsg *);

   FUNCTION
	This function returns the value associated with the cause or source
	of the commodity message 'cxm'. Values are provided by the application
	when a sender or custom object is created.

   INPUTS
	cxm - the commodity message to inquire about (must NOT be NULL)

   RESULTS
	id - if not specified by the application, the ID value of a
	     commodity message will be 0. It is suggested that using
	     non-zero values in your program as a rule may identify some
	     possible errors.

   SEE ALSO
	[cx_lib/CxSender()](../Includes_and_Autodocs_3._guide/node0030.html), [cx_lib/CxCustom()](../Includes_and_Autodocs_3._guide/node002D.html)

