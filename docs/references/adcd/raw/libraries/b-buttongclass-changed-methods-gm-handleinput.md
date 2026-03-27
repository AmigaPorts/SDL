# B / buttongclass / Changed Methods: GM_HANDLEINPUT


This method continuously issues [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) messages for each IECLASS_TIMER
event it gets.  The OM_NOTIFY message's OPUF_INTERIM flag (from
[opUpdate.opu_Flags](../Libraries_Manual_guide/node04C4.html#line26)) is set for all but the final OM_NOTIFY.

The [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) message contains one attribute/value pair, GA_ID.  If the
pointer is currently over the gadget image, the value of this
attribute/value pair is the gadget's actual GA_ID (from the
[Gadget.GadgetID](../Libraries_Manual_guide/node0149.html#line137) field).  If the pointer isn't over the image, the value is
the negative of the gadget's actual GA_ID.

