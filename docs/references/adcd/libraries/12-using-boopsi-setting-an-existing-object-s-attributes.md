---
title: 12 / / Using Boopsi / Setting an Existing Object's Attributes
manual: libraries
chapter: libraries
section: 12-using-boopsi-setting-an-existing-object-s-attributes
functions: [NewObject]
libraries: [intuition.library]
---

# 12 / / Using Boopsi / Setting an Existing Object's Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An object's attributes are not necessarily static.  An application can ask
an object to set certain object attributes using the [SetAttrs()](autodocs-2.0/intuition-library-setattrsa.md) function:


```c
    ULONG SetAttrs(APTR myobject, Tag1, Value1, ...);
```
Because Boopsi gadgets require some extra information about their display,
they use a special version of this function, [SetGadgetAttrs()](autodocs-2.0/intuition-library-setgadgetattrsa.md):


```c
    ULONG SetGadgetAttrs(struct Gadget *myobject, struct Window *w,
                         struct Requester *r, Tag1, Value1, ...);
```
Here myobject is a pointer to the Boopsi object, w points to the gadget's
window, r points to the gadget's requester, and the tag/value pairs are
the attributes and their new values.  The return value of [SetAttrs()](autodocs-2.0/intuition-library-setattrsa.md) and
[SetGadgetAttrs()](autodocs-2.0/intuition-library-setgadgetattrsa.md) is class specific.  In general, if the attribute change
causes a visual change to some object, the SetAttrs()/SetGadgetAttrs()
function should return a non-zero value, otherwise, these functions should
return zero (see the Boopsi Class Reference in "[Appendix B](libraries/b-boopsi-class-reference.md)" of this manual
for information on the return values for specific classes).  The following
is an example of how to set the current integer value and gadget ID of the
gadget created in the [NewObject()](libraries/12-using-boopsi-creating-an-object.md) call above:


```c
    SetGadgetAttrs(mystringgadget, mywindow, NULL, STRINGA_LongVal,   75L,
                                                   GA_ID,             2L,
                                                   TAG_END));
```
This changes two of mystringgadget's attributes.  It changes the gadget's
current integer value to 75 and it changes the gadget's ID number to 2.

Note that it is not OK to call [SetGadgetAttrs()](autodocs-2.0/intuition-library-setgadgetattrsa.md) on a Boopsi object that
isn't a gadget, nor is it OK to call [SetAttrs()](autodocs-2.0/intuition-library-setattrsa.md) on a Boopsi gadget.

Not all object attributes can be set with [SetGadgetAttrs()](autodocs-2.0/intuition-library-setgadgetattrsa.md)/[SetAttrs()](autodocs-2.0/intuition-library-setattrsa.md).
Some classes are set up so that applications cannot change certain
attributes.  For example, the imagery for the knob of a proportional
gadget cannot be altered after the object has been created.  Whether or
not a specific attribute is "settable" is class dependent.  For more
information about the attributes of specific classes, see the Boopsi Class
Reference in the [Appendix B](libraries/b-boopsi-class-reference.md) of this manual.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
