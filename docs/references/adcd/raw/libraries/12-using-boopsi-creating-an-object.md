# 12 / / Using Boopsi / Creating an Object


The Intuition function [NewObjectA()](../Includes_and_Autodocs_2._guide/node022F.html) creates a Boopsi object:


```c
    mynewobject = APTR NewObjectA(Class *privclass, UBYTE *pubclass,
                                  struct TagItem *myattrs)
```
The pointer that [NewObjectA()](../Includes_and_Autodocs_2._guide/node022F.html) returns is a pointer to a Boopsi object.  In
general, Boopsi objects are "black boxes".  This means the inner workings
of Boopsi objects are not visible to the application programmer, so the
programmer does not know what goes on inside it.  This really means the
inner workings of these objects are none of your business.  Unless
otherwise documented, only use an object pointer as a handle to the object.

To create an object, [NewObjectA()](../Includes_and_Autodocs_2._guide/node022F.html) needs to know what class the new object
is an instance of.  To create a public class object, pass a NULL pointer
in privclass and an ASCII string in pubclass naming the object's public
class.  The privclass pointer is used to create a private class object,
which is covered in the "[Creating a Boopsi Class](../Libraries_Manual_guide/node0215.html)" section later in this
chapter.

The myattrs tag list is a list of tag/value pairs, each of which contains
an initial value for some object attribute.  Most objects have a set of
attributes associated with them, so each attribute has a tag name.  For
Boopsi gadgets and images, the attributes include some of the values from
the old [Gadget](../Libraries_Manual_guide/node0149.html) and [Image](../Libraries_Manual_guide/node01BA.html) structures (position, size, etc.).

Most applications use the stack-based version of [NewObjectA()](../Includes_and_Autodocs_2._guide/node022F.html),
[NewObject()](../Includes_and_Autodocs_2._guide/node022F.html), to create objects.  This allows an application to build the
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
If [NewObject()](../Includes_and_Autodocs_2._guide/node022F.html) is successful, it returns a pointer to a new Boopsi gadget
object.  Otherwise, it returns NULL.  The class "[strgclass](../Libraries_Manual_guide/node020A.html#line7)" is one of the
public classes built into Release 2.  It is a class of string gadgets.

If you look at the diagram of the public classes built into Intuition,
you'll see that [strgclass](../Libraries_Manual_guide/node020A.html#line7) is a subclass of [gadgetclass](../Libraries_Manual_guide/node020A.html). In the example
above, the attribute tag IDs that start with "GA_" are defined by
gadgetclass and not by strgclass.  This is because strgclass inherits
these attributes from its superclass, gadgetclass. The other attribute,
[STRINGA_LongVal](../Libraries_Manual_guide/node0512.html), is defined by strgclass.  It does two things.  First, it
tells the object that it is a special type of string gadget which only
handles an integer value rather than a generic ASCII string.  Second, it
passes the object its initial integer value.

