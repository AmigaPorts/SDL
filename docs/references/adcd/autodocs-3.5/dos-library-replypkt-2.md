---
title: dos.library/ReplyPkt
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-replypkt-2
functions: [DoPkt, IoErr, ReplyPkt, SendPkt, WaitPkt]
libraries: [dos.library]
---

# dos.library/ReplyPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReplyPkt -- replies a packet to the person who sent it to you (V36)

   SYNOPSIS
	ReplyPkt(packet, result1, result2)
		   D1      D2       D3

	void ReplyPkt(struct [DosPacket](autodocs-3.5/include-dos-dosextens-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG)

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
	[DoPkt()](autodocs-3.5/dos-library-dopkt-2.md), [SendPkt()](autodocs-3.5/dos-library-sendpkt-2.md), [WaitPkt()](autodocs-3.5/dos-library-waitpkt-2.md), [IoErr()](autodocs-3.5/dos-library-ioerr-2.md)

---

## See Also

- [DoPkt — dos.library](../autodocs/dos.library.md#dopkt)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [ReplyPkt — dos.library](../autodocs/dos.library.md#replypkt)
- [SendPkt — dos.library](../autodocs/dos.library.md#sendpkt)
- [WaitPkt — dos.library](../autodocs/dos.library.md#waitpkt)
