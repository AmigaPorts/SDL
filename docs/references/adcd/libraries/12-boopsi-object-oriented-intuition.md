---
title: 12 Boopsi--Object Oriented Intuition
manual: libraries
chapter: libraries
section: 12-boopsi-object-oriented-intuition
functions: []
libraries: []
---

# 12 Boopsi--Object Oriented Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Boopsi is an acronym for Basic Object Oriented Programming System for
Intuition.  Using the Object Oriented Programming (OOP) model, Boopsi
represents certain Intuition entities, like [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)s and [Image](libraries/8-creating-images-image-structure.md)s, as objects.

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
also uses the tag concept  to pass parameters.  The "[Utility Library](libraries/37-utility-library.md)"
chapter of this manual discusses [tags](libraries/37-utility-library-tags.md).  The "Utility Library" chapter also
discusses [callback Hooks](libraries/37-utility-library-callback-hooks.md), which are important to the later sections of
this chapter.

 [OOP Overview](libraries/12-boopsi-object-oriented-intuition-oop-overview.md)               [Boopsi Gadgets](libraries/12-boopsi-object-oriented-intuition-boopsi-gadgets.md) 
 [Creating a Boopsi Class](libraries/12-boopsi-object-oriented-intuition-creating-a-boopsi-class.md)    [Function Reference](libraries/12-boopsi-object-oriented-intuition-function-reference.md) 

