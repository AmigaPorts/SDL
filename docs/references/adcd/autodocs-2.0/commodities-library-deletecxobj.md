---
title: commodities.library/DeleteCxObj
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-deletecxobj
functions: [DeleteCxObjAll]
libraries: [commodities.library]
---

# commodities.library/DeleteCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteCxObj -- delete a commmodity object. (V36)
```
SYNOPSIS

```c
    DeleteCxObj(co);
                A0

    VOID DeleteCxObj(CxObj *);
```
FUNCTION

```c
    Deletes a commodity object of any type. If the object
    is linked into a list, it is first removed. Note that
    the handle 'co' is invalid after this function is called.

    Also note that deleting an object which has other objects attached
    to it may be undesirable. Use the function [DeleteCxObjAll()](autodocs-2.0/commodities-library-deletecxobjall.md)
    to delete an entire sub-tree of objects.
```
INPUTS

    co - the commodity object to delete
SEE ALSO

```c
    [DeleteCxObjAll()](autodocs-2.0/commodities-library-deletecxobjall.md)
```

---

## See Also

- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
