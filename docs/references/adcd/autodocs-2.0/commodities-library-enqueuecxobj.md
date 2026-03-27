---
title: commodities.library/EnqueueCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-enqueuecxobj
functions: [ClearCxObjError, CxObjError, SetCxObjPri]
libraries: [commodities.library]
---

# commodities.library/EnqueueCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    EnqueueCxObj -- insert a commodity object within a list of objects
                    based on object priority. (V36)
```
SYNOPSIS

```c
    EnqueueCxObj(headObj,co);
                 A0      A1

    VOID EnqueueCxObj(CxObj *,CxObj *);
```
FUNCTION

```c
    This function puts object 'co' into the list of object 'headObj'.
    The insertion point is determined by the object's priority. The
    objects are kept in the list from the highest priority to the
    lowest. New nodes are inserted in front of the first node with a
    lower priority. Hence a FIFO queue for nodes of equal priority.

    The priority of the commodity object can be set using [SetCxObjPri()](autodocs-2.0/commodities-library-setcxobjpri.md).
```
INPUTS

    headObj - pointer to a list of objects
    co - the object to add to the list
RESULTS

```c
    If 'co' is NULL, this function will record that fact in the
    internal accumulated error of 'headObj'. This error record
    can be retrieved using [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md) and cleared using
    [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md).
```
SEE ALSO

```c
    [SetCxObjPri()](autodocs-2.0/commodities-library-setcxobjpri.md), [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md), [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md)
```

---

## See Also

- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
