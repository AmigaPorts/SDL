# exec.library/CreateMsgPort



   NAME
	CreateMsgPort - [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) and initialize a new message port  (V36)

   SYNOPSIS
	CreateMsgPort()

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) * CreateMsgPort(void);

   FUNCTION
	Allocates and initializes a new message port.  The message list
	of the new port will be prepared for use (via NewList).  A signal
	bit will be allocated, and the port will be set to signal your
	task when a message arrives (PA_SIGNAL).

	You *must* use [DeleteMsgPort()](../Includes_and_Autodocs_3._guide/node0201.html) to delete ports created with
	CreateMsgPort()!

   RESULT
	[MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) - A new [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) structure ready for use, or NULL if out of
		memory or signals.  If you wish to add this port to the public
		port list, fill in the ln_Name and ln_Pri fields, then call
		[AddPort()](../Includes_and_Autodocs_3._guide/node01DE.html).  Don't forget RemPort()!

   SEE ALSO
	[DeleteMsgPort()](../Includes_and_Autodocs_3._guide/node0201.html), [exec/AddPort()](../Includes_and_Autodocs_3._guide/node01DE.html), [exec/ports.h](../Includes_and_Autodocs_3._guide/node062E.html), [amiga.lib/CreatePort()](../Includes_and_Autodocs_3._guide/node002A.html)

