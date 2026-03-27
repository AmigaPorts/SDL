---
title: B / rootclass / New Methods: OM_ADDTAIL
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-addtail
functions: [NextObject]
libraries: [intuition.library]
---

# B / rootclass / New Methods: OM_ADDTAIL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells an object to add itself to the end of a specified Exec
list.  Boopsi objects contain a [MinNode](libraries/23-list-structure-node-structure-definition.md) structure used for this purpose.
The return value for this method is not explicitly defined.

The method uses a custom message (defined in <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opAddTail {
        ULONG       MethodID;   /* OM_ADDTAIL */
        struct List *opat_List; /* The exec list to add the object to */
    };
```
The opat_List can be any Exec list.  Use the Intuition function
[NextObject()](autodocs-2.0/intuition-library-nextobject.md) to step through this list.

---

## See Also

- [NextObject — intuition.library](../autodocs/intuition.library.md#nextobject)
