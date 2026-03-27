---
title: OM_NEW
manual: amiga-mail
chapter: amiga-mail
section: om-new
functions: []
libraries: []
---

# OM_NEW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The OM_NEW method receives the following arguments:


```c
    struct opSet
    {
        ULONG MethodID;
        struct TagItem *ops_AttrList;
        struct GadgetInfo *ops_GInfo;
    };
```
The ops_AttrList field contains a pointer to the TagItem array of
attributes for the new object.  The ops_GInfo field is always NULL for the
OM_NEW method.

Unlike other methods, this method is not passed an object pointer (since
the whole idea is to create an object).  The pointer normally used to pass
a boopsi object is instead used to pass the address of the object's "true
class" (the class the object is an instance of).  That way, all class
dispatchers can tell if they are the "true class" of the object being
created (as opposed to a superclass of the true class).  Also, with this
pointer, rootclass can determine what the instance data is for an object,
and can allocate the right amount of memory for it.

For the OM_NEW method, the new class's dispatcher should do the following:

1) Pass the message along to the superclass.  All classes do this as
   rootclass takes care of allocating memory for the new object.  As the
   OM_NEW method works "top down" (from rootclass down through its
   subclasses to the true class), each class will in turn initialize its
   corresponding instance data.  This all happens before the new class's
   dispatcher regains control.  Eventually, the message comes back from
   the superclass with a newly allocated object (unless of course
   something failed and you receive a NULL pointer instead).

2) Obtain a pointer to the object's instance data for this class.  Use the
   INST_DATA() macro (defined in <intuition/classes.h>).  INST_DATA()
   takes two arguments, a pointer to your class and a pointer to the
   object.


```c
       void *INST_DATA(*Class, *Object);
```
3) Initialize your instance data.  You may allocate additional memory
   buffers for your object, or even create other objects which are
   components to objects of your class.

4) Process your initial attribute list (from the opSet structure passed in
   the OM_NEW message).  In particular, process all the attributes that
   can be set only at initialization time.  After you deal with the
   "initialization only" attributes, apply the same attribute processing
   on these remaining attributes that you would apply to an OM_SET
   message.

5) Return the object to the caller.

