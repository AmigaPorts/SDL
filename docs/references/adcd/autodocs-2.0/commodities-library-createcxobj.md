---
title: commodities.library/CreateCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-createcxobj
functions: [CxBroker, CxObjError]
libraries: [commodities.library]
---

# commodities.library/CreateCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateCxObj -- create a new commodity object. (V36)
```
SYNOPSIS

```c
    co = CreateCxObj(type,arg1,arg2);
                     D0   A0   A1

    CxObj *CreateCxObj(ULONG,LONG,LONG);
```
FUNCTION

```c
    This function creates a commodity object of type 'type'. It is not
    proper to call this function directly. Each object creation routine
    except [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md) is defined as a macro in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md)
    These are independently documented.

    All functions which operate on a commodity object are made with
    a reference to the thirty-two bit value returned by this function
    (or by [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)).
```
INPUTS
```c
    type - the type of object to create as defined in
           [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md)
```
   arg1 - first argument, meaning depends on 'type'

    arg2 - second argument, meaning depends on 'type'
RESULTS

```c
    co - a pointer to the new object or NULL if it could not be created.
         A NULL return indicates typically a lack of system memory. Minor
         problems in creating an object, such as providing a bad filter
         description to [cx_lib/CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md), typically don't cause failure,
         but are recorded in an internal error field in the new object
         which can be accessed via [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md).
```
SEE ALSO

```c
    [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md), [cx_lib/CxFilter()](autodocs-2.0/amiga-lib-cxfilter.md), [cx_lib/CxSender()](autodocs-2.0/amiga-lib-cxsender.md),
    [cx_lib/CxSignal()](autodocs-2.0/amiga-lib-cxsignal.md), [cx_lib/CxTranslate()](autodocs-2.0/amiga-lib-cxtranslate.md), [cx_lib/CxDebug()](autodocs-2.0/amiga-lib-cxdebug.md),
    [cx_lib/CxCustom()](autodocs-2.0/amiga-lib-cxcustom.md), [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)
```

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
