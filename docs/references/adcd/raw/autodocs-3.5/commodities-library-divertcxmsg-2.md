# commodities.library/DivertCxMsg



   NAME
	DivertCxMsg -- send a commodity message down an object list. (V36)

   SYNOPSIS
	DivertCxMsg(cxm,headObj,returnObj);
		    A0  A1      A2

	VOID DivertCxMsg(struct CxMsg *,[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *,[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *);

   FUNCTION
	This function sends the commodity message 'cxm' down the list of
	objects attached to 'headObj'. The pointer 'returnObj' is first
	pushed onto the routing stack of 'cxm' so that when the end of the
	list of 'headObj' is reached the SUCCESSOR of 'returnObj' is the
	next destination.

	For example, when a filter finds a match with a message, the
	message is diverted down the filter's list like this:

	  DivertCxMsg(cxm,filter,filter);

   INPUTS
	cxm - the commodity message to divert (must NOT be NULL)
	headObj - the list of objects to divert the message to
	returnObj - the object to use as a place holder

   SEE ALSO
	[RouteCxMsg()](../Includes_and_Autodocs_3._guide/node00F5.html)

