# amiga.lib/DeletePort



   NAME
	DeletePort - free a message port created by [CreatePort()](../Includes_and_Autodocs_3._guide/node002A.html)

   SYNOPSIS
	DeletePort(port)

	VOID DeletePort(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	Frees a message port created by [CreatePort](../Includes_and_Autodocs_3._guide/node002A.html). All messages that
	may have been attached to this port must have already been
	replied before this function is called.

   INPUTS
	port - message port to delete

   SEE ALSO
	[CreatePort()](../Includes_and_Autodocs_3._guide/node002A.html)

