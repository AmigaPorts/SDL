# dos.library/ReplyPkt



   NAME
	ReplyPkt -- replies a packet to the person who sent it to you (V36)

   SYNOPSIS
	ReplyPkt(packet, result1, result2)
		   D1      D2       D3

	void ReplyPkt(struct [DosPacket](../Includes_and_Autodocs_3._guide/node05D9.html#line107) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG)

   FUNCTION
	This returns a packet to the process which sent it to you.  In
	addition, puts your pr_MsgPort address in dp_Port, so using ReplyPkt()
	again will send the message to you.  (This is used in "ping-ponging"
	packets between two processes).  It uses result 1 & 2 to set the
	dp_Res1 and dp_Res2 fields of the packet.

   INPUTS
	packet  - packet to reply, assumed to set up correctly.
	result1 - first result
	result2 - secondary result

   SEE ALSO
	[DoPkt()](../Includes_and_Autodocs_3._guide/node0155.html), [SendPkt()](../Includes_and_Autodocs_3._guide/node01B0.html), [WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html), [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html)

