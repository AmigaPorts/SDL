---
title: 12 / OOP Overview / The Interconnection Classes
manual: libraries
chapter: libraries
section: 12-oop-overview-the-interconnection-classes
functions: []
libraries: []
---

# 12 / OOP Overview / The Interconnection Classes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [IDCMP_IDCMPUPDATE](libraries/9-event-message-classes-and-flags-other-flags.md) scheme presents a problem to an application that
wants to make gadgets talk to each other and talk to the application.
Boopsi gadgets only have one [ICA_TARGET](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md).  One Boopsi gadget can talk to
either another Boopsi object or its window's IDCMP port, but not both.
Using this scheme alone would force the application to update the integer
value of the gadgets, which is what we are trying to avoid in the first
place.

One of the standard Boopsi classes, [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md), is a class of information
forwarders.  An icclass object receives [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) messages from one object
and passes those messages on to its own [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md).  If it needs to map
any incoming attributes, it can use its own [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md) to do so.

[Icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) has a subclass called [modelclass](libraries/b-boopsi-class-reference-modelclass.md).  Using a modelclass object, an
application can chain a series of these objects together to set up a
"broadcast list" of icclass objects.  The modelclass object is similar to
the icclass object in that it has its own [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) and [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md).  It
differs in that an application can use the modelclass [OM_ADDMEMBER](libraries/b-modelclass-changed-methods-om-addmember.md) method
to add icclass objects to the modelclass object's broadcast list.

The [OM_ADDMEMBER](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method is defined by [rootclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md).  It adds one Boopsi
object to the personal list of another Boopsi object.  It is up to the
Boopsi object's class to determine the purpose of the objects in the list.
Unlike the other methods mentioned so far in this chapter, OM_ADDMEMBER
does not have an Intuition function equivalent.  To pass an OM_ADDMEMBER
message to an object use the amiga.lib function [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), or its
stack-based equivalent, [DoMethod()](autodocs-2.0/amiga-lib-domethod.md):


```c
    ULONG DoMethodA(Object *myobject, Msg boopsimessage);
    ULONG DoMethod(Object *myobject, ULONG methodID, ...);
```
The return value is class-dependent.  The first argument to both of these
functions points to the object that will receive the Boopsi message.

For [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), boopsimessage is the actual Boopsi message.  The layout
of it depends on the method.  Every method's message starts off with an
Msg (from <intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    typedef struct {
        ULONG MethodID; /* Method-specific data may follow this field */
    } *Msg;
```
The message that the [OM_ADDMEMBER](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method uses looks like this (from
<intuition/[classusr.h](autodocs-2.0/includes-intuition-classusr-h.md)>):


```c
    struct opMember {
        ULONG    MethodID;
        Object   *opam_Object;
    };
```
where MethodID is [OM_ADDMEMBER](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) and opam_Object points to the object to add
to myobject's list.

[DoMethod()](autodocs-2.0/amiga-lib-domethod.md) uses the stack to build a message.  To use DoMethod(), just
pass the elements of the method's message structure as arguments to
DoMethod() in the order that they appear in the structure.  For example,
to ask the Boopsi object myobject to add the object addobject to its
personal list:


```c
    DoMethod(myobject, OM_ADDMEMBER, addobject);
```
To rearrange [Talk2boopsi.c](libraries/lib-examples-talk2boopsi-c.md) so that it uses a [modelclass](libraries/b-boopsi-class-reference-modelclass.md) object (also known
as a model):

  * Create the integer and prop gadget.

  * Create the model.

  * Create two [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) objects, one called int2prop and the other called

    prop2int.
  * Make the model the [ICA_TARGET](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md) of both the integer gadget and the prop

```c
    gadget.  The gadgets do not need an [ICA_MAP](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md).
```
  * Using [DoMethod()](autodocs-2.0/amiga-lib-domethod.md) to call [OM_ADDMEMBER](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md), add the [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) objects to the

    model's personal list.
  * Make the prop gadget the [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) of int2prop.  Make the integer

    gadget the ICA_TARGET of prop2int.
  * Create an [ICA_MAP](libraries/b-icclass-attributes-ica-map-is.md) map list for int2prop that maps [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md) to

```c
    [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md).  Create an ICA_MAP map list for prop2int that maps PGA_Top
    to STRINGA_LongVal.  Make the [ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md) of the model [ICTARGET_IDCMP](libraries/12-oop-overview-making-gadgets-talk-to-an-application.md).
```
Diagrammatically, the new [Talk2boopsi.c](libraries/lib-examples-talk2boopsi-c.md) should look something like this:


```c
     [Figure 12-4: ICC Diagram](libraries/lib-pics-12-4-pic.md) 
```
When either of these gadgets has some interim state change (caused by the
user manipulating the gadgets), it sends an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message to its
[ICA_TARGET](libraries/b-icclass-attributes-ica-target-is.md), which in this case is the [modelclass](libraries/b-boopsi-class-reference-modelclass.md) object.  When this model
gets the message, it does two things.  It sends an [IDCMP_IDCMPUPDATE](libraries/9-event-message-classes-and-flags-other-flags.md) to
the IDCMP port of the gadget's window and it also sends OM_UPDATE messages
to all of the objects in its personal list.  When int2prop gets an
OM_UPDATE message, it forwards that message to its ICA_TARGET, the prop
gadget.  Similarly, when prop2int gets an OM_UPDATE message, it forwards
that message to its ICA_TARGET, the integer gadget.

Although in this case it isn't a problem, [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) and [modelclass](libraries/b-boopsi-class-reference-modelclass.md) objects
contain loop inhibition capabilities.  If an icclass object (or modelclass
object) receives an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, it forwards the message to its
target.  If somehow that forwarded message gets forwarded (or broadcast)
back to the icclass object, the icclass object ignores the message.  This
prevents the possibility of an infinite OM_UPDATE loop.

