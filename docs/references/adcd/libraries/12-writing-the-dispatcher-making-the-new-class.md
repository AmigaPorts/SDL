---
title: 12 / / Writing The Dispatcher / Making the New Class
manual: libraries
chapter: libraries
section: 12-writing-the-dispatcher-making-the-new-class
functions: [AddClass, FreeClass, MakeClass, RemoveClass]
libraries: [intuition.library]
---

# 12 / / Writing The Dispatcher / Making the New Class

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Intuition function [MakeClass()](autodocs-2.0/intuition-library-makeclass.md) creates a new Boopsi class:


```c
    Class *MakeClass(UBYTE *newclassID, UBYTE *pubsuperclassID,
                     Class *privsuperclass, UWORD instancesize,
                     ULONG flags);
```
If the new class is going to be public, newclassID is a string naming the
new class.  If the new class is private, this field is NULL.  The next two
fields tell [MakeClass()](autodocs-2.0/intuition-library-makeclass.md) where to find the new class's superclass.  If the
superclass is public, pubsuperclassID points to a string naming that
public superclass and the privsuperclass pointer is NULL.  If the
superclass is private, privsuperclass points to that superclass's Class
structure and pubsuperclassID is NULL. The size of the new class's local
instance data is instancesize.  The last parameter, flags, is for future
enhancement.  For now, make this zero.

If it is successful, [MakeClass()](autodocs-2.0/intuition-library-makeclass.md) returns a pointer to the new class,
otherwise it returns NULL.  When MakeClass() is successful, it also takes
measures to make sure no one can "close" the new class's superclass (using
[FreeClass()](autodocs-2.0/intuition-library-freeclass.md)).  It does this by incrementing a private field of the
superclass that keeps track of how many subclasses the superclass
currently has.

After successfully creating a class, an application has to tell the class
where its dispatcher is. The Class pointer (defined in
<intuition/[classes.h](autodocs-2.0/includes-intuition-classes-h.md)>) returned by [MakeClass()](autodocs-2.0/intuition-library-makeclass.md) contains a Hook structure
called cl_Dispatcher, which is used to call the dispatcher.  The
application has to initialize this hook:


```c
    myclass->cl_Dispatcher.h_Entry = HookEntry;
    /* HookEntry() is defined in amiga.lib */

    myclass->cl_Dispatcher.h_SubEntry = dispatchRKMModel;
```
The h_Entry field points to a function in amiga.lib that copies the
function arguments to where the dispatcher expects them. See the
"[Callback Hooks](libraries/37-callback-hooks-callback-hook-structure-and-function.md)" section of the "Utility Library" chapter of this manual for
more details.

To make a class public instead of private, an application has to call
AddClass() in addition to giving the class a name in [MakeClass()](autodocs-2.0/intuition-library-makeclass.md).
AddClass() takes one argument, a pointer to a valid Class structure that
has been initialized as a public class by MakeClass().  To remove a public
class added to the system with AddClass(), pass the public class pointer
to RemoveClass().  See the Intuition Autodocs for more details on
[AddClass()](autodocs-2.0/intuition-library-addclass.md) and [RemoveClass()](autodocs-2.0/intuition-library-removeclass.md).

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
