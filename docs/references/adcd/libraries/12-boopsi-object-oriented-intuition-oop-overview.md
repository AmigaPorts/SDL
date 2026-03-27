---
title: 12 Boopsi--Object Oriented Intuition / OOP Overview
manual: libraries
chapter: libraries
section: 12-boopsi-object-oriented-intuition-oop-overview
functions: []
libraries: []
---

# 12 Boopsi--Object Oriented Intuition / OOP Overview

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Understanding Boopsi requires an understanding of several of the concepts
behind Object Oriented Programming.  This section is a general overview of
these concepts as they pertain to Boopsi.  Because Boopsi is in part based
on the concepts present in the OOP language Smalltalk, a reference book on
Smalltalk may provide a deeper understanding of Boopsi in general.
Timothy Budd's book entitled A Little Smalltalk (Addison-Wesley Publishing
ISBN 0-201-10698-1) is a good start.

In the Boopsi version of the Object Oriented Programming model, everything
is an Object.  For example, a proportional gadget named myprop is an
object.  Certain objects have similar characteristics and can be
classified into groups called classes.  As objects, Rover the dog, Bob the
cat, and Sam the bird are all distinct objects but they all have something
in common, they can all be classified as animals.  As objects, myprop the
proportional gadget, mystring the string gadget, and mybutton the button
gadget all have something in common, they can all be classified as
gadgets.  A specific object is an instance of a particular class ("Rover"
is an instance of class "animal", "myslidergadget" is an instance of class
"gadget").

Notice that, although Rover, Bob, and Sam can all be classified as
animals, each belongs to a subgroup of the animal class.  "Rover" is an
instance of class "dog", "Bob" is an instance of class "cat", and "Sam" is
an instance of class "bird".  Because each of these animal types share
common characteristics, each type makes up its own class.  Because dog,
cat, and bird are subclassifications of the animal class, they are known
as subclasses of the animal class.  Conversely, the animal class is the
superclass of the dog, cat, and bird classes.

Following the branches upward from class to superclass will bring you to a
universal root category from which all objects are derived.  The OOP
language Smalltalk calls this class "Object".




                  Figure 12-1: Object Diagram


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
Like Smalltalk, Boopsi also has a universal root catagory, [rootclass](libraries/b-boopsi-class-reference-rootclass.md).
Currently, Intuition defines three immediate subclasses of rootclass.  The
first, [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md), is the class of Boopsi gadgets.  The second class,
[imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md), makes up the class of Boopsi images.

Unlike [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) and [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md), the remaining subclass, [icclass](libraries/b-boopsi-class-reference-icclass.md), does
not correspond to an existing Intuition entity, it is a concept new to
Intuition.  Icclass, or interconnection class, allows one Boopsi object to
notify another Boopsi object when a specific event occurs.  For example,
consider a Boopsi proportional gadget and a Boopsi image object that
displays an integer value.  An application can connect these two objects
so that the prop gadget tells the image object the prop gadget's current
value, which the image object displays.  Every time the user slides the
prop gadget, the prop gadget notifies the image of the change and the
image updates its display to reflect the prop gadget's current integer
value.  Because these objects are talking to each other rather than the
application, the updates happen automatically.  The application doesn't
have to talk to the two objects, it only has to connect them.


```c
     [Figure 12-2: Simple Boopsi Diagram](libraries/lib-pics-12-2-pic.md) 
```
An object's characteristics and behavior are determined by its class. Each
class can define a set of attributes and a set of methods that apply to
all objects of that class.  An attribute is a variable characteristic of
an object.  For example, an attribute for the animal class could be the
number of legs an animal object has.  An example of a Boopsi attribute is
the X coordinate of a Boopsi image object.  The data that makes up the
values of an object's attributes is collectively known as the instance
data for that object.

The behavior of an object depends upon the set of methods associated to it
by its class.  A method is basically a function that applies to objects of
that class.  An example of a Boopsi method is the [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md) method
[IM_DRAW](libraries/b-imageclass-new-methods-im-draw.md).  This method tells a Boopsi image to draw itself.  All Boopsi
actions are carried out via methods.

From the Object Diagram, two of the methods of the "animal" class could be
"eat" and "sleep".  One of the methods of the "dog" class could be "bark".
Notice that instances of the "dog" class can do more than just bark, they
can also eat and sleep. This is because a subclass inherits methods from
its superclasses. If there were a subclass of dog called "attack dog", all
instances of that class would be able to bark, eat, and sleep, as well as
"attack".  Due to inheritance, a subclass has all of the methods and all
of the attributes of its superclass.  For example, the [IA_Height](libraries/b-imageclass-attributes-ia-fgpen-ia-bgpen-isg.md) attribute
is defined by [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md).  All instances of the subclasses of imageclass
have their own IA_Height attribute, even though the subclasses do not
explicitly define IA_Height.  In turn, all instances of subclasses of the
imageclass subclasses also inherit the IA_Height attribute.  All classes
on levels below a class will inherit its methods and attributes.

When an application or a Boopsi object wants another Boopsi object to
perform a method, it passes it a command in the form of a Boopsi message.
A Boopsi message tells an object which method to perform.  The message may
also contain some parameters that the method requires.


    Watch Out!
    ----------
    The term "message" used in object oriented terminology can be little
    confusing to the Amiga programmer because the Boopsi message has
    nothing to do with an Exec message.
Boopsi classes can be either public or private.  Public classes have ASCII
names associated with them and are accessible to all applications.
Private classes have no ASCII name and normally can only be accessed by
the application that created the private class.

 [Using Boopsi](libraries/12-oop-overview-using-boopsi.md) 
 [The Public Classes](libraries/12-oopoverview-the-public-classes.md) 
 [Making Gadget Objects Talk to Each Other](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md) 
 [Making Gadgets Talk to an Application](libraries/12-oop-overview-making-gadgets-talk-to-an-application.md) 
 [The Interconnection Classes](libraries/12-oop-overview-the-interconnection-classes.md) 

