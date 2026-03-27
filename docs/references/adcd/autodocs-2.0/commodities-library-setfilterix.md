---
title: commodities.library/SetFilterIX
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-setfilterix
functions: [CxObjError, SetFilter]
libraries: [commodities.library]
---

# commodities.library/SetFilterIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetFilterIX -- change the matching condition of a commodity filter.
                   (V36)
```
SYNOPSIS

```c
    SetFilterIX(filter,ix);
                A0     A1

    VOID SetFilterIX(CxObj *,IX *);
```
FUNCTION

```c
    This function changes the matching condition of a commodity input
    filter to that described by the binary input expression pointed by
    'ix'.

    Input expressions are defined in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md).
    It is important to remember that the first field of the input
    expression structure must indicate which version of the
    input expression structure is being used.
```
INPUTS

    filter - the filter object to affect
    ix - the new matching conditions for the filter
RESULTS

    The internal error of 'filter' will have the COERR_BADFILTER
    bit set or cleared depending on the failure or success of this
    function.
SEE ALSO

```c
    [SetFilter()](autodocs-2.0/commodities-library-setfilter.md), [CxObjError()](autodocs-2.0/commodities-library-cxobjerror.md), [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md)
```

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
