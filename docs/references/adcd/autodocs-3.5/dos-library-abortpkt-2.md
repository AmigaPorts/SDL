---
title: dos.library/AbortPkt
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-abortpkt-2
functions: [DoPkt, SendPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/AbortPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbortPkt -- Aborts an asynchronous packet, if possible. (V36)

   SYNOPSIS
	AbortPkt(port, pkt)
		  D1    D2

	void AbortPkt(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, struct [DosPacket](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	This attempts to abort a packet sent earlier with [SendPkt](autodocs-3.5/dos-library-sendpkt-2.md) to a
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
	[SendPkt()](autodocs-3.5/dos-library-sendpkt-2.md), [DoPkt()](autodocs-3.5/dos-library-dopkt-2.md), [WaitPkt()](autodocs-3.5/dos-library-waitpkt-2.md)

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
