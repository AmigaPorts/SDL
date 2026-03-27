# B / propgclass / Changed Methods: GM_HANDLEINPUT


If the knob position changes sufficiently to change a [propgclass](../Libraries_Manual_guide/node0507.html) object's
[PGA_Top](../Libraries_Manual_guide/node050F.html) attribute, the gadget will send an [OM_NOTIFY](../Libraries_Manual_guide/node04F9.html) message to itself,
which the propgclass dispatcher passes on to the [gadgetclass](../Libraries_Manual_guide/node04F2.html) dispatcher
for processing (see the [rootclass](../Libraries_Manual_guide/node04BB.html) description of [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) and [OM_UPDATE](../Libraries_Manual_guide/node04C4.html)
for more information).

The [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) message will contain two attribute/value pairs, [PGA_Top](../Libraries_Manual_guide/node050F.html) and
GA_ID.  While the prop gadget's PGA_Top is in a transitory state (while it
is active and the user is moving the prop gadget's knob), the gadget sends
interim [OM_NOTIFY](../Libraries_Manual_guide/node04F9.html) messages.  The interim OM_NOTIFY messages have the
OPUF_INTERIM flag of the [opUpdate.opu_Flags](../Libraries_Manual_guide/node04C4.html#line26) field set.  When the user
finishes manipulating the gadget (by letting go of the knob), the gadget
sends a final OM_NOTIFY message, which has a cleared OPUF_INTERIM flag.

