---
title: exec.library/GetMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-getmsg-2
functions: [GetMsg, PutMsg, ReplyMsg, Wait, WaitPort]
libraries: [exec.library]
---

# exec.library/GetMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetMsg -- get next message from a message port

   SYNOPSIS
	message = GetMsg(port)
	D0		 A0

	struct [Message](autodocs-3.5/include-exec-ports-h.md) *GetMsg(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function receives a message from a given message port. It
	provides a fast, non-copying message receiving mechanism. The
	received message is removed from the message port.

	This function will not wait.  If a message is not present this
	function will return zero.  If a program must wait for a message,
	it can [Wait()](autodocs-3.5/exec-library-wait-2.md) on the signal specified for the port or use the
	[WaitPort()](autodocs-3.5/exec-library-waitport-2.md) function.  There can only be one task waiting for any
	given port.

	Getting a message does not imply to the sender that the message is
	free to be reused by the sender.  When the receiver is finished
	with the message, it may [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) it back to the sender.


	Getting a signal does NOT always imply a message is ready.  More
	than one message may arrive per signal, and signals may show up
	without messages.  Typically you must loop to GetMsg() until it
	returns zero, then [Wait()](autodocs-3.5/exec-library-wait-2.md) or [WaitPort()](autodocs-3.5/exec-library-waitport-2.md).

   INPUT
	port - a pointer to the receiver message port

   RESULT
	message - a pointer to the first message available.  If
		  there are no messages, return zero.
		  Callers must be prepared for zero at any time.

   SEE ALSO
	[PutMsg()](autodocs-3.5/exec-library-putmsg-2.md), [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md), [WaitPort()](autodocs-3.5/exec-library-waitport-2.md), [Wait()](autodocs-3.5/exec-library-wait-2.md), [exec/ports.h](autodocs-3.5/include-exec-ports-h.md)

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
