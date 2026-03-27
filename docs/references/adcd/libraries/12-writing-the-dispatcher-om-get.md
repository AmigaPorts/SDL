---
title: 12 / / Writing The Dispatcher / OM_GET
manual: libraries
chapter: libraries
section: 12-writing-the-dispatcher-om-get
functions: []
libraries: []
---

# 12 / / Writing The Dispatcher / OM_GET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The rkmmodel only has one "gettable" attribute: [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md), which
makes processing it easy.  The [OM_GET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message looks like this (defined in
<intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opGet {
        ULONG MethodID;     /* OM_GET */
        ULONG opg_AttrID;   /* The attribute to retrieve */
        ULONG *opg_Storage; /* a place to put the attribute's value */
    };
```
When the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher receives an [OM_GET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message with an
opg_AttrID equal to [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md), it copies the current value
([RKMModData](libraries/12-building-on-existing-public-classes-building.md)).currval to the memory location opg_Storage points to and
returns a value of TRUE.  The TRUE indicates that there was no error.  If
opg_AttrID is not RKMMOD_CurrVal, the dispatcher should let its superclass
handle this message.

The [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher can take advantage of the fact that the only
"gettable" attribute available to an rkmmodel is [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) (the
attributes defined by [modelclass](libraries/12-oop-overview-the-interconnection-classes.md) and [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) are not gettable--see the
Boopsi Class Reference in the [Appendix B](libraries/b-boopsi-class-reference.md) of this manual for more details
on which attributes are "settable", "gettable", etc.).  If opg_AttrID is
not RKMMOD_CurrVal, the rkmmodelclass dispatcher can return FALSE,
indicating that the attribute was not "gettable".

If the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher comes across any other messages besides
[OM_NEW](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md), [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md), [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md), and [OM_GET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, it blindly passes them on
to its superclass for processing.

