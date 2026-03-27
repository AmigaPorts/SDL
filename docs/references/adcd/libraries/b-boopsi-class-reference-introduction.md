---
title: B Boopsi Class Reference / Introduction
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-introduction
functions: []
libraries: []
---

# B Boopsi Class Reference / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are 14 public classes built into the Release 2.04 ROM:


```c
                            [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
                               /
                 _____________/____________
                /         /                \
               /         /                  \
           [icclass](libraries/b-boopsi-class-reference-icclass.md)      /                [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md)
             /         /                      \
            /         /         _______________\___________________
           /     [imageclass](libraries/b-boopsi-class-reference-imageclass.md)    /           /         \             \
          /         /         /           /           \             \
     [modelclass](libraries/b-boopsi-class-reference-modelclass.md)    /      [propgclass](libraries/b-boopsi-class-reference-propgclass.md)  [strgclass](libraries/b-boopsi-class-reference-strgclass.md)  [buttongclass](libraries/b-boopsi-class-reference-buttongclass.md)  [groupgclass](libraries/b-boopsi-class-reference-groupgclass.md)
                  /                                     \
                 /                                       \
         _______/___________________________        [frbuttongclass](libraries/b-boopsi-class-reference-frbuttonclass.md)
        /         \            \            \
       /           \            \            \
```
  [frameiclass](libraries/b-boopsi-class-reference-frameiclass.md)  [sysiclass](libraries/b-boopsi-class-reference-sysiclass.md)  [fillrectclass](libraries/b-boopsi-class-reference-fillrectclass.md)  [itexticlass](libraries/b-boopsi-class-reference-itexticlass.md)


This appendix documents all the standard Boopsi classes, including their
methods and attributes.

Each class entry in this document can have two sets of methods: new
methods that the class defines and inherited methods that the class has
modified significantly.  Similarly, each class entry can have two sets of
attributes: those that the class defines and those that the class
inherited and modified.  Unless documented otherwise,  all classes inherit
all of its superclass's methods and attributes.

Each method has a Boopsi message associated with it.  These messages are
in the form of C structures.  Many methods use the default message
structure:


```c
    typedef struct
    {
        ULONG MethodID;
    } *Msg;
```
Some methods require a customized message so they can pass other
parameters besides the Method ID.  If a method requires a custom message,
its custom message structure is documented along with the method.

All methods have to return some sort of return value.  The meaning of the
return value depends on the class and method.  Normally a return value of
zero indicates that either the method failed or it is not supported by the
class.  A method can use the return value to return a pointer to an
object.  If a class does not directly support a particular method, the
class's dispatcher should pass the method on to its superclass for
processing.  The class dispatcher should record the return value it gets
from its superclass and use that as its return value.  Methods that assign
no meaning to their return value can return 1L to indicate that the method
is implemented.

The description of each attribute contains a code which lists the
[rootclass](libraries/b-boopsi-class-reference-rootclass.md) methods that apply to that attribute:


```c
    I  [OM_NEW](libraries/b-rootclass-new-methods-om-new.md)     Attribute can be set at initialization
    S  [OM_SET](libraries/b-rootclass-new-methods-om-set.md)     Attribute can be set with OM_SET method
    G  [OM_GET](libraries/b-rootclass-new-methods-om-get.md)     Attribute can be read with OM_GET method
    N  [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md)  Changing the attribute triggers object to send
                  notifications
    U  [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)  Attribute can be set with OM_UPDATE method
```
For example, the [itexticlass](libraries/b-boopsi-class-reference-itexticlass.md) attribute [IA_Left](libraries/b-imageclass-attributes-ia-left-ia-top-ia-width-ia-height.md) has the code (ISG) after
it.  This means an application can set IA_Left when it creates an instance
of itexticlass ([OM_NEW](libraries/b-rootclass-new-methods-om-new.md)) and when it uses the OM_SET method.  The
application can also ask an itexticlass object what the IA_Left value is,
using the [OM_GET](libraries/b-rootclass-new-methods-om-get.md) method.

The [OM_NEW](libraries/b-rootclass-new-methods-om-new.md), [OM_SET](libraries/b-rootclass-new-methods-om-set.md), [OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md), and [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) messages all contain a
pointer to a tag list.  This tag list contains the attributes and
corresponding values that the method affects.  Each [TagItem](libraries/37-tags-tag-functions-and-structures.md) in this list
makes up an attribute/value pair.  The [ti_Tag](libraries/37-tags-tag-functions-and-structures.md) portion of the TagItem
contains the attribute's ID while the [ti_Data](libraries/37-tags-tag-functions-and-structures.md) field contains the
attribute's value.  Note that these tag lists can also contain
utility.library Global System control tags (like [TAG_SKIP](libraries/37-tags-simple-tag-usage.md) and [TAG_DONE](libraries/37-tags-simple-tag-usage.md)),
so dispatchers should use the tag functions from utility.library to
process these lists.  See documentation on the [Utility](libraries/37-utility-library.md) library for more
information.

All methods are called via a class dispatcher:


```c
    classDispatcher(Class *class, Object *object, Msg msg);
```
The first argument, class, is a pointer to the dispatcher's Class
structure (defined in <intuition/[classes.h](autodocs-2.0/includes-intuition-classes-h.md)>).  The second parameter,
object, is a pointer to the Boopsi object to which the Boopsi message (the
third argument, msg) refers.  Both [Object](autodocs-2.0/includes-intuition-classusr-h.md) and [Msg](autodocs-2.0/includes-intuition-classusr-h.md) are defined in
<intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>.

