# commodities.library/RouteCxMsg



   NAME
	RouteCxMsg -- set the next destination of a commodity message. (V36)

   SYNOPSIS
	RouteCxMsg(cxm,co);
		   A0  A1

	VOID RouteCxMsg(struct CxMsg *,[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *);

   FUNCTION
	Establishes the next destination of a commodity message
	to be 'co', which must be a valid commodity object, and
	must be linked in ultimately to commodities' object list.

	Routing of an object is analogous to a 'goto' in a program.
	There is no effect on the message's routing stack.

   INPUTS
	cxm - the commodity message to route (must NOT be NULL)
	co - the commodity object to route the message to (must NOT be NULL)

   SEE ALSO
	[DivertCxMsg()](../Includes_and_Autodocs_3._guide/node00EE.html)

