---
title: IV-23: Introduction to Boopsi
manual: amiga-mail
chapter: amiga-mail
section: iv-23-introduction-to-boopsi
functions: [DisposeObject, GetAttr, NewObject, SetAttrsA]
libraries: [intuition.library]
---

# IV-23: Introduction to Boopsi

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By John Orr


Boopsi is an acronym for Basic Object Oriented Programming System for
Intuition.  On its simplest level, boopsi allows the application
programmer to create Intuition supported gadgets and images with minimal
overhead.  It allows a program to consolidate gadgets into one entity to
make processing and updating easy.  On a more sophisticated level,
boopsi provides ways to create a wide variety of system supported,
extensible custom gadgets.

Understanding boopsi requires an understanding of several of the
concepts behind Object Oriented Programming (OOP).  This article only
briefly covers those concepts.  For a more in depth explanation of those
concepts, see Timothy Budd's book titled A Little Smalltalk (Addison-
Wesley Publishing ISBN 0-201-10698-1).  A port (by Bill Kinnersley) of
Timothy Budd's Little Smalltalk interpreter is on Fish disk #37.

In the boopsi version of the Object Oriented Programming (OOP) model,
everything is an Object.  Each object is a distinct entity.  Certain
objects have similar characteristics and can be classified into
different groups called classes.  As objects, a dog, a cat, and a mouse
are all distinct objects but they all have something in common; they can
all be classified as animals.  A specific object is an instance of a
particular class ("Rover" is an instance of class "dog").

Classes can be subdivided into subclasses.  A vegetable object class can
have several subclasses such as peas, corn, and spinach.  Inversely, the
superclass of peas, corn, and spinach is "vegetable".  In turn, both
the "animal" and "vegetable" classes are subclasses.   They are
subclasses of a universal root category.  The OOP language Smalltalk
calls this class "Object".




                      Figure 1 - Classes


                            object
                               |
                    ___________|__________
                   /                      \
                  /                        \
               animal                  vegetables
                 |                          |
            _____|_____                _____|_____
           /     |     \              /     |     \
          /      |      \            /      |      \
        dog     cat    mouse       peas    corn  spinach
In boopsi, the universal root category is called rootclass.  Intuition
supplies three subclasses of rootclass: gadgetclass, imageclass, and
icclass.  All boopsi gadgets in the system are an instance of
gadgetclass.  Likewise, all boopsi images are an instance of imageclass.
The remaining subclass, icclass, is a concept new to Intuition that
allow one boopsi object (such as a gadget) to notify another boopsi
object when some specific event occurs.    For example, a program can
offer a user two methods of altering one integer value; one by sliding a
proportional gadget, the other by typing in a value at a string gadget.
Without boopsi, the program would have to explicitly update one gadget
when the other was altered by the user.  Using a boopsi icclass object,
the gadgets can update each other.  The gadgets update each other
automatically, without the calling program's intervention.

The rootclass' subclasses each have their own subclasses.  These
subclasses are discussed later in this article.


                 Figure 2 - The Boopsi Classes


                            rootclass
                               /
                 _____________/____________
                /         /                \
               /         /                  \
           icclass      /                gadgetclass
             /         /                      \
            /         /         _______________\___________________
           /     imageclass    /           /         \             \
          /         /         /           /           \             \
     modelclass    /      propgclass  strgclass  buttongclass  groupgclass
                  /                                     \
                 /                                       \
         _______/___________________________        frbuttongclass
        /         \            \            \
       /           \            \            \
  frameiclass  sysiclass  fillrectclass  itexticlass


It is possible for an application to create its own custom boopsi class.
When an application creates a class, it can make it either public or
private.  A public class has a name associated with it (for example
gadgetclass) so arbitrary applications can access it.  A private class
has no name associated with it, so unless an application has a pointer
to the class, it cannot access it.

Each class has a set of methods associated with it  Each method of a
class is an operation that applies to objects of that class.  A example
of a method for a class of integers is to add or to subtract "integer"
objects.  All boopsi actions are carried out via methods.

In OOP terminology, an application requests an object to perform some
method by sending the object a message (which is not related to the Exec
style message).  In boopsi, the amiga.lib function DoMethod() accepts a
method ID and some method specific parameters (older versions of
amiga.lib do not have DoMethod(), but the function is available on the
Atlanta DevCon disks in classface.o).  DoMethod() creates a message from
these parameters and sends the message to the object:


```c
    ULONG DoMethod(Object *myobject, ULONG MethodID, ...);
```
where myobject is a pointer to the target object, MethodID specifies
which method to perform.  Any remaining parameters are passed on to the
method in the form of a boopsi message.  Each message contains the
method ID and the parameters for the method.  The parameters are method
specific.  For example, one way to delete the imageclass object
obj2delete is to call the DoMethod() function like this:


```c
    DoMethod(obj2delete, OM_DISPOSE);
```
The OM_DISPOSE method does not require any arguments, so, in this case,
DoMethod() has only two arguments.

One peculiar thing about the above function call is that the OM_DISPOSE
method is not defined for imageclass.  It is instead defined in the
superclass of imageclass, rootclass.  The OM_DISPOSE method works
because imageclass inherits the methods of its superclass, rootclass.
If an object is asked to perform a method that its class does not
explicitly define, it passes the request onto its superclass for
processing.  This superclass can in turn pass on the request to its
superclass if it does not understand the method requested.


Some of the methods currently defined for Boopsi's rootclass are:


