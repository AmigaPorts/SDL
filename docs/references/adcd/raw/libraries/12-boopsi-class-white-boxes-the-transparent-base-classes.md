# 12 / Boopsi Class / White Boxes - The Transparent Base Classes


Boopsi gadgets and images were designed to be backwards compatible with
the old Intuition [Gadget](../Libraries_Manual_guide/node0149.html)s and [Image](../Libraries_Manual_guide/node01BA.html)s, so as part of their instance data,
both types of objects have the old Intuition structures built into them.
When [NewObject()](../Libraries_Manual_guide/node0203.html#line25) creates a new gadget or image object, the pointer it
returns points to the object's embedded Gadget or Image corresponding
structure. Because Intuition can tell the difference between Boopsi images
and gadgets and the original images and gadgets, applications can use
Boopsi images and gadgets interchangeably with the older Intuition
entities.

Although normally considered a "programming sin", in some cases it is
legal for class dispatchers to directly manipulate some internal fields of
certain Boopsi objects.  For compatibility reasons, a Boopsi image or
gadget object contains an actual [Image](../Libraries_Manual_guide/node01BA.html) or [Gadget](../Libraries_Manual_guide/node0149.html) structure.  These objects
are instances of the Transparent Base Classes, [imageclass](../Libraries_Manual_guide/node0209.html) and [gadgetclass](../Libraries_Manual_guide/node020A.html).

To change an attribute of a Boopsi object, you normally invoke the set
method, [OM_SET.](../Libraries_Manual_guide/node0211.html#line28)  The Intuition functions [SetAttrs()](../Libraries_Manual_guide/node0205.html) and [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5)
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
using the Boopsi [OM_SET](../Libraries_Manual_guide/node0211.html#line28) mechanism, altering a Boopsi object's internal
structure directly will not give the class the opportunity to react to any
structure changes.  This violates the Boopsi concept, and therefore cannot
be done in general.

In order to provide a balance between the flexibility of function-access
and the performance of direct-access, the transparent base classes
[imageclass](../Libraries_Manual_guide/node0209.html) and [gadgetclass](../Libraries_Manual_guide/node020A.html) do not depend on being informed of changes to
certain fields in the internal [Image](../Libraries_Manual_guide/node01BA.html) and [Gadget](../Libraries_Manual_guide/node0149.html) structures.  This means
that it is OK for the dispatchers of direct subclasses of imageclass and
gadgetclass to modify specific fields of Boopsi images or gadgets.
Applications and indirect subclass dispatchers of imageclass or
gadgetclass may not modify those fields, since their parent classes may
depend on hearing about changes to these fields, which the [SetAttrs()](../Libraries_Manual_guide/node0205.html) call
(or a similar function) provides.

For dispatchers of direct subclasses of [imageclass](../Libraries_Manual_guide/node0209.html), the following are the
only fields of the [Image](../Libraries_Manual_guide/node01BA.html) structure that are alterable:


```c
    [LeftEdge](../Libraries_Manual_guide/node01BA.html#line17)      [Width](../Libraries_Manual_guide/node01BA.html#line32)     [ImageData](../Libraries_Manual_guide/node01BA.html#line47)
    [TopEdge](../Libraries_Manual_guide/node01BA.html#line17)       [Height](../Libraries_Manual_guide/node01BA.html#line32)    [PlanePick](../Libraries_Manual_guide/node01BA.html#line63)
    [PlaneOnOff](../Libraries_Manual_guide/node01BA.html#line69)
```
For dispatchers of direct subclasses of [gadgetclass](../Libraries_Manual_guide/node020A.html), the following are the
only fields of the [Gadget](../Libraries_Manual_guide/node0149.html) structure that are alterable:


```c
    [LeftEdge](../Libraries_Manual_guide/node0149.html#line33)    [Flags](../Libraries_Manual_guide/node0149.html#line48)           [GadgetText](../Libraries_Manual_guide/node0149.html#line111)
    [TopEdge](../Libraries_Manual_guide/node0149.html#line33)     [GadgetType](../Libraries_Manual_guide/node0149.html#line58)      [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125)
    [Width](../Libraries_Manual_guide/node0149.html#line33)       [GadgetRender](../Libraries_Manual_guide/node0149.html#line91)    [Activation](../Libraries_Manual_guide/node0149.html#line53)
    [Height](../Libraries_Manual_guide/node0149.html#line33)      [SelectRender](../Libraries_Manual_guide/node0149.html#line102)
```
Under no circumstances may an application or an indirect subclass modify
one of these fields, even if the subclass knows the superclasses do not
depend on notification for this field.  This is the only way to preserve
the possibility for future enhancements to that superclass.  Note that
these fields are not alterable while the gadget or image object is in use
(for example, when it is attached to a window).

