# 12 Boopsi--Object Oriented Intuition


Boopsi is an acronym for Basic Object Oriented Programming System for
Intuition.  Using the Object Oriented Programming (OOP) model, Boopsi
represents certain Intuition entities, like [Gadget](../Libraries_Manual_guide/node0149.html)s and [Image](../Libraries_Manual_guide/node01BA.html)s, as objects.

There are many advantages to using Boopsi:

  * Boopsi makes Intuition customizable and extensible.  Boopsi

    programmers can create new types of Boopsi objects to suit the needs
    of their applications.  These new types of objects are part of
    Intuition and can be made public so other applications can use them.
    Because applications can share the new types, application writers
    don't have to waste their time duplicating each other's efforts
    writing the same objects.
  * New types of Boopsi objects can build on old types of Boopsi objects,

    inheriting the old object's behavior.  The result is that Boopsi
    programmers don't have to waste their time building new objects from
    scratch, they simply add to the existing object.
  * OOP and Boopsi apply the concept of interchangeable parts to

```c
    Intuition programming.  A Boopsi programmer can combine different
    Boopsi objects (like gadgets and images) to create an entire
    Graphical User Interface (GUI).  The Boopsi programmer doesn't have
    take the time to understand or implement the inner workings of these
    objects.  The Boopsi programmer only needs to know how to interact
    with Boopsi objects and how to make them interact with each other.
```
  * Boopsi objects have a consistent, command-driven interface.  To the

    Boopsi programmer, there is no difference between displaying a text,
    border, or bitmap-based Boopsi image, even though they are rendered
    quite differently.  Each image object accepts a single command to
    tell it to render itself.
Before reading this chapter, you should already be familiar with several
Amiga concepts.  Boopsi is built on top of Intuition and uses many of its
structures.  These include Intuition gadgets, images, and windows.  Boopsi
also uses the tag concept  to pass parameters.  The "[Utility Library](../Libraries_Manual_guide/node0495.html)"
chapter of this manual discusses [tags](../Libraries_Manual_guide/node0496.html).  The "Utility Library" chapter also
discusses [callback Hooks](../Libraries_Manual_guide/node04A2.html), which are important to the later sections of
this chapter.

 [OOP Overview](../Libraries_Manual_guide/node0200.html)               [Boopsi Gadgets](../Libraries_Manual_guide/node0218.html) 
 [Creating a Boopsi Class](../Libraries_Manual_guide/node020E.html)    [Function Reference](../Libraries_Manual_guide/node0220.html) 

