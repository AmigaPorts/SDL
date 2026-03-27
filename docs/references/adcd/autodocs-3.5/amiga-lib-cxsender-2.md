---
title: amiga.lib/CxSender
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxsender-2
functions: [CreateCxObj, CxMsgID, PutMsg, ReplyMsg]
libraries: [commodities.library, exec.library]
---

# amiga.lib/CxSender

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxSender -- create a commodity sender object. (V36)

   SYNOPSIS
	senderObj = CxSender(port,id)

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxSender(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *,LONG);

   FUNCTION
	This function creates a Commodities sender object. The action
	of this object on receiving a Commodities message is to copy the
	Commodities message into a standard Exec [Message](autodocs-3.5/include-exec-ports-h.md), to put the value
	'id' in the message as well, and to send the message off to the
	message port 'port'.

	The value 'id' is used so that an application can monitor
	messages from several senders at a single port. It can be retrieved
	from the Exec message by using the function [CxMsgID()](autodocs-3.5/commodities-library-cxmsgid-2.md). The value can
	be a simple integer ID, or a pointer to some application data
	structure.

	Note that Exec messages sent by sender objects arrive
	asynchronously at the destination port. Do not assume anything about
	the status of the Commodities message which was copied into the Exec
	message you received.

	All Exec messages sent to your ports must be replied. Messages may be
	replied after the sender object has been deleted.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	port - the port for the sender to send messages to
	id - the id of the messages sent by the sender

   RESULTS
	senderObj - a pointer to the sender object, or NULL if it could
		    not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [commodities.library/CxMsgID()](autodocs-3.5/commodities-library-cxmsgid-2.md),
	[exec.library/PutMsg()](autodocs-3.5/exec-library-putmsg-2.md), [exec.library/ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md)

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
