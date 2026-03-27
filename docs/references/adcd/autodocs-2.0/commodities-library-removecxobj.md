---
title: commodities.library/RemoveCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-removecxobj
functions: [AttachCxObj, EnqueueCxObj, InsertCxObj]
libraries: [commodities.library]
---

# commodities.library/RemoveCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemoveCxObj -- remove a commodity object from a list. (V36)
```
SYNOPSIS

```c
    RemoveCxObj(co);
                A0

    VOID RemoveCxObj(CxObj *);
```
FUNCTION

```c
    This function remove 'co' from any list it may be a part of.
    Will not crash if 'co' is NULL, or if it has not been inserted
    in a list (and is not corrupted).

    It is not recommended to remove a broker from the master list.
```
INPUTS
   co - the object to remove, may be NULL

SEE ALSO

```c
    [AttachCxObj()](autodocs-2.0/commodities-library-attachcxobj.md), [EnqueueCxObj()](autodocs-2.0/commodities-library-enqueuecxobj.md), [InsertCxObj()](autodocs-2.0/commodities-library-insertcxobj.md)
```

---

## See Also

- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
- [InsertCxObj — commodities.library](../autodocs/commodities.library.md#insertcxobj)
