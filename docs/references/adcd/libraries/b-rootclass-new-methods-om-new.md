---
title: B / rootclass / New Methods: OM_NEW
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-new
functions: [NewObject]
libraries: [intuition.library]
---

# B / rootclass / New Methods: OM_NEW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells a class to create a new instance of itself.  If OM_NEW
is successful, it returns a pointer to the new object, otherwise it
returns NULL.

For programmers who are only creating Boopsi objects rather than creating
custom classes, use the intuition.library function [NewObject()](libraries/12-using-boopsi-creating-an-object.md):


```c
    APTR NewObject(struct IClass  *privateclass,
                   UBYTE          *publicclassname,
                   ULONG          firsttag,
                   ...)
```
The OM_NEW method receives the following arguments (defined in
<intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opSet /* The OM_NEW method uses the same structure as OM_SET */
    {
        ULONG             MethodID;      /* OM_NEW */
        struct TagItem    *ops_AttrList; /* tag attributes to initialize */
        struct GadgetInfo *ops_GInfo;    /* Always NULL for OM_NEW */
    };
```
The ops_AttrList field contains a pointer to a tag list of attribute/value
pairs.  Each pair contains an attribute ID and the initial value of the
corresponding attribute.

The ops_GInfo field is always NULL for the OM_NEW method.

Unlike other methods, when the dispatcher gets an OM_NEW message, the
object pointer (newobject from the [dispatchRKMModel()](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) prototype above)
does not point to an object, since the idea is to create a new object.
The pointer normally used to pass a Boopsi object is instead used to pass
the address of the object's "true class" (the class of which the object
is an instance).

The first thing the dispatcher does when it processes an OM_NEW message is
pass the OM_NEW message on to its superclass's dispatcher.  It does this
using the amiga.lib function [DoSuperMethodA()](libraries/12-writing-the-dispatcher-om-new.md):


```c
    ULONG DoSuperMethodA(Class *cl, Object *trueclass, Msg msg);
```
Each superclass's dispatcher does this until the message gets to the
rootclass dispatcher.

Each class keeps a record of how much memory its local instance data
requires.  The [rootclass](libraries/b-boopsi-class-reference-rootclass.md) dispatcher's OM_NEW method looks at the object's
true class (newobject from the prototype) to find out how much memory to
allocate for the object's instance data.  The rootclass dispatcher
allocates enough memory for the true class's local instance data, plus
enough memory for the local instance data of each of the true class's
superclasses.  If all goes well, the rootclass dispatcher increments the
true class's internal count of instances of true class, and returns a
pointer to the newly created object.  it passes control back to the
subclass dispatcher that called it.  If there was a problem, the rootclass
dispatcher passes back a NULL.

When the [rootclass](libraries/b-boopsi-class-reference-rootclass.md) dispatcher returns, the subclass dispatcher regains
control from [DoSuperMethodA()](libraries/12-writing-the-dispatcher-om-new.md).  DoSuperMethodA() will return either a
pointer to the new object or NULL if there was an error.  Although the
rootclass dispatcher allocated all the memory the object needs, it did not
set up any of that memory.  Now its the the subclass dispatcher's turn to
do some work.  It has to initialize the instance data that is local to its
class.  A dispatcher finds its local instance data by using the
INST_DATA() macro (defined in <intuition/[classes.h](autodocs-2.0/includes-intuition-classes-h.md)>).

After initializing its local instance data, the subclass dispatcher passes
control down to its subclass dispatcher, which in turn, initializes its
local instance data.  Control passes down from class to subclass until the
true class dispatcher regains control.

Now the true class dispatcher has to initialize its local instance data.
It has to scan through the tag list of attribute/value pairs passed in the
OM_NEW message (opSet.ops_AttrList).  If the dispatcher finds any
attributes that the true class recognizes, it has to initialize them to
the value passed in the attribute/value pair.

At this point, the new object can allocate other resources it needs that
it did not allocate as part of its instance data.  For example, the new
Boopsi object might need a frame image around itself, so it can create a
new one using a Boopsi frame image.  If the object allocates any resources
in this step, it must deallocate these resources later when it is disposed
in the [OM_DISPOSE](libraries/b-rootclass-new-methods-om-dispose.md) method.

Finally, the dispatcher can return.  When the dispatcher returns from an
OM_NEW method, it returns a pointer to the new object.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
