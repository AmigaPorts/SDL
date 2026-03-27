---
title: reaction.lib/LibDoGadgetMethodA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-libdogadgetmethoda
functions: [AddGList, AddGadget, DisposeObject, GetAttr, MakeClass, NewObject]
libraries: [intuition.library]
---

# reaction.lib/LibDoGadgetMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       LibDoGadgetMethodA -- [DoGadgetMethodA](autodocs-3.5/intuition-library-dogadgetmethoda.md) for V37 machines
       LibDoGadgetMethod -- Varargs stub for LibDoGadgetMethodA
```
   SYNOPSIS


```c
       result = LibDoGadgetMethodA( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md), [Message](autodocs-3.5/include-exec-ports-h.md) )
       D0                  A0      A1      A2         A3

       ULONG LibDoGadgetMethodA( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [Msg](autodocs-3.5/include-intuition-classusr-h.md) );

       result = LibDoGadgetMethod( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md), MethodID, ...)

       ULONG LibDoGadgetMethod( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, ... );
```
   FUNCTION

```c
       Same as the DoGadgetMethod() function of intuition.library V39,
       this function invokes a BOOPSI method and provides context
       information for classes which implement custom Intuition gadgets.

       You should use this function for boopsi gadget objects,
       or for "models" which propagate information to gadgets.

       Unlike [DoMethod()](autodocs-3.5/amiga-lib-domethod-2.md), this function provides a [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) pointer
       (if possible) when invoking the method.  Some classes may
       require or benefit from this.

       On a V39 machine, this function calls the Intuition function.
```
   INPUTS

```c
       [Gadget](autodocs-3.5/include-intuition-intuition-h.md) = abstract pointer to a boopsi gadget
       [Window](autodocs-3.5/include-intuition-intuition-h.md) = window gadget has been added to using [AddGList()](autodocs-3.5/intuition-library-addglist-2.md) or [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md)
       [Requester](autodocs-3.5/include-intuition-intuition-h.md) = for REQGADGETs, requester containing the gadget
       [Msg](autodocs-3.5/include-intuition-classusr-h.md) = the boopsi message to send
```
   RESULT

       The object does whatever it wants with the message you sent,
       which might include updating its gadget visuals.

       The return value is defined per-method.
   NOTES

```c
       This function invokes the specified method with a [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md)
       derived from the 'Window' and 'Requester' pointers.  The [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md)
       is passed as the second parameter of the message, except for
       OM_NEW, OM_SET, OM_NOTIFY, and OM_UPDATE, where the [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md)
       is passed as the third parameter.

       Implementers of new gadget methods should ensure that the
       [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) is the second long-word of their message!
```
   SEE ALSO

```c
       [NewObject()](autodocs-3.5/intuition-library-newobject-2.md), [DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
       Document "Basic Object-Oriented Programming System for Intuition"
       and the "boopsi Class Reference" document.
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
