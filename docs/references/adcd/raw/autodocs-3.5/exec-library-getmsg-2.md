# exec.library/GetMsg



   NAME
	GetMsg -- get next message from a message port

   SYNOPSIS
	message = GetMsg(port)
	D0		 A0

	struct [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) *GetMsg(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	This function receives a message from a given message port. It
	provides a fast, non-copying message receiving mechanism. The
	received message is removed from the message port.

	This function will not wait.  If a message is not present this
	function will return zero.  If a program must wait for a message,
	it can [Wait()](../Includes_and_Autodocs_3._guide/node0246.html) on the signal specified for the port or use the
	[WaitPort()](../Includes_and_Autodocs_3._guide/node0248.html) function.  There can only be one task waiting for any
	given port.

	Getting a message does not imply to the sender that the message is
	free to be reused by the sender.  When the receiver is finished
	with the message, it may [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) it back to the sender.


	Getting a signal does NOT always imply a message is ready.  More
	than one message may arrive per signal, and signals may show up
	without messages.  Typically you must loop to GetMsg() until it
	returns zero, then [Wait()](../Includes_and_Autodocs_3._guide/node0246.html) or [WaitPort()](../Includes_and_Autodocs_3._guide/node0248.html).

   INPUT
	port - a pointer to the receiver message port

   RESULT
	message - a pointer to the first message available.  If
		  there are no messages, return zero.
		  Callers must be prepared for zero at any time.

   SEE ALSO
	[PutMsg()](../Includes_and_Autodocs_3._guide/node0226.html), [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html), [WaitPort()](../Includes_and_Autodocs_3._guide/node0248.html), [Wait()](../Includes_and_Autodocs_3._guide/node0246.html), [exec/ports.h](../Includes_and_Autodocs_3._guide/node062E.html)

