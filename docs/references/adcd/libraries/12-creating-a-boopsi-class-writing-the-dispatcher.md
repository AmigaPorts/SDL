---
title: 12 / Creating a Boopsi Class / Writing the Dispatcher
manual: libraries
chapter: libraries
section: 12-creating-a-boopsi-class-writing-the-dispatcher
functions: []
libraries: []
---

# 12 / Creating a Boopsi Class / Writing the Dispatcher

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The C prototype for a Boopsi dispatcher looks like this:


```c
    ULONG dispatchRKMModel(Class *cl, Object *recvobject, Msg msg);
```
where cl points to the Class (defined in <intuition/[classes.h](autodocs-2.0/includes-intuition-classes-h.md)>) of the
dispatcher, recvobject points to the object that received the message, and
msg is that Boopsi message.  The format of the message varies according to
the method.  The default Boopsi message is an Msg (from
<intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    typedef struct {
        ULONG MethodID;
    } *Msg;
```
Boopsi methods that require parameters use custom message structures. The
first field of any message structure is always the method's methodID.
This makes custom messages look like an Msg.  The dispatcher looks at an
incoming message's first field to tell what its method is.  [Rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md)
objects respond to several [rootclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) methods:

[OM_NEW](libraries/b-rootclass-new-methods-om-new.md)

```c
    This method creates a new [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) object.  It uses an [opSet](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
    structure as its Boopsi message.
```
[OM_DISPOSE](libraries/b-rootclass-new-methods-om-dispose.md)

    This method tells an object to dispose of itself.  It uses an Msg as
    its Boopsi message.
[OM_SET](libraries/b-rootclass-new-methods-om-set.md)

```c
    This method tells an object to set one or more of its attribute
    values.  It uses an [opSet](libraries/12-boopsi-object-oriented-intuition-creating-a-boopsi-class.md) structure as its Boopsi message.
```
[OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)

```c
    This method tells an object to update one or more of its attribute
    values.  It uses an [opUpdate](libraries/12-writing-the-dispatcher-om-set-om-update.md) structure as its Boopsi message.
```
[OM_GET](libraries/b-rootclass-new-methods-om-get.md)

```c
    This method tells an object to report an attribute value.  It uses an
    [opGet](libraries/12-writing-the-dispatcher-om-get.md) structure as its Boopsi message.
```
[OM_ADDTAIL](libraries/b-rootclass-new-methods-om-addtail.md)

```c
    This method tells an object to add itself to the end of an Exec list.
    It uses an [opAddTail](autodocs-2.0/includes-intuition-classusr-h.md) structure as its Boopsi message.
```
[OM_REMOVE](libraries/b-rootclass-new-methods-om-remove.md)

    This method tells an object to remove itself from an Exec list.  It
    uses an Msg as its Boopsi message.
[OM_ADDMEMBER](libraries/b-rootclass-new-methods-om-addmember.md)

```c
    This method tells an object to add an object to its broadcast list.
    It uses an [opMember](libraries/12-oop-overview-the-interconnection-classes.md) structure as its Boopsi message.
```
[OM_REMMEMBER](libraries/b-rootclass-new-methods-om-remmember.md)

```c
    This method tells an object to remove an object from its broadcast
    list.  It uses an [opMember](libraries/12-oop-overview-the-interconnection-classes.md) structure as its Boopsi message.
```
[OM_NOTIFY](libraries/b-rootclass-new-methods-om-notify.md)

```c
    This method tells an object to broadcast an attribute change to its
    broadcast list.  It uses an [opSet](libraries/12-boopsi-object-oriented-intuition-creating-a-boopsi-class.md) structure as its Boopsi message.
```
Of these, [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) has to process OM_NEW, OM_SET, OM_UPDATE, and
OM_GET.

 [OM_NEW](libraries/12-writing-the-dispatcher-om-new.md)              [OM_GET](libraries/12-writing-the-dispatcher-om-get.md)                  [RKMModel.c](libraries/12-writing-the-dispatcher-rkmmodel-c.md) 
 [OM_SET/OM_UPDATE](libraries/12-writing-the-dispatcher-om-set-om-update.md)    [Making the New Class](libraries/12-writing-the-dispatcher-making-the-new-class.md) 

