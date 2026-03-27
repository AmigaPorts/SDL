---
title: commodities.library/CxObjError
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-cxobjerror
functions: [ActivateCxObj, AttachCxObj, ClearCxObjError, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# commodities.library/CxObjError

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxObjError -- obtain a commodity object's accumulated error. (V36)
```
SYNOPSIS

```c
    error = CxObjError(co);
                       A0

    LONG CxObjError(CxObj *);
```
FUNCTION

```c
    When a function acting on an object fails, it records the failure
    in the object. This function returns the accumulated error value.
    The values are represented by flag bits defined in
    [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md). Several errors may be recorded by multiple
    bits in 'error'.

    The currently defined errors are:

    COERR_ISNULL
      The value of parameter 'co' was in fact NULL. This error
      means "the problem with the object you inquire about is
      that it failed to be created."

    COERR_NULLATTACH
      Using the commodities' list manipulation functions, an attempt was
      made to add a NULL object to the list belonging to 'co'. This allows
      a line of code as follows to exist in an error-tolerant program:

        AttachCxObj(filter,CxSender(myport,MY_ID));

    COERR_BADFILTER
      The most recent filter specification for a filter object
      was faulty. This happens if no sense can be made out of a
      description string, or if an input expression (IX) has an
      invalid format or version byte. When this bit is set in a
      filter's error field, the filter will match nothing, but this
      is not the proper way to "turn off" a filter, use [ActivateCxObj()](autodocs-2.0/commodities-library-activatecxobj.md).

    COERR_BADTYPE
      A type specific operation, such as [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md), was called
      for object 'co', but 'co' isn't of the proper type.
```
INPUTS

    co - the commodity object to get the accumulated error from
RESULTS

    error - the accumulated error
SEE ALSO

```c
    [SetFilter()](autodocs-2.0/commodities-library-setfilter.md), [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md), [AttachCxObj()](autodocs-2.0/commodities-library-attachcxobj.md), [ActivateCxObj()](autodocs-2.0/commodities-library-activatecxobj.md),
    [ClearCxObjError()](autodocs-2.0/commodities-library-clearcxobjerror.md)
```

---

## See Also

- [ActivateCxObj — commodities.library](../autodocs/commodities.library.md#activatecxobj)
- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
