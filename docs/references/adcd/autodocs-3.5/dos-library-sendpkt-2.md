---
title: dos.library/SendPkt
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-sendpkt-2
functions: [AllocDosObject, DoPkt, FreeDosObject, WaitPkt]
libraries: [dos.library]
---

# dos.library/SendPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SendPkt -- Sends a packet to a handler (V36)

   SYNOPSIS
	SendPkt(packet, port, replyport)
		 D1     D2	D3

	void SendPkt(struct [DosPacket](autodocs-3.5/include-dos-dosextens-h.md) *,struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *,struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)

   FUNCTION
	Sends a packet to a handler and does not wait.  All fields in the
	packet must be initialized before calling this routine.  The packet
	will be returned to replyport.  If you wish to use this with
	[WaitPkt()](autodocs-3.5/dos-library-waitpkt-2.md), use the address of your pr_MsgPort for replyport.

   INPUTS
	packet - packet to send, must be initialized and have a message.
	port   - pr_MsgPort of handler process to send to.
	replyport - [MsgPort](autodocs-3.5/include-exec-ports-h.md) for the packet to come back to.

   NOTES
	Callable from a task.

   SEE ALSO
	[DoPkt()](autodocs-3.5/dos-library-dopkt-2.md), [WaitPkt()](autodocs-3.5/dos-library-waitpkt-2.md), [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md), [FreeDosObject()](autodocs-3.5/dos-library-freedosobject-2.md), [AbortPkt()](autodocs-3.5/dos-library-abortpkt-2.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
