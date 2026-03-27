# dos.library/SendPkt



   NAME
	SendPkt -- Sends a packet to a handler (V36)

   SYNOPSIS
	SendPkt(packet, port, replyport)
		 D1     D2	D3

	void SendPkt(struct [DosPacket](../Includes_and_Autodocs_3._guide/node05D9.html#line107) *,struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *,struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)

   FUNCTION
	Sends a packet to a handler and does not wait.  All fields in the
	packet must be initialized before calling this routine.  The packet
	will be returned to replyport.  If you wish to use this with
	[WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html), use the address of your pr_MsgPort for replyport.

   INPUTS
	packet - packet to send, must be initialized and have a message.
	port   - pr_MsgPort of handler process to send to.
	replyport - [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) for the packet to come back to.

   NOTES
	Callable from a task.

   SEE ALSO
	[DoPkt()](../Includes_and_Autodocs_3._guide/node0155.html), [WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html), [FreeDosObject()](../Includes_and_Autodocs_3._guide/node0172.html), [AbortPkt()](../Includes_and_Autodocs_3._guide/node0139.html)