OM_NEW - Creates a new object.  Normally this method is not called
directly by the application programmer (a.k.a. using the DoMethod()
function).  Instead, there is an Intuition function called NewObject()
that takes care of creating objects.


```c
    APTR NewObject( struct IClass *privateclass, UBYTE *publicclassID,
                      unsigned long tag1, ...);
```
The privateclass and publicclassID parameters are used to specify the
new object's class. NewObject() only pays attention to one of these.
If privateclass is NULL, publicclassID points to a string naming the
class of the new object.  If privateclass is not NULL, it contains a
pointer to a private class.  The remaining arguments make up a series
of tag ID/data pairs.  These are used to set the object's default
attributes.  These attributes are specific to the class in question.
This function returns a handle to the new object.

Each object (or instance of a class) has instance data associated with
it.  The OM_NEW method takes care of allocating memory for the instance
data for each class.  Instance data is class specific, but all
subclasses inherit instance data from their superclasses.  For example,
part of the instance data for a gadgetclass object is a Gadget
structure.  Any objects that are instances of subclasses of gadgetclass
have a Gadget structure embedded in them.  Subclasses can have their own
class specific instance data in addition to the instance data inherited
from the superclass.

Boopsi gadgetclass and imageclass objects are organized so that
NewObject() returns a pointer to the corresponding Intuition structure
embedded within them (struct Gadget and struct Image, respectively).
This makes it possible to use non-boopsi Intuition functions on boopsi
objects.  Normally, these internal structures should be considered
private, and should be accessed through the corresponding attributes,
but if it is necessary, an application can look at certain fields in the
embedded structure.  For both gadgets and images, the Left, Top, Width,
and Height fields are legal to look at.  The Images NextImage field is
also OK for viewing.  However, this does not mean that it is OK for an
application to go poking around the internals of boopsi objects.  All
boopsi objects are strictly private and can change without notice.  Use
only the functions Intuition provides for manipulating boopsi objects.

Another function, NewObjectA(), works exactly like NewObject(), but
instead of accepting the tag pairs as arguments, it accepts a single
pointer to a TagList.  See the Intuition Autodocs for more details.


OM_DISPOSE - Deletes an object.  Like OM_NEW this method is not normally
called directly by the application program.  Instead there is an
Intuition function DisposeObject() that takes care of object disposal.



```c
    void DisposeObject( APTR object2delete );
```
OM_SET - Sets object specific attributes.  This method is not normally
called by the application program directly.  Instead, there are two
Intuition functions that set object attributes:


```c
    ULONG SetAttrs( APTR object, unsigned long tag1, ... );

    ULONG SetGadgetAttrs( struct Gadget *mygadgetobject, struct Window
        *window, struct Requester *requester, unsigned long tag1, ... );
```
SetAttrs() accepts as arguments a pointer to the object in question and
a series of tag pairs corresponding to the attributes to set.
SetGadgetAttrs() is a special version of SetAttrs() that is required to
change the attributes of gadgetclass objects.  SetGadgetAttrs() is
similar to SetAttrs(), except it has some extra parameters that a gadget
needs to redraw itself in response to the attribute changes.  This
function can be used on non-gadgetclass objects as the gadget specific
parameters are ignored by the other object classes.  If the gadget is
not yet attached to a window or requester, these arguments should be set
to NULL.

Both of these functions have corresponding TagList based arguments,
SetAttrsA() and SetGadgetAttrs().


OM_GET - Reads an object specific attribute.  The Intuition function
GetAttr() provides easy access to this method:


```c
    ULONG GetAttr( unsigned long attrID, APTR object, ULONG *storagePtr );
```
GetAttr() fills in storagePtr with the value of the object's attribute
attrID.  The function returns FALSE if there is an error.


OM_ADDMEMBER - Adds a boopsi object to another object's list, if it has
one.  Certain object classes have an Exec list as part of their instance
data.  To add the object object2add to the list of the object mainobject
use DoMethod() like so:


```c
    DoMethod(mainobject, OM_ADDMEMBER, object2add);
```
DoMethod() also has a non-varargs form called DM() (also in amiga.lib).
DM() accepts an object pointer and a pointer to a structure specific to
a method.  For example, the DM() form of the above DoMethod() call would
look like this:


```c
    DM(mainobject, addmemstruct);
```
where addmemstruct is a pointer to the following structure (defined in
<intuition/classusr.h>):

```c
    struct opMember {
        ULONG    MethodID;      /* in this case MethodID = OM_ADDMEMBER */
        Object   *opam_Object;  /* = addmemstruct */
```
};


OM_REMMEMBER - Removes a boopsi object previously added with
OM_ADDMEMBER.  The parameters are the same for OM_ADDMEMBER.


OM_UPDATE - Updates attributes of an object.  For gadgets, this method
is very similar to the OM_SET method.  It is normally used only between
objects for notifying each other of attribute changes, so simple boopsi
users should use the SetAttrs() and SetGadgetAttrs() functions.


OM_NOTIFY - Notifies one object when another object's attribute(s) have
changed.  It is normally used only between objects for modifying each
others attributes, so simple boopsi users should use the SetAttrs() and
SetGadgetAttrs() functions.


 [Attributes](amiga-mail/attributes.md)                 [Gadgetclass Subclasses](amiga-mail/gadgetclass-subclasses.md)      [Appendix](amiga-mail/iv-23-appendix-boopsi-class-reference.md) 
 [Imageclass Subclasses](amiga-mail/imageclass-subclasses.md)      [Interconnection](amiga-mail/interconnection.md) 

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetAttrsA — intuition.library](../autodocs/intuition.library.md#setattrsa)
