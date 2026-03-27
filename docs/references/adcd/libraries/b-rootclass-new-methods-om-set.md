---
title: B / rootclass / New Methods: OM_SET
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-set
functions: [NextTagItem]
libraries: [utility.library]
---

# B / rootclass / New Methods: OM_SET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells an object to set one or more of its attributes.
Applications should not call this method directly.  Instead, use the
intuition.library functions [SetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) and [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) to call this
method.  The return value for this method is not explicitly defined.

The return value for this method is not explicitly defined.  However, in
general, when implementing the OM_SET method, if setting an object
attribute causes some sort of visual state change, the OM_SET method
should return a value greater than zero.  If changing an attribute does
not affect the visual state, OM_SET should return zero.

This method uses a custom message (defined in <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opSet {
        ULONG             MethodID;      /* OM_SET */
        struct TagItem    *ops_AttrList; /* tag list of attributes to set*/
        struct GadgetInfo *ops_GInfo;
    };
```
The ops_AttrList field contains a pointer to a tag list of attribute/value
pairs.  These pairs contain the IDs and the new values of the attributes
to set.  The dispatcher has to look through this list (see docs for the
utility.library [NextTagItem()](libraries/37-tags-tag-functions-and-structures.md) function) for attributes its class
recognizes and set the attribute's value accordingly.  The dispatcher
should let its superclass handle any attributes it does not recognize.

If the object is a gadget, the ops_GInfo field contains a pointer to a
[GadgetInfo](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) structure.  Otherwise, the value in ops_GInfo is undefined.
Intuition use the GadgetInfo structure to pass display information to
gadgets.  See the [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) methods for more details.

---

## See Also

- [NextTagItem — utility.library](../autodocs/utility.library.md#nexttagitem)
