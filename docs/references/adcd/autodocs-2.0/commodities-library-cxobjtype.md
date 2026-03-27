---
title: commodities.library/CxObjType
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-cxobjtype
functions: [CreateCxObj]
libraries: [commodities.library]
---

# commodities.library/CxObjType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxObjType -- obtain the type of a commodity object. (V36)
```
SYNOPSIS

```c
    type = CxObjType(co);
                     A0

    ULONG CxObjType(CxObj *);
```
FUNCTION

    This function should not really be necessary. It returns
    the type of a commodity object, which you should already
    know, since you created it in the first place.
INPUTS

    co - the commodity object to inquire about
RESULTS

```c
    type - the type of the commodity object, possible values are
           defined in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md)
```
SEE ALSO

```c
    [CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md)
```

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
