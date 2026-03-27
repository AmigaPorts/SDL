---
title: exec.library/ReplyMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-replymsg-2
functions: [GetMsg, PutMsg]
libraries: [exec.library]
---

# exec.library/ReplyMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReplyMsg -- put a message to its reply port

   SYNOPSIS
	ReplyMsg(message)
		 A1

	void ReplyMsg(struct [Message](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function sends a message to its reply port.  This is usually
	done when the receiver of a message has finished and wants to
	return it to the sender (so that it can be re-used or deallocated,
	whatever).

	This call may be made from interrupts.

   INPUT
	message - a pointer to the message

   IMPLEMENTATION
	1> Places "NT_REPLYMSG" into LN_TYPE.
	2> Puts the message to the port specified by MN_REPLYPORT
	   If there is no replyport, sets LN_TYPE to "NT_FREEMSG" (use this
	   feature only with extreme care).

   SEE ALSO
	[GetMsg()](autodocs-3.5/exec-library-getmsg-2.md), [PutMsg()](autodocs-3.5/exec-library-putmsg-2.md), [exec/ports.h](autodocs-3.5/include-exec-ports-h.md)

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
