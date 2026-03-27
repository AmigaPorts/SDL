---
title: 31 Commodities Exchange Library / Connecting CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-connecting-cxobjects
functions: [AttachCxObj, EnqueueCxObj, InsertCxObj, RemoveCxObj, SetCxObjPri]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Connecting CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) has to be inserted into the Commodities network before it can
process any [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md).  [AttachCxObj()](autodocs-2.0/commodities-library-attachcxobj.md) adds a CxObject to the personal
list of another CxObject.  The HotKey.c example uses it to attach its
[filter](libraries/31-commodities-exchange-filter-objects-and-input.md) to a [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md).


```c
    void AttachCxObj ( CxObj *headobj, CxObj *co);
    void InsertCxObj ( CxObj *headobj, CxObj *co, CxObj *co_pred );
    void EnqueueCxObj( CxObj *headobj, CxObj *co );
    void SetCxObjPri ( CxObj *co, long pri );
    void RemoveCxObj ( CxObj *co );
```
[AttachCxObj()](autodocs-2.0/commodities-library-attachcxobj.md) adds the [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) to the end of headobj's personal list.
The ordering of a CxObject list determines which object gets [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md)
first.  [InsertCxObj()](autodocs-2.0/commodities-library-insertcxobj.md) also inserts a CxObject, but it inserts it after
another CxObject already in the personal list (co_pred in the prototype
above).

[Brokers](libraries/31-commodities-exchange-library-installing-a-broker-object.md) aren't the only [CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) with a priority.  All CxObjects have a
priority associated with them.  To change the priority of any CxObject,
use the [SetCxObjPri()](autodocs-2.0/commodities-library-setcxobjpri.md) function.  A commodity can use the priority to keep
CxObjects in a personal list sorted by their priority.  The
commodities.library function [EnqueueCxObj()](autodocs-2.0/commodities-library-enqueuecxobj.md) inserts a CxObject into
another CxObject's personal list based on priority.

Like its name implies, the [RemoveCxObj()](autodocs-2.0/commodities-library-removecxobj.md) function removes a [CxObject](libraries/31-commodities-exchange-library-cxobjects.md) from
a personal list.  Note that it is not necessary to remove a CxObject from
a list in order to delete it.


```c
     [HotKey.c](libraries/lib-examples-hotkey-c.md) 
```

---

## See Also

- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
- [InsertCxObj — commodities.library](../autodocs/commodities.library.md#insertcxobj)
- [RemoveCxObj — commodities.library](../autodocs/commodities.library.md#removecxobj)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
