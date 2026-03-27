# 12 / / Writing The Dispatcher / OM_SET/OM_UPDATE


For the [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message, the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher steps through the
attribute/value pairs passed to it in the OM_SET message looking for the
local attributes (see [OM_NEW](../Libraries_Manual_guide/node0212.html) for the OM_SET message structure).  The
[RKMMOD_Limit](../Libraries_Manual_guide/node0210.html) attribute is easy to process.  Just find it and record the
value in the local [RKMModData](../Libraries_Manual_guide/node0210.html#line18).vallimit field.

Because the function of the [rkmmodelclass](../Libraries_Manual_guide/node020F.html)'s [OM_SET](../Libraries_Manual_guide/node0211.html#line28) and [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) methods
are almost identical, the rkmmodelclass dispatcher handles them as the
same case.  The only difference is that, because the OM_UPDATE message
comes from another Boopsi object, the OM_UPDATE method can report on
transitory state changes of an attribute.  For example, when the user
slides a Boopsi prop gadget, that prop gadget sends out an interim
OM_UPDATE message for every interim value of [PGA_Top](../Libraries_Manual_guide/node050F.html).  When the user lets
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
[OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message because the OM_UPDATE message has an extra field on it
for flags.  If the low order bit (the OPUF_INTERIM bit) is set, this is an
interim OM_UPDATE message.  The interim flag is useful to a class that
wants to ignore any transitory messages, processing only final attribute
values.  Because [rkmmodelclass](../Libraries_Manual_guide/node020F.html) wants to process all changes to its
attributes, it processes all OM_UPDATE messages.

The [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html) attribute is a little more complicated to process. The
dispatcher has to make sure the new current value is within the limits set
by [RKMMOD_Limit](../Libraries_Manual_guide/node0210.html), then record that new value in the local
[RKMModData](../Libraries_Manual_guide/node0210.html#line18).currval field.  Because other objects need to hear about
changes to RKMMOD_CurrVal,  the dispatcher has to send a notification
request.  It does this by sending itself an [OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) message.  The
OM_NOTIFY message tells an object to notify its targets (its [ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20)
and the objects in its broadcast list) about an attribute change.  The
OM_NOTIFY method does this by sending [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) messages to all of an
object's targets.

The [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher does not handle the [OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) message itself.
It inherits this method from [modelclass](../Libraries_Manual_guide/node020D.html#line13), so the rkmmodelclass dispatcher
passes OM_NOTIFY messages on to its superclass. To notify its targets, the
rkmmodelclass dispatcher has to construct an OM_NOTIFY message.  The
OM_NOTIFY method uses the same message structure as [OM_UPDATE.](../Libraries_Manual_guide/node0211.html#line32)  Using the
stack-based version of [DoSuperMethodA()](../Libraries_Manual_guide/node0212.html#line27), [DoSuperMethod()](../Includes_and_Autodocs_2._guide/node0158.html), the dispatcher
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
Because the [OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) needs a tag list of attributes about which to issue
updates, the dispatcher builds a tag list containing just the
[RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html) tag and its new value.  The dispatcher doesn't use the tag
list passed to it in the [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32)/OM_NOTIFY message because that list can
contain many other attributes besides RKMMOD_CurrVal.

The msg variable in the [DoSuperMethod()](../Includes_and_Autodocs_2._guide/node0158.html) call above is the [OM_SET](../Libraries_Manual_guide/node0211.html#line28) or
[OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message that was passed to the dispatcher.  The dispatcher uses
that structure to find a pointer to the [GadgetInfo](../Libraries_Manual_guide/node0219.html#line23) structure that the
[OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) message requires.  The GadgetInfo structure comes from Intuition
and contains information that Boopsi gadgets need to render themselves.
For the moment, don't worry about what the GadgetInfo structure actually
does, just pass it on.  The targets of an rkmmodel will probably need it.

Notice that the dispatcher has to test to see if the message is an [OM_SET](../Libraries_Manual_guide/node0211.html#line28)
or [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) so it can account for the opu_Flags field at the end of the
OM_UPDATE message.

Processing the [RKMMOD_Up](../Libraries_Manual_guide/node0210.html#line8) and [RKMMOD_Down](../Libraries_Manual_guide/node0210.html#line8) attributes is similar to the
[RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html) attribute.  When the dispatcher sees one of these, it has
to increment or decrement the local [RKMModData](../Libraries_Manual_guide/node0210.html#line18).currval, making sure
RKMModData.currval is within limits.  The dispatcher then sends an
[OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) message to the superclass about the change to RKMModData.currval.

The return value from the dispatcher's [OM_SET](../Libraries_Manual_guide/node0211.html#line28) method depends on the what
effect the attribute change has to the visual state of the objects in the
rkmmodel's broadcast list.  If an attribute change will not affect the
visual state of the rkmmodel's objects, the OM_SET method returns zero.
If the attribute change could trigger a change to the rkmmodel's objects,
it returns something besides zero. For example, the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) OM_SET
method returns 1L if an rkmmodel's [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html), [RKMMOD_Up](../Libraries_Manual_guide/node0210.html#line8), or
[RKMMOD_Down](../Libraries_Manual_guide/node0210.html#line8) attribute is changed.

At some point the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher has to allow its superclasses
to process these attributes it inherits.  Normally a dispatcher lets the
superclass process its attributes before attempting to process any local
attributes.  The rkmmodelclass dispatcher does this by passing on the
[OM_SET](../Libraries_Manual_guide/node0211.html#line28) or [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message using [DoSuperMethodA()](../Libraries_Manual_guide/node0212.html#line27) (inheritance at work!).
As an alternative, the dispatcher can use the amiga.lib function
[SetSuperAttrs()](../Includes_and_Autodocs_2._guide/node0166.html).  See the [amiga.lib](../Includes_and_Autodocs_2._guide/node0139.html) Autodocs for more details on this
function.

