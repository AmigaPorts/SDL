---
title: 31 Commodities Exchange Library / CxMessages
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-cxmessages
functions: [CxBroker, CxMsgData, CxMsgID, CxMsgType]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / CxMessages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are actually two types of CxMessages.  The first, [CXM_IEVENT](autodocs-2.0/includes-libraries-commodities-h.md),
corresponds to an input event and travels through the Commodities Exchange
network.  The other type, [CXM_COMMAND](autodocs-2.0/includes-libraries-commodities-h.md), carries a command to a commodity.
A CXM_COMMAND normally comes from the controller program and is used to
pass user commands on to a commodity.  A commodity receives these commands
through an Exec message port that the commodity sets up before it calls
[CxBroker()](libraries/31-commodities-exchange-library-installing-a-broker-object.md).  The [NewBroker](libraries/31-commodities-exchange-library-installing-a-broker-object.md)'s [nb_Port](libraries/31-commodities-exchange-library-installing-a-broker-object.md) field points to this message port.  A
commodity can tell the difference between the two types of CxMessages by
calling the [CxMsgType()](autodocs-2.0/commodities-library-cxmsgtype.md) function.


```c
    ULONG  CxMsgType( CxMsg *cxm );
    UBYTE *CxMsgData( CxMsg *cxm );
    LONG   CxMsgID  ( CxMsg *cxm );
```
A CxMessage not only has a type, it can also have a data pointer as well
as an ID associated with it.  The data associated with a [CXM_IEVENT](autodocs-2.0/includes-libraries-commodities-h.md)
CxMessage is an [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md) structure.  By using the [CxMsgData()](autodocs-2.0/commodities-library-cxmsgdata.md) function,
a commodity can obtain a pointer to the corresponding InputEvent of a
CXM_IEVENT message.  Commodities Exchange gives an ID of zero to any
CXM_IEVENT CxMessage that it introduces to the Commodities network but
certain [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) can assign an ID to them.

For a [CXM_COMMAND](autodocs-2.0/includes-libraries-commodities-h.md) CxMessages, the data pointer is generally not used but
the ID specifies a command passed to the commodity from the user operating
the controller program.  The [CxMsgID()](autodocs-2.0/commodities-library-cxmsgid.md) macro extracts the ID from a
CxMessage.

 [A Simple Commodity Example](libraries/lib-examples-broker-c.md) 
 [Controller Commands](libraries/31-cxmessages-controller-commands.md) 
 [Shutting Down the Commodity](libraries/31-cxmessages-shutting-down-the-commodity.md) 

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [CxMsgType — commodities.library](../autodocs/commodities.library.md#cxmsgtype)
