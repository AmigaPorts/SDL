---
title: B / rootclass / New Methods: OM_GET
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-get
functions: [GetAttr]
libraries: [intuition.library]
---

# B / rootclass / New Methods: OM_GET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Tells an object to report an attribute's value.  Applications should not
call this method directly.  Instead, use the intuition.library function
[GetAttr()](libraries/12-using-boopsi-getting-an-object-s-attributes.md).  The return value for this method is not explicitly defined.

This method uses a custom message (defined in <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opGet {
        ULONG MethodID;     /* OM_GET */
        ULONG opg_AttrID;   /* ID of attribute to get */
        ULONG *opg_Storage; /* place to put attribute value */
    };
```
If the object's dispatcher recognizes opg_AttrID as one of the attributes
defined by this class, the dispatcher should copy the value of that
attribute to where opg_Storage points:


```c
    struct opGet *myopget;
    ...
    *(myopget->opg_Storage) = my_attribute_value;
    ...
```
If the dispatcher does not recognize opg_AttrID, it should pass the
message on to the superclass.

---

## See Also

- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
