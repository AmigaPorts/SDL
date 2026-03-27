# exec.library/DeleteMsgPort



   NAME
	DeleteMsgPort - Free a message port created by [CreateMsgPort](../Includes_and_Autodocs_3._guide/node01FC.html)  (V36)

   SYNOPSIS
	DeleteMsgPort(msgPort)
		      a0

	void DeleteMsgPort(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	Frees a message port created by [CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html).  All messages that
	may have been attached to this port must have already been
	replied to.

   INPUTS
	msgPort - A message port.  NULL for no action.

   SEE ALSO
	[CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html), [amiga.lib/DeletePort()](../Includes_and_Autodocs_3._guide/node0035.html)

