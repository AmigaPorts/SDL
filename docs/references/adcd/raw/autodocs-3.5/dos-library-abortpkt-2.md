# dos.library/AbortPkt



   NAME
	AbortPkt -- Aborts an asynchronous packet, if possible. (V36)

   SYNOPSIS
	AbortPkt(port, pkt)
		  D1    D2

	void AbortPkt(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *, struct [DosPacket](../Includes_and_Autodocs_3._guide/node05D9.html#line107) *)

   FUNCTION
	This attempts to abort a packet sent earlier with [SendPkt](../Includes_and_Autodocs_3._guide/node01B0.html) to a
	handler.  There is no guarantee that any given handler will allow
	a packet to be aborted, or if it is aborted whether function
	requested completed first or completely.  After calling AbortPkt(),
	you must wait for the packet to return before reusing it or
	deallocating it.

   INPUTS
	port - port the packet was sent to
	pkt  - the packet you wish aborted

   BUGS
	As of V37, this function does nothing.

   SEE ALSO
	[SendPkt()](../Includes_and_Autodocs_3._guide/node01B0.html), [DoPkt()](../Includes_and_Autodocs_3._guide/node0155.html), [WaitPkt()](../Includes_and_Autodocs_3._guide/node01D0.html)

