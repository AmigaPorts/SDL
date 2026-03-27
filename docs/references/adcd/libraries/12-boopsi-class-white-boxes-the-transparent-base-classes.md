---
title: 12 / Boopsi Class / White Boxes - The Transparent Base Classes
manual: libraries
chapter: libraries
section: 12-boopsi-class-white-boxes-the-transparent-base-classes
functions: [NewObject]
libraries: [intuition.library]
---

# 12 / Boopsi Class / White Boxes - The Transparent Base Classes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Boopsi gadgets and images were designed to be backwards compatible with
the old Intuition [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)s and [Image](libraries/8-creating-images-image-structure.md)s, so as part of their instance data,
both types of objects have the old Intuition structures built into them.
When [NewObject()](libraries/12-using-boopsi-creating-an-object.md) creates a new gadget or image object, the pointer it
returns points to the object's embedded Gadget or Image corresponding
structure. Because Intuition can tell the difference between Boopsi images
and gadgets and the original images and gadgets, applications can use
Boopsi images and gadgets interchangeably with the older Intuition
entities.

Although normally considered a "programming sin", in some cases it is
legal for class dispatchers to directly manipulate some internal fields of
certain Boopsi objects.  For compatibility reasons, a Boopsi image or
gadget object contains an actual [Image](libraries/8-creating-images-image-structure.md) or [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  These objects
are instances of the Transparent Base Classes, [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md) and [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md).

To change an attribute of a Boopsi object, you normally invoke the set
method, [OM_SET.](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)  The Intuition functions [SetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) and [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md)
invoke this method.  A Boopsi class is informed of any attribute change at
that time, allowing it to react to this change.  The reaction can include
validating the changed attribute, changing other attributes to match, or
informing other objects of the change.  That is the inherent advantage of
using function calls to change attributes.

When using conventional images and gadgets, you generally modify the
structure's fields directly.  This operation is very fast.  For
conventional images and gadgets, there is no class that needs to know
about the changes, so there is no problem.  However, this is untrue of
Boopsi images and gadgets.  Although directly modifying the Boopsi
object's internal structure would provide a performance increase over
using the Boopsi [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) mechanism, altering a Boopsi object's internal
structure directly will not give the class the opportunity to react to any
structure changes.  This violates the Boopsi concept, and therefore cannot
be done in general.

In order to provide a balance between the flexibility of function-access
and the performance of direct-access, the transparent base classes
[imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md) and [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) do not depend on being informed of changes to
certain fields in the internal [Image](libraries/8-creating-images-image-structure.md) and [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structures.  This means
that it is OK for the dispatchers of direct subclasses of imageclass and
gadgetclass to modify specific fields of Boopsi images or gadgets.
Applications and indirect subclass dispatchers of imageclass or
gadgetclass may not modify those fields, since their parent classes may
depend on hearing about changes to these fields, which the [SetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) call
(or a similar function) provides.

For dispatchers of direct subclasses of [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md), the following are the
only fields of the [Image](libraries/8-creating-images-image-structure.md) structure that are alterable:


```c
    [LeftEdge](libraries/8-creating-images-image-structure.md)      [Width](libraries/8-creating-images-image-structure.md)     [ImageData](libraries/8-creating-images-image-structure.md)
    [TopEdge](libraries/8-creating-images-image-structure.md)       [Height](libraries/8-creating-images-image-structure.md)    [PlanePick](libraries/8-creating-images-image-structure.md)
    [PlaneOnOff](libraries/8-creating-images-image-structure.md)
```
For dispatchers of direct subclasses of [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md), the following are the
only fields of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure that are alterable:


```c
    [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md)    [Flags](libraries/5-intuition-gadgets-gadget-structure.md)           [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md)
    [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md)     [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md)      [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md)
    [Width](libraries/5-intuition-gadgets-gadget-structure.md)       [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md)    [Activation](libraries/5-intuition-gadgets-gadget-structure.md)
    [Height](libraries/5-intuition-gadgets-gadget-structure.md)      [SelectRender](libraries/5-intuition-gadgets-gadget-structure.md)
```
Under no circumstances may an application or an indirect subclass modify
one of these fields, even if the subclass knows the superclasses do not
depend on notification for this field.  This is the only way to preserve
the possibility for future enhancements to that superclass.  Note that
these fields are not alterable while the gadget or image object is in use
(for example, when it is attached to a window).

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
