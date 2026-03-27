---
title: exec.library/WaitPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-waitport-2
functions: [GetMsg, Wait]
libraries: [exec.library]
---

# exec.library/WaitPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WaitPort -- wait for a given port to be non-empty

   SYNOPSIS
	message = WaitPort(port)
	D0		   A0

	struct [Message](autodocs-3.5/include-exec-ports-h.md) *WaitPort(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function waits for the given port to become non-empty.  If
	necessary, the [Wait()](autodocs-3.5/exec-library-wait-2.md) function will be called to wait for the port
	signal.  If a message is already present at the port, this function
	will return immediately.  The return value is always a pointer to
	the first message queued (but it is not removed from the queue).

   CAUTION
	More than one message may be at the port when this returns.  It is
	proper to call the [GetMsg()](autodocs-3.5/exec-library-getmsg-2.md) function in a loop until all messages
	have been handled, then wait for more to arrive.

	To wait for more than one port, combine the signal bits from each
	port into one call to the [Wait()](autodocs-3.5/exec-library-wait-2.md) function, then use a [GetMsg()](autodocs-3.5/exec-library-getmsg-2.md) loop
	to collect any and all messages.  It is possible to get a signal
	for a port WITHOUT a message showing up.  Plan for this.

   INPUT
	port - a pointer to the message port

   RETURN
	message - a pointer to the first available message

   SEE ALSO
	[GetMsg()](autodocs-3.5/exec-library-getmsg-2.md)

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
