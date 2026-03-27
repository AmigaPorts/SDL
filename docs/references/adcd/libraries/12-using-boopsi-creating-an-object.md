---
title: 12 / / Using Boopsi / Creating an Object
manual: libraries
chapter: libraries
section: 12-using-boopsi-creating-an-object
functions: [NewObject]
libraries: [intuition.library]
---

# 12 / / Using Boopsi / Creating an Object

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Intuition function [NewObjectA()](autodocs-2.0/intuition-library-newobject.md) creates a Boopsi object:


```c
    mynewobject = APTR NewObjectA(Class *privclass, UBYTE *pubclass,
                                  struct TagItem *myattrs)
```
The pointer that [NewObjectA()](autodocs-2.0/intuition-library-newobject.md) returns is a pointer to a Boopsi object.  In
general, Boopsi objects are "black boxes".  This means the inner workings
of Boopsi objects are not visible to the application programmer, so the
programmer does not know what goes on inside it.  This really means the
inner workings of these objects are none of your business.  Unless
otherwise documented, only use an object pointer as a handle to the object.

To create an object, [NewObjectA()](autodocs-2.0/intuition-library-newobject.md) needs to know what class the new object
is an instance of.  To create a public class object, pass a NULL pointer
in privclass and an ASCII string in pubclass naming the object's public
class.  The privclass pointer is used to create a private class object,
which is covered in the "[Creating a Boopsi Class](libraries/12-writing-the-dispatcher-making-the-new-class.md)" section later in this
chapter.

The myattrs tag list is a list of tag/value pairs, each of which contains
an initial value for some object attribute.  Most objects have a set of
attributes associated with them, so each attribute has a tag name.  For
Boopsi gadgets and images, the attributes include some of the values from
the old [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) and [Image](libraries/8-creating-images-image-structure.md) structures (position, size, etc.).

Most applications use the stack-based version of [NewObjectA()](autodocs-2.0/intuition-library-newobject.md),
[NewObject()](autodocs-2.0/intuition-library-newobject.md), to create objects.  This allows an application to build the
tag list of object attributes on the stack rather than having to allocate
and initialize a tag list.  A code sample from a program that creates a
Boopsi string gadget might look like this:


```c
    mystringgadget = (struct Gadget *)NewObject(NULL, "strgclass",
                                                GA_ID,           1L,
                                                GA_Left,         0L,
                                                GA_Top,          0L,
                                                STRINGA_LongVal, 100L,
                                                TAG_END);
```
If [NewObject()](autodocs-2.0/intuition-library-newobject.md) is successful, it returns a pointer to a new Boopsi gadget
object.  Otherwise, it returns NULL.  The class "[strgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)" is one of the
public classes built into Release 2.  It is a class of string gadgets.

If you look at the diagram of the public classes built into Intuition,
you'll see that [strgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) is a subclass of [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md). In the example
above, the attribute tag IDs that start with "GA_" are defined by
gadgetclass and not by strgclass.  This is because strgclass inherits
these attributes from its superclass, gadgetclass. The other attribute,
[STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md), is defined by strgclass.  It does two things.  First, it
tells the object that it is a special type of string gadget which only
handles an integer value rather than a generic ASCII string.  Second, it
passes the object its initial integer value.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
