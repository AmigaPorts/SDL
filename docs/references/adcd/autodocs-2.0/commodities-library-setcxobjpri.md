---
title: commodities.library/SetCxObjPri
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-setcxobjpri
functions: [EnqueueCxObj]
libraries: [commodities.library]
---

# commodities.library/SetCxObjPri

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetCxObjPri -- set the priority of a commodity object. (V36)
```
SYNOPSIS

```c
    SetCxObjPri(co,pri)
                A0 D0

    VOID SetCxObjPri(CxObj *,LONG);
```
FUNCTION

```c
    This function sets the priority of a commodity object for the
    purposes of [EnqueueCxObj()](autodocs-2.0/commodities-library-enqueuecxobj.md).

    It is strongly recommended that the ToolTypes environment be
    utilized to provide end-user control over the priority of
    brokers, but application specific ordering of other objects
    within their lists is not dictated.
```
INPUTS

    co - the commodity object to affect
    pri - the object's new priority in the range -128 to +127. A value
          of 0 is normal.
SEE ALSO

```c
    [EnqueueCxObj()](autodocs-2.0/commodities-library-enqueuecxobj.md)
```

---

## See Also

- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
