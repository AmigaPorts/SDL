---
title: dos.library/WaitPkt
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-waitpkt-2
functions: [DoPkt, GetMsg, SendPkt, WaitPkt]
libraries: [dos.library, exec.library]
---

# dos.library/WaitPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WaitPkt -- Waits for a packet to arrive at your pr_MsgPort (V36)

   SYNOPSIS
	packet = WaitPkt()
	D0

	struct [DosPacket](autodocs-3.5/include-dos-dosextens-h.md) *WaitPkt(void);

   FUNCTION
	Waits for a packet to arrive at your pr_MsgPort.  If anyone has
	installed a packet wait function in pr_PktWait, it will be called.
	The message will be automatically GetMsg()ed so that it is no longer
	on the port.  It assumes the message is a dos packet.  It is NOT
	guaranteed to clear the signal for the port.

   RESULT
	packet - the packet that arrived at the port (from ln_Name of message).

   SEE ALSO
	[SendPkt()](autodocs-3.5/dos-library-sendpkt-2.md), [DoPkt()](autodocs-3.5/dos-library-dopkt-2.md), [AbortPkt()](autodocs-3.5/dos-library-abortpkt-2.md)

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
