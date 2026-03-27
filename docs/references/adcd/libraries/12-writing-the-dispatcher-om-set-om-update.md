---
title: 12 / / Writing The Dispatcher / OM_SET/OM_UPDATE
manual: libraries
chapter: libraries
section: 12-writing-the-dispatcher-om-set-om-update
functions: []
libraries: []
---

# 12 / / Writing The Dispatcher / OM_SET/OM_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For the [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher steps through the
attribute/value pairs passed to it in the OM_SET message looking for the
local attributes (see [OM_NEW](libraries/12-writing-the-dispatcher-om-new.md) for the OM_SET message structure).  The
[RKMMOD_Limit](libraries/12-building-on-existing-public-classes-building.md) attribute is easy to process.  Just find it and record the
value in the local [RKMModData](libraries/12-building-on-existing-public-classes-building.md).vallimit field.

Because the function of the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md)'s [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) and [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) methods
are almost identical, the rkmmodelclass dispatcher handles them as the
same case.  The only difference is that, because the OM_UPDATE message
comes from another Boopsi object, the OM_UPDATE method can report on
transitory state changes of an attribute.  For example, when the user
slides a Boopsi prop gadget, that prop gadget sends out an interim
OM_UPDATE message for every interim value of [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md).  When the user lets
go of the prop gadget, the gadget sends out a final OM_UPDATE message.
The OM_UPDATE message is almost identical to the OM_SET message:


```c
    #define OPUF_INTERIM    (1<<0)

    /* the OM_NOTIFY method uses the same structure */

    struct opUpdate {
        ULONG             MethodID;
        struct TagItem    *opu_AttrList;
        struct GadgetInfo *opu_GInfo;
        ULONG             opu_Flags;      /* The extra field */
    };
```
A dispatcher can tell the difference between an interim and final
[OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message because the OM_UPDATE message has an extra field on it
for flags.  If the low order bit (the OPUF_INTERIM bit) is set, this is an
interim OM_UPDATE message.  The interim flag is useful to a class that
wants to ignore any transitory messages, processing only final attribute
values.  Because [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) wants to process all changes to its
attributes, it processes all OM_UPDATE messages.

The [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) attribute is a little more complicated to process. The
dispatcher has to make sure the new current value is within the limits set
by [RKMMOD_Limit](libraries/12-building-on-existing-public-classes-building.md), then record that new value in the local
[RKMModData](libraries/12-building-on-existing-public-classes-building.md).currval field.  Because other objects need to hear about
changes to RKMMOD_CurrVal,  the dispatcher has to send a notification
request.  It does this by sending itself an [OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message.  The
OM_NOTIFY message tells an object to notify its targets (its [ICA_TARGET](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md)
and the objects in its broadcast list) about an attribute change.  The
OM_NOTIFY method does this by sending [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) messages to all of an
object's targets.

The [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher does not handle the [OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message itself.
It inherits this method from [modelclass](libraries/12-oop-overview-the-interconnection-classes.md), so the rkmmodelclass dispatcher
passes OM_NOTIFY messages on to its superclass. To notify its targets, the
rkmmodelclass dispatcher has to construct an OM_NOTIFY message.  The
OM_NOTIFY method uses the same message structure as [OM_UPDATE.](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)  Using the
stack-based version of [DoSuperMethodA()](libraries/12-writing-the-dispatcher-om-new.md), [DoSuperMethod()](autodocs-2.0/amiga-lib-dosupermethod.md), the dispatcher
can build an OM_NOTIFY message on the stack:


```c
     . . .

    struct TagItem tt[2];
    struct opUpdate *msg;
     . . .

    tt[0].ti_Tag  = RKMMOD_CurrVal;  /* make a tag list.  */
    tt[0].ti_Data = mmd->currval;
    tt[1].ti_Tag  = TAG_END;

    DoSuperMethod(cl, o, OM_NOTIFY, tt, msg->opu__GInfo,
                  ((msg->MethodID == OM_UPDATE) ? (msg->opu_Flags) : 0L));
     . . .
```
Because the [OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) needs a tag list of attributes about which to issue
updates, the dispatcher builds a tag list containing just the
[RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) tag and its new value.  The dispatcher doesn't use the tag
list passed to it in the [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)/OM_NOTIFY message because that list can
contain many other attributes besides RKMMOD_CurrVal.

The msg variable in the [DoSuperMethod()](autodocs-2.0/amiga-lib-dosupermethod.md) call above is the [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) or
[OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message that was passed to the dispatcher.  The dispatcher uses
that structure to find a pointer to the [GadgetInfo](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) structure that the
[OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message requires.  The GadgetInfo structure comes from Intuition
and contains information that Boopsi gadgets need to render themselves.
For the moment, don't worry about what the GadgetInfo structure actually
does, just pass it on.  The targets of an rkmmodel will probably need it.

Notice that the dispatcher has to test to see if the message is an [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
or [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) so it can account for the opu_Flags field at the end of the
OM_UPDATE message.

Processing the [RKMMOD_Up](libraries/12-building-on-existing-public-classes-building.md) and [RKMMOD_Down](libraries/12-building-on-existing-public-classes-building.md) attributes is similar to the
[RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) attribute.  When the dispatcher sees one of these, it has
to increment or decrement the local [RKMModData](libraries/12-building-on-existing-public-classes-building.md).currval, making sure
RKMModData.currval is within limits.  The dispatcher then sends an
[OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message to the superclass about the change to RKMModData.currval.

The return value from the dispatcher's [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method depends on the what
effect the attribute change has to the visual state of the objects in the
rkmmodel's broadcast list.  If an attribute change will not affect the
visual state of the rkmmodel's objects, the OM_SET method returns zero.
If the attribute change could trigger a change to the rkmmodel's objects,
it returns something besides zero. For example, the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) OM_SET
method returns 1L if an rkmmodel's [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md), [RKMMOD_Up](libraries/12-building-on-existing-public-classes-building.md), or
[RKMMOD_Down](libraries/12-building-on-existing-public-classes-building.md) attribute is changed.

At some point the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher has to allow its superclasses
to process these attributes it inherits.  Normally a dispatcher lets the
superclass process its attributes before attempting to process any local
attributes.  The rkmmodelclass dispatcher does this by passing on the
[OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) or [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message using [DoSuperMethodA()](libraries/12-writing-the-dispatcher-om-new.md) (inheritance at work!).
As an alternative, the dispatcher can use the amiga.lib function
[SetSuperAttrs()](autodocs-2.0/amiga-lib-setsuperattrs.md).  See the [amiga.lib](autodocs-2.0/amiga-lib-doc.md) Autodocs for more details on this
function.

