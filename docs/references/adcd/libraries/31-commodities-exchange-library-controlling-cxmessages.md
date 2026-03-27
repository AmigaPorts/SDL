---
title: 31 Commodities Exchange Library / Controlling CxMessages
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-controlling-cxmessages
functions: [DisposeCxMsg, DivertCxMsg, RouteCxMsg]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Controlling CxMessages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [Custom CxObject](libraries/31-commodities-exchange-library-custom-cxobjects.md) has the power to directly manipulate the [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md) that
travel around the Commodities network.  One way is to directly change
values in the corresponding input event.  Another way is to redirect (or
dispose of) the CxMessages.


```c
    void DivertCxMsg ( CxMsg *cxm, CxObj *headobj, CxObj *retobj );
    void RouteCxMsg  ( CxMsg *cxm, CxObj *co );
    void DisposeCxMsg( CxMsg *cxm );
```
[DivertCxMsg()](autodocs-2.0/commodities-library-divertcxmsg.md) and [RouteCxMsg()](autodocs-2.0/commodities-library-routecxmsg.md) dictate where the [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) will go next.
Conceptually, DivertCxMsg() is analogous to a subroutine in a program; the
CxMessage will travel down the personal list of a [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) (headobj in the
prototype) until it gets to the end of that list.  It then returns and
visits the CxObject that follows the return CxObject (the return CxObject
in the prototype above is retobj).  RouteCxMsg() is analogous to a goto in
a program; it has no CxObject to return to.

[DisposeCxMsg()](autodocs-2.0/commodities-library-disposecxmsg.md) removes a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) from the network and releases its
resources.  The [translate CxObject](libraries/31-commodities-exchange-library-translate-cxobjects.md) uses this function to remove a
CxMessage.

The example Divert.c shows how to use [DivertCxMsg()](autodocs-2.0/commodities-library-divertcxmsg.md) as well as a
[signal CxObject](libraries/31-commodities-exchange-library-signal-cxobjects.md).


```c
     [divert.c](libraries/lib-examples-divert-c.md) 
```

---

## See Also

- [DisposeCxMsg — commodities.library](../autodocs/commodities.library.md#disposecxmsg)
- [DivertCxMsg — commodities.library](../autodocs/commodities.library.md#divertcxmsg)
- [RouteCxMsg — commodities.library](../autodocs/commodities.library.md#routecxmsg)
