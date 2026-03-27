---
title: exec.library/PutMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-putmsg-2
functions: [GetMsg, ReplyMsg]
libraries: [exec.library]
---

# exec.library/PutMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PutMsg -- put a message to a message port

   SYNOPSIS
	PutMsg(port, message)
	       A0    A1

	void PutMsg(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, struct [Message](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function attaches a message to the end of a given message port.
	It provides a fast, non-copying message sending mechanism.

	Messages can be attached to only one port at a time.  The message
	body can be of any size or form.  Because messages are not copied,
	cooperating tasks share the same message memory.  The sender task
	must not recycle the message until it has been replied by the
	receiver.  Of course this depends on the message handling conventions
	setup by the involved tasks.  If the ReplyPort field is non-zero,
	when the message is replied by the receiver, it will be sent back to
	that port.

	Any one of the following actions can be set to occur when a message
	is put:

		1. no special action
		2. signal a given task (specified by MP_SIGTASK)
		3. cause a software interrupt (specified by MP_SIGTASK)

	The action is selected depending on the value found in the MP_FLAGS
	of the destination port.

   IMPLEMENTATION
	1.  Sets the LN_TYPE field to "NT_MESSAGE".
	2.  Attaches the message to the destination port.
	3.  Performs the specified arrival action at the destination.

   INPUT
	port - pointer to a message port
	message - pointer to a message

   SEE ALSO
	[GetMsg()](autodocs-3.5/exec-library-getmsg-2.md), [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md), [exec/ports.h](autodocs-3.5/include-exec-ports-h.md)

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
