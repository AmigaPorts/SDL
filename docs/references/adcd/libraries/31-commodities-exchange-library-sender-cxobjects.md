---
title: 31 Commodities Exchange Library / Sender CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-sender-cxobjects
functions: [AttachCxObj, CxMsgData]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Sender CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [filter CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) by itself is not especially useful.  It needs some other
[CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) attached to it.  A commodity interested in knowing if a specific
key was pressed uses a filter to detect and divert the corresponding
[CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) down the filter's personal list.  The filter does this without
letting the commodity know what happened.  The sender CxObject can be
attached to a filter to notify a commodity that it received a CxMessage.
[CxSender()](autodocs-2.0/amiga-lib-cxsender.md) is a macro that creates a sender CxObject.


```c
    senderCxObj = CxObj *CxSender(struct MsgPort *senderport, LONG cxmID);
```
[CxSender()](autodocs-2.0/amiga-lib-cxsender.md) supplies the sender with an Exec message port and an ID.  For
every [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) a sender receives, it sends a new CxMessage to the Exec
message port passed in CxSender().  Normally, the commodity creates this
port.  It is not unusual for a commodity's [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md) and sender(s) to share
an Exec message port.  The [HotKey.c](libraries/lib-examples-hotkey-c.md) example does this to avoid creating
unnecessary message ports.  A sender uses the ID (cxmID) passed to
CxSender() as the ID for all the CxMessages that the it transmits.  A
commodity uses the ID to monitor CxMessages from several senders at a
single message port.

A sender does several things when it receives a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md).  First, it
duplicates the CxMessage's corresponding input event and creates a new
CxMessage.  Then, it points the new CxMessage's data field to the copy of
the input event and sets the new CxMessage's ID to the ID passed to
[CxSender()](autodocs-2.0/amiga-lib-cxsender.md).  Finally, it sends the new CxMessage to the port passed to
CxSender(), asynchronously.

Because HotKey uses only one message port between its [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md) and sender
object, it has to extract the [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md)'s type so it can tell if it is a
CXM_IEVENT or a CXM_COMMAND.  If HotKey gets a CXM_IEVENT, it compares the
CxMessage's ID to the sender's ID, EVT_HOTKEY, to see which sender sent
the CxMessage.  Of course HotKey has only one sender, so it only checks
for only one ID.  If it had more senders, HotKey would check for the ID of
each of the other senders as well.

Although HotKey doesn't use it, a [CXM_IEVENT CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) contains a pointer
to the copy of an input event.  A commodity can extract this pointer
( using [CxMsgData()](libraries/31-commodities-exchange-library-cxmessages.md) ) if it needs to examine the input event copy.  This
pointer is only valid before the CxMessage reply.  Note that it does not
make any sense to modify the input event copy.

Senders are attached almost exclusively to [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) that filter out most
input events (usually a [filter CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md)).  Because a sender sends a
[CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) for every single input event it gets, it should only get a
select few input events.  The [AttachCxObj()](libraries/31-commodities-exchange-library-connecting-cxobjects.md) function can add a CxObject to
the end of a filter's (or some other filtering CxObject's) personal list.
A commodity should not attach a CxObject to a sender as a sender ignores
any CxObjects in its personal list.

---

## See Also

- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
