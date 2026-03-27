---
title: 12 Boopsi--Object Oriented Intuition / Function Reference
manual: libraries
chapter: libraries
section: 12-boopsi-object-oriented-intuition-function-reference
functions: [AddClass, DisposeObject, FreeClass, GetAttr, MakeClass, NewObject, ObtainGIRPort, ReleaseGIRPort, RemoveClass]
libraries: [intuition.library]
---

# 12 Boopsi--Object Oriented Intuition / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition and amiga.lib
functions discussed in this chapter.  See the "Amiga ROM Kernel Reference
Manual: Includes and Autodocs" for details on each function call.  All
these functions require Release 2 or a later version of the Amiga
operating system.

              Table 12-1: Intuition Library Boopsi Functions
  ________________________________________________________________________
 |                                                                        |
 |       Function                 Description                             |
 |========================================================================|
 |      [NewObjectA()](autodocs-2.0/intuition-library-newobject.md)  Create a new Boopsi object (tag array form).        |
 |       [NewObject()](autodocs-2.0/intuition-library-newobject.md)  Create a new Boopsi object (varargs form).          |
 |   [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md)  Dispose of a Boopsi object.                         |
 |        [SetAttrs()](autodocs-2.0/intuition-library-setattrsa.md)  Set one or more of a Boopsi object's attributes     |
 |                    (tag array form).                                   |
 |  [SetGadgetAttrs()](autodocs-2.0/intuition-library-setgadgetattrsa.md)  Set one or more of a Boopsi object's attributes     |
 |                    (varargs form).                                     |
 |         [GetAttr()](autodocs-2.0/intuition-library-getattr.md)  Obtain an attribute from a Boopsi object.           |
 |------------------------------------------------------------------------|
 |       [MakeClass()](autodocs-2.0/intuition-library-makeclass.md)  Create a new private or public Boopsi class.        |
 |       [FreeClass()](autodocs-2.0/intuition-library-freeclass.md)  Free a Boopsi class created by MakeClass().         |
 |        [AddClass()](autodocs-2.0/intuition-library-addclass.md)  Add a public Boopsi class to Intuition's internal   |
 |                    list of public classes.                             |
 |     [RemoveClass()](autodocs-2.0/intuition-library-removeclass.md)  Remove a public Boopsi class that was added to      |
 |                    Intuition's internal list with AddClass().          |
 |------------------------------------------------------------------------|
 |   [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md)  Set up a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) for use by a Boopsi gadget        |
 |                    dispatcher.                                         |
 |  [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md)  Free a RastPort set up by ReleaseGIRPort().         |
 |________________________________________________________________________|


                  Table 12-2: Amiga.lib Boopsi Functions
  ________________________________________________________________________
 |                                                                        |
 |       Function                 Description                             |
 |========================================================================|
 |       [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md)  Send a Boopsi message to a Boopsi object            |
 |                    (tag array form).                                   |
 |        [DoMethod()](autodocs-2.0/amiga-lib-domethod.md)  Send a Boopsi message to a Boopsi object            |
 |                    (varargs form).                                     |
 |  [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of its class's superclass    |
 |                    (tag array form).                                   |
 |   [DoSuperMethod()](autodocs-2.0/amiga-lib-dosupermethod.md)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of its class's superclass    |
 |                    (varargs form).                                     |
 |   [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of the specified class       |
 |                    (tag array form).                                   |
 |    [CoerceMethod()](autodocs-2.0/amiga-lib-coercemethod.md)  Send a Boopsi message to a Boopsi object as if the  |
 |                    object was an instance of the specified class       |
 |                    (varargs form).                                     |
 |   [SetSuperAttrs()](autodocs-2.0/amiga-lib-setsuperattrs.md)  Send a Boopsi [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message to the Boopsi object's |
 |                    superclass.                                         |
 |________________________________________________________________________|

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
