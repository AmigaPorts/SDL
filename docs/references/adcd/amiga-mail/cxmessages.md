---
title: CxMessages
manual: amiga-mail
chapter: amiga-mail
section: cxmessages
functions: [ActivateCxObj, CxBroker, CxMsgData, CxMsgID, CxMsgType, DeleteCxObj]
libraries: [commodities.library]
---

# CxMessages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are actually two types of CxMessages.  The first, CXM_IEVENT,
corresponds to an input event and travels through the Commodities
Exchange network.  The other type, CXM_COMMAND, carries a command to
a commodity.  A CXM_COMMAND normally comes from the controller
program and is used to pass user commands on to a commodity.  A
commodity receives these commands through an Exec message port that
the commodity sets up before it calls CxBroker.  The NewBroker's
nb_Port field points to this message port.  A c ommodity can tell the
difference between the two types of CxMessages by calling the
CxMsgType() function.


```c
    ULONG CxMsgType(CxMsg *cxm);
    UBYTE *CxMsgData(CxMsg *cxm);
    LONG  CxMsgID(CxMsg *cxm);
```
A CxMessage not only has a type, it can also have a data pointer as
well as an ID associated with it.  The data associated with a
CXM_IEVENT is an InputEvent structure.  By using the CxMsgData()
function, a commodity can obtain a pointer to the correspond ing
InputEvent of a CXM_IEVENT.  Commodities Exchange does not give an ID
to the CXM_IEVENT CxMessages it introduces to the Commodities network,
but certain CxObjects can assign an ID to a CXM_IEVENT CxMessage.

CXM_COMMAND CxMessages generally do not use the data pointer.
Instead, they use an ID.  They use this ID to specify the command
passed to a commodity.  CxMsgID() extracts the ID from a CxMessage.


```c
    oldactivationvalue = LONG ActivateCxObj(CxObj *co,
                           long newactivationvalue);
```
After successfully completing the initial set up and activating the
broker using ActivateCxObj(), a commodity can begin its input
processing loop.  The example [Broker.c](amiga-mail/xi-1-broker-c.md) receives input from one source,
the controller program.  The controller program sends a CxMessage each
time the user clicks its enable, disable, or kill gadgets.  Using the
CxMsgID() function, the commodity finds out what the command is and
executes it.

Notice that [Broker.c](amiga-mail/xi-1-broker-c.md) uses Ctrl-C as a break key.  This is a change
from 1990 Atlanta DevCon Notes on Commodities Exchange which said to
use Ctrl-E.  The break key for any commodity should be Ctrl-C.

The commands that a commodity can receive from the controller program
(as defined in <libraries/commodities.h>) are:


    CXCMD_DISABLE     /* please disable yourself       */
    CXCMD_ENABLE      /* please enable yourself        */
    CXCMD_KILL        /* go away for good              */
    CXCMD_APPEAR      /* open your window, if you can  */
    CXCMD_DISAPPEAR   /* hide your window              */
The CXCMD_DISABLE, CXCMD_ENABLE, and CXCMD_KILL commands correspond
to the similarly named controller program gadgets, "Disable",
"Enable", and "Kill"; CXCMD_APPEAR and CXCMD_DISAPPEAR correspond to
the controller program gadgets, "Show" and "Hi de".  These gadgets
are ghosted in [Broker.c](amiga-mail/xi-1-broker-c.md) because it has no window (It doesn't make
much sense to give the user a chance to click the "Show" and "Hide"
gadgets).  In order to do this, Broker.c has to tell Commodities
Exchange to ghost these gadge ts.  When CxBroker() sets up a broker,
it looks at the NewBroker.nb_Flags field to see if the COF_SHOW_HIDE
bit (from <libraries/commodities.h>) is set.  If it is, the "Show"
and "Hide" gadgets for this broker will be selectable. Otherwise they
are g hosted and disabled.

Shutting down a commodity is easy.  After replying to all CxMessages
waiting at the broker's message port, a commodity can delete its
CxObjects.  DeleteCxObj() removes a single CxObject from the
Commodities network.


```c
    void DeleteCxObj(CxObj *co);
```

---

## See Also

- [ActivateCxObj — commodities.library](../autodocs/commodities.library.md#activatecxobj)
- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxMsgData — commodities.library](../autodocs/commodities.library.md#cxmsgdata)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [CxMsgType — commodities.library](../autodocs/commodities.library.md#cxmsgtype)
- [DeleteCxObj — commodities.library](../autodocs/commodities.library.md#deletecxobj)
