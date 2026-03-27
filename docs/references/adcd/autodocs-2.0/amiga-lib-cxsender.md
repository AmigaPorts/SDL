---
title: amiga.lib/CxSender
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-cxsender
functions: [CreateCxObj, CxMsgID, PutMsg, ReplyMsg]
libraries: [commodities.library, exec.library]
---

# amiga.lib/CxSender

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxSender -- create a commodity sender object. (V36)
```
SYNOPSIS

```c
    senderObj = CxSender(port,id)

    CxObj *CxSender(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,LONG);
```
FUNCTION

```c
    This function creates a Commodities sender object. The action
    of this object on receiving a Commodities message is to copy the
    Commodities message into a standard Exec [Message](autodocs-2.0/includes-exec-ports-h.md), to put the value
    'id' in the message as well, and to send the message off to the
    message port 'port'.

    The value 'id' is used so that an application can monitor
    messages from several senders at a single port. It can be retrieved
    from the Exec message by using the function [CxMsgID()](autodocs-2.0/commodities-library-cxmsgid.md). The value can
    be a simple integer ID, or a pointer to some application data
    structure.

    Note that Exec messages sent by sender objects arrive
    asynchronously at the destination port. Do not assume anything about
    the status of the Commodities message which was copied into the Exec
    message you received.

    All Exec messages sent to your ports must be replied. Messages may be
    replied after the sender object has been deleted.

    This function is a C-language macro for [CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), defined
    in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md).
```
INPUTS

    port - the port for the sender to send messages to
    id - the id of the messages sent by the sender
RESULTS

    semderObj - a pointer to the sender object, or NULL if it could
                not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), [commodities.library/CxMsgID()](autodocs-2.0/commodities-library-cxmsgid.md),
    [exec.library/PutMsg()](autodocs-2.0/exec-library-putmsg.md), [exec.library/ReplyMsg()](autodocs-2.0/exec-library-replymsg.md)
```

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
