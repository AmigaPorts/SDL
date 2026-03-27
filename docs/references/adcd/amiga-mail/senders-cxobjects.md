---
title: Senders CxObjects
manual: amiga-mail
chapter: amiga-mail
section: senders-cxobjects
functions: [AttachCxObj, CxMsgData]
libraries: [commodities.library]
---

# Senders CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A filter CxObject by itself is not especially useful.  It needs some
other CxObjects attached to it.  A commodity interested in knowing if
a specific key was pressed uses a filter to detect and divert the
corresponding CxMessage down the filter's personal list.  The filter
does this without letting the commodity know what happened.  The
sender CxObject is used to notify a commodity that it received a
CxMessage.  CxSender() is a macro that creates a sender CxObject.


```c
    senderCxObj = CxObj *CxSender(struct MsgPort *senderport, LONG cxmID);
```
CxSender() supplies the sender with an Exec message port and an ID.
For every CxMessage a sender receives, it sends a new CxMessage to the
Exec message port passed in CxSender().  Normally, the commodity
creates this port.  It is not unusual for a commod ity's broker and
sender(s) to share an Exec message port.  The [HotKey.c](amiga-mail/xi-1-hotkey-c.md) example does
this to avoid creating unnecessary message ports.  A sender uses the
ID (cxmID) passed to CxSender() as the ID for all the CxMessages that
the it transmits.  A commodity uses the ID to monitor CxMessages from
several senders at a single message port.

A sender does several things when it receives a CxMessage.  First, it
duplicates the CxMessage's corresponding input event and creates a new
CxMessage.  Then, it points the new CxMessage's data field to the copy
of the input event and sets the new CxMessa ge's ID to the ID passed
to CxSender().  Finally, it sends the new CxMessage to the port passed
to CxSender(), asynchronously.

Because HotKey uses only one message port between its broker and
sender object, it has to extract the CxMessage's type so it can tell
if it is a CXM_IEVENT or a CXM_COMMAND.  If HotKey gets a CXM_IEVENT,
it compares the CxMessage's ID to the sender's ID, EVT_HOTKEY, to see
which sender sent the CxMessage.  Of course HotKey has only one
sender, so it only checks for only one ID.  If it had more senders,
HotKey would check for the ID of each of the other senders as well.

Although HotKey doesn't use it, a CXM_IEVENT CxMessage contains a
pointer to the copy of an input event.  A commodity can extract this
pointer (using CxMsgData() ) if it needs to examine the input event
copy.  This pointer is only valid before the CxMessa ge reply.  Note
that it does not make any sense to modify the input event copy.

Senders are attached almost exclusively to CxObjects that filter out
most input events (usually a filter CxObject).  Because a sender
sends a CxMessage for every single input event it gets, it should
only get a select few input events.  The AttachCxObj() function can
add a CxObject to the end of a filter's (or some other filtering
CxObject's) personal list. A commodity should not attach a CxObject
to a sender as a sender ignores any CxObjects in its personal list.

---

## See Also

- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
