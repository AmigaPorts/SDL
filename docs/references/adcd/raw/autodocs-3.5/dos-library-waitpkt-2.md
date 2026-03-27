# dos.library/WaitPkt



   NAME
	WaitPkt -- Waits for a packet to arrive at your pr_MsgPort (V36)

   SYNOPSIS
	packet = WaitPkt()
	D0

	struct [DosPacket](../Includes_and_Autodocs_3._guide/node05D9.html#line107) *WaitPkt(void);

   FUNCTION
	Waits for a packet to arrive at your pr_MsgPort.  If anyone has
	installed a packet wait function in pr_PktWait, it will be called.
	The message will be automatically GetMsg()ed so that it is no longer
	on the port.  It assumes the message is a dos packet.  It is NOT
	guaranteed to clear the signal for the port.

   RESULT
	packet - the packet that arrived at the port (from ln_Name of message).

   SEE ALSO
	[SendPkt()](../Includes_and_Autodocs_3._guide/node01B0.html), [DoPkt()](../Includes_and_Autodocs_3._guide/node0155.html), [AbortPkt()](../Includes_and_Autodocs_3._guide/node0139.html)

