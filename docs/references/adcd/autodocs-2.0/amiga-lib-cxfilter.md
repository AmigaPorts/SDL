---
title: amiga.lib/CxFilter
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-cxfilter
functions: [CreateCxObj, CxObjError, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# amiga.lib/CxFilter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxFilter -- create a commodity filter object. (V36)
```
SYNOPSIS

```c
    filterObj = CxFilter(description);

    CxObj *CxFilter(STRPTR)
```
FUNCTION

```c
    Creates an input event filter object that matches the
    'description' string. If 'description' is NULL, the filter will not
    match any messages.

    A filter may be modified by the functions [SetFilter()](autodocs-2.0/commodities-library-setfilter.md), using
    a description string, and [SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md), which takes a
    binary Input Expression as a parameter.

    This function is a C-language macro for [CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), defined
    in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md).
```
INPUTS

```c
    description - the description string in the same format as strings
                  expected by [commodities.library/SetFilter()](autodocs-2.0/commodities-library-setfilter.md)
```
RESULTS

```c
    filterObj - a pointer to the filter object, or NULL if there
                was not enough memory. If there is a problem in the
                description string, the internal error code of the filter
                object will be set to so indicate. This error code may be
                interrogated using the function [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md).
```
SEE ALSO

```c
    [commodities.library/CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), [commodities.library/SetFilter()](autodocs-2.0/commodities-library-setfilter.md),
    [commodities.library/SetFilterIX()](autodocs-2.0/commodities-library-setfilterix.md), [commodities.library/CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md)
```

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
