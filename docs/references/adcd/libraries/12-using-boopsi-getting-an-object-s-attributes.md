---
title: 12 / / Using Boopsi / Getting an Object's Attributes
manual: libraries
chapter: libraries
section: 12-using-boopsi-getting-an-object-s-attributes
functions: [GetAttr]
libraries: [intuition.library]
---

# 12 / / Using Boopsi / Getting an Object's Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Intuition function [GetAttr()](autodocs-2.0/intuition-library-getattr.md) asks an object what the value of a
specific attribute is:


```c
    ULONG GetAttr(ULONG attrID, APTR myobject, ULONG *mydata);
```
where attrID is the attribute's ID number, myobject is the object to get
the attribute from, and mydata points to a data area that will hold the
attribute value.  This function returns a 0L if the object doesn't
recognize the attribute, otherwise it returns some non-zero value, the
meaning of which depends on the class.  In most cases, [GetAttr()](autodocs-2.0/intuition-library-getattr.md) returns a
1 when it is successful.

Not all object attributes are obtainable using the [GetAttr()](autodocs-2.0/intuition-library-getattr.md) function.
Some classes are set up so that applications cannot query the state of
certain attributes.  For example, using the [GA_Image](libraries/b-propgclass-attributes-ga-image-i.md) attribute, an
application can give a Boopsi prop gadget ([propgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)) an [Image](libraries/8-creating-images-image-structure.md) structure
which the gadget uses as the imagery for its knob. This attribute is not
"gettable" as there is no need for an application to have to ask the
gadget for the structure that the application passed it in the first
place.  Whether or not a specific attribute is "gettable" is class
dependent.  For more information about the attributes of specific classes,
see the Boopsi Class Reference in the [Appendix B](libraries/b-boopsi-class-reference.md) of this manual.

---

## See Also

- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
