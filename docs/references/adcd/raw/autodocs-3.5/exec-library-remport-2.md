# exec.library/RemPort



   NAME
	RemPort -- remove a message port from the system

   SYNOPSIS
	RemPort(port)
		A1

	void RemPort(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	This function removes a message port structure from the system's
	message port list.  Subsequent attempts to rendezvous by name with
	this port will fail.

   INPUTS
	port - pointer to a message port

   SEE ALSO
	[AddPort()](../Includes_and_Autodocs_3._guide/node01DE.html), [FindPort()](../Includes_and_Autodocs_3._guide/node0208.html)

