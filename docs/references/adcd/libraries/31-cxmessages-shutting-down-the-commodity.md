---
title: 31 / CxMessages / Shutting Down the Commodity
manual: libraries
chapter: libraries
section: 31-cxmessages-shutting-down-the-commodity
functions: [DeleteCxObj, DeleteCxObjAll]
libraries: [commodities.library]
---

# 31 / CxMessages / Shutting Down the Commodity

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Shutting down a commodity is easy.  After replying to all [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md)
waiting at the [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md)'s message port, a commodity can delete its
[CxObjects](libraries/31-commodities-exchange-library-cxobjects.md).  The [DeleteCxObj()](autodocs-2.0/commodities-library-deletecxobj.md) function removes a single CxObject from the
Commodities network.  [DeleteCxObjAll()](autodocs-2.0/commodities-library-deletecxobjall.md) removes multiple objects.


```c
    void DeleteCxObj( CxObj *co );
    void DeleteCxObjAll( CxObj *delete_co );
```
If a commodity has a lot of [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md), deleting each individually can be a
bit tedious.  [DeleteCxObjAll()](autodocs-2.0/commodities-library-deletecxobjall.md) will delete a CxObject and any other
CxObjects that are attached to it.  The [HotKey.c](libraries/lib-examples-hotkey-c.md) example given later in
this chapter uses this function to delete all its CxObjects.  A commodity
that uses DeleteCxObjAll() to delete all its CxObjects should make sure
that they are all connected to the main one.  (See the section
"[Connecting CxObjects](libraries/31-commodities-exchange-library-connecting-cxobjects.md)" below.)

After deleting its [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md), a commodity must take care of any [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md)
that might have arrived at the message port just before the commodity
deleted its objects.


```c
    while(msg = (CxMsg *)GetMsg(broker_mp))
        ReplyMsg((struct Message *)msg);
```

---

## See Also

- [DeleteCxObj — commodities.library](../autodocs/commodities.library.md#deletecxobj)
- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
