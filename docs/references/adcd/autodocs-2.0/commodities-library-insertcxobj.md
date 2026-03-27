---
title: commodities.library/InsertCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-insertcxobj
functions: [ClearCxObjError, CxObjError]
libraries: [commodities.library]
---

# commodities.library/InsertCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InsertCxObj -- insert a commodity object in a list after a given
                   object. (V36)
```
SYNOPSIS

```c
    InsertCxObj(headObj,co,pred);
                A0      A1 A2

    VOID InsertCxObj(CxObj *,CxObj *,CxObj *);
```
FUNCTION

    Adds 'co' to the list of objects pointed to by 'headObj' after
    object 'pred'.
INPUTS

    headObj - pointer to a list of objects
    co - the object to insert in the list
    pred - the object after which 'co' should be inserted. If this is NULL
           then 'co' is added to the head of the list.
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
