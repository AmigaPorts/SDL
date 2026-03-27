# exec.library/ReplyMsg



   NAME
	ReplyMsg -- put a message to its reply port

   SYNOPSIS
	ReplyMsg(message)
		 A1

	void ReplyMsg(struct [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) *);

   FUNCTION
	This function sends a message to its reply port.  This is usually
	done when the receiver of a message has finished and wants to
	return it to the sender (so that it can be re-used or deallocated,
	whatever).

	This call may be made from interrupts.

   INPUT
	message - a pointer to the message

   IMPLEMENTATION
	1> Places "NT_REPLYMSG" into LN_TYPE.
	2> Puts the message to the port specified by MN_REPLYPORT
	   If there is no replyport, sets LN_TYPE to "NT_FREEMSG" (use this
	   feature only with extreme care).

   SEE ALSO
	[GetMsg()](../Includes_and_Autodocs_3._guide/node0214.html), [PutMsg()](../Includes_and_Autodocs_3._guide/node0226.html), [exec/ports.h](../Includes_and_Autodocs_3._guide/node062E.html)

