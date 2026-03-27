---
title: 31 Commodities Exchange Library / CxObject Errors
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-cxobject-errors
functions: [ClearCxObjError, CxObjError, SetFilter]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / CxObject Errors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A Commodities Exchange function that acts on a [CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) records errors in
the CxObject's accumulated error field.  The function [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md) returns
a CxObject's error field.


```c
    co_errorfield = LONG CxObjError( CxObj *co );
```
Each bit in the error field corresponds to a specific type of error.  The
following is a list of the currently defined [CxObject errors](autodocs-2.0/includes-libraries-commodities-h.md) and their
corresponding bit mask constants.




```c
    Error Constant    Meaning
    --------------    -------
    COERR_ISNULL      [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md) was passed a NULL.
    COERR_NULLATTACH  Someone tried to attach a NULL [CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) to this
                      CxObject.
    COERR_BADFILTER   This [filter CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) currently has an invalid
                      filter description.
    COERR_BADTYPE     Someone tried to perform a type specific function
                      on the wrong type of [CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) (for example calling
                      [SetFilter()](libraries/31-commodities-exchange-library-the-ix-structure.md) on a [sender CxObject](libraries/31-commodities-exchange-library-sender-cxobjects.md)).
```
The remaining bits are reserved for future use.  [HotKey.c](libraries/lib-examples-hotkey-c.md)
checks the error field of its [filter CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md) to make sure the filter is
valid.  HotKey.c does not need to check the other objects with
[CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md) because it already makes sure that these other objects are
not NULL, which is the only other kind of error the other objects can
cause in this situation.

Commodities Exchange has a function that clears a [CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md)'s accumulated
error field, [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md).


```c
    void ClearCxObjError( CxObj *co );
```
A commodity should be careful about using this, especially on a [filter](libraries/31-commodities-exchange-library-cxmessages.md).
If a commodity clears a filter's error field and the COERR_BADFILTER bit
is set, Commodities Exchange will think that the filter is OK and start
sending messages through it.

---

## See Also

- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
