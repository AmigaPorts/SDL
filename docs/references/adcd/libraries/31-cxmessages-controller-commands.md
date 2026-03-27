---
title: 31 / CxMessages / Controller Commands
manual: libraries
chapter: libraries
section: 31-cxmessages-controller-commands
functions: [CxBroker]
libraries: [commodities.library]
---

# 31 / CxMessages / Controller Commands

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The commands that a commodity can receive from the controller program (as
defined in <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>) are:


    CXCMD_DISABLE     /* please disable yourself       */
    CXCMD_ENABLE      /* please enable yourself        */
    CXCMD_KILL        /* go away for good              */
    CXCMD_APPEAR      /* open your window, if you can  */
    CXCMD_DISAPPEAR   /* hide your window              */
The CXCMD_DISABLE, CXCMD_ENABLE, and CXCMD_KILL commands correspond to the
similarly named controller program gadgets, Disable, Enable, and Kill;
CXCMD_APPEAR and CXCMD_DISAPPEAR correspond to the controller program
gadgets, Show and Hide.  These gadgets are ghosted in [Broker.c](libraries/lib-examples-broker-c.md) because it
has no window (It doesn't make much sense to give the user a chance to
click the Show and Hide gadgets).  In order to do this, Broker.c  has to
tell Commodities Exchange to ghost these gadgets.  When [CxBroker()](libraries/31-commodities-exchange-library-installing-a-broker-object.md) sets up
a [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md), it looks at the [NewBroker.nb_Flags](libraries/31-commodities-exchange-library-installing-a-broker-object.md) field to see if the
COF_SHOW_HIDE bit (from <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>) is set.  If it is, the
"Show" and "Hide" gadgets for this broker will be selectable.  Otherwise
they are ghosted and disabled.

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
