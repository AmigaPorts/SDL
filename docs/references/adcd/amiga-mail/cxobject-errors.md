---
title: CxObject Errors
manual: amiga-mail
chapter: amiga-mail
section: cxobject-errors
functions: [CxObjError, SetFilter]
libraries: [commodities.library]
---

# CxObject Errors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A Commodities Exchange function that acts on a CxObject records errors
in the CxObject's accumulated error field.  The function CxObjError()
returns a CxObject's error field.


```c
    co_errorfield = LONG CxObjError( CxObj *co );
```
Each bit in the error field corresponds to a specific type of error.
The following is a list of the currently defined CxObject errors and
their corresponding bit mask constants.


```c
    COERR_ISNULL             CxObjError() was passed a NULL.
    COERR_NULLATTACH         Someone tried to attach a NULL CxObj to this
    CxObj.  COERR_BADFILTER  This CxObj is a filter and currently has an
                               invalid filter description.
    COERR_BADTYPE            Someone tried to perform a type specific
                               function on the wrong kind of CxObject
                               (for example calling SetFilter() on a
                               sender CxObject).
```
The remaining bits are reserved by Commodore for future use.  HotKey
checks the error field of its filter CxObject to make sure the filter
is valid.  HotKey does not need to check the other objects with
CxObjError() because it already makes sure that thes e other objects
are not NULL, which is the only other kind of error the other objects
can cause in this situation.

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
