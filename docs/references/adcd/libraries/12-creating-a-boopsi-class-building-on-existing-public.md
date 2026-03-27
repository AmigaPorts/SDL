---
title: 12 / Creating a Boopsi Class / Building On Existing Public Classes
manual: libraries
chapter: libraries
section: 12-creating-a-boopsi-class-building-on-existing-public
functions: []
libraries: []
---

# 12 / Creating a Boopsi Class / Building On Existing Public Classes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A program can create its own subclasses which build on the features of
existing classes.  For example, a program could create a subclass of
[modelclass](libraries/12-oop-overview-the-interconnection-classes.md) named rkmmodelclass.  Rkmmodelclass builds on modelclass by
adding a new attribute called RKMMOD_CurrVal.  This purpose of this
attribute is simply to hold an integer value.

Because this new attribute is built into an rkmmodel object, the object
could be implemented so that it exercises a certain amount of control over
that value.  For example, rkmmodelclass could be implemented so an
rkmmodel performs bounds checking on its internal value.  When an
application asks an rkmmodel to set its internal RKMMOD_CurrVal, the
rkmmodel makes sure the new value is not beyond a maximum value.  If the
new value is beyond the maximum, it sets its current value to the maximum.
After the rkmmodelclass object has set its internal RKMMOD_CurrVal, it can
broadcast the change on to objects in its broadcast list.

The dispatcher for rkmmodelclass does not have to do a lot of work because
it inherits most of its behavior from its superclasses.  The rkmmodelclass
has to take care of setting aside memory for the RKMMOD_CurrVal attribute
and processing any [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) requests to set the RKMMOD_CurrVal attribute.
For any other attributes or methods, the rkmmodelclass dispatcher passes
on processing to its superclass, [modelclass](libraries/12-oop-overview-the-interconnection-classes.md).

 [Building Rkmmodelclass](libraries/12-building-on-existing-public-classes-building.md) 

