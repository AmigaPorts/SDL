---
title: commodities.library/AttachCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-attachcxobj
functions: [ClearCxObjError, CxObjError]
libraries: [commodities.library]
---

# commodities.library/AttachCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AttachCxObj -- attach a commodity object to the end of an existing
                   list of objects. (V36)
```
SYNOPSIS

```c
    AttachCxObj(headObj,co);
                A0      A1

    VOID AttachCxObj(CxObj *,CxObj *);
```
FUNCTION

    Adds 'co' to the list of objects pointed to by 'headObj'. The
    new object is added at the end of the list.
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
    [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md), [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md)
```

---

## See Also

- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
