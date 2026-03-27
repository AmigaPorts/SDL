# 7 / True Requesters / Gadgets in Requesters


Each requester gadget must have the [GTYP_REQGADGET](../Libraries_Manual_guide/node0149.html#line88) flag set in the
[GadgetType](../Libraries_Manual_guide/node0149.html#line58) field of its [Gadget](../Libraries_Manual_guide/node0149.html) structure.  This informs Intuition that
this gadget is to be rendered in a requester rather than a window.

Requesters can have gadgets in them that automatically satisfy the request
and end the requester.  When one of these gadgets is selected, Intuition
will remove the requester from the window.  This is equivalent to the
application calling [EndRequest()](../Libraries_Manual_guide/node01A2.html#line24), and, if the request is terminated by
selection of such a gadget, the application should not call EndRequest()
for that requester.

Set the [GACT_ENDGADGET](../Libraries_Manual_guide/node014B.html#line31) flag in the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the [Gadget](../Libraries_Manual_guide/node0149.html)
structure to create a gadget that automatically terminates the requester.
Every time one of the requester's gadgets is selected, Intuition examines
the GACT_ENDGADGET flag.  If GACT_ENDGADGET is set, the requester is
removed from the display and unlinked from the window's active requester
list.

Requesters rendered via Intuition and those that use a custom bitmap
differ in how their gadgets are rendered.  For requesters rendered via
Intuition, the application supplies a regular gadget list just as it would
for application gadgets in a window.

In custom bitmap requesters, however, any gadget imagery is part of the
bitmap supplied for the requester.  Therefore the list of gadgets supplied
for custom bitmap requesters should not provide gadget imagery but rather
it should define only the select boxes, highlighting, and gadget types for
the gadgets.

The [Gadget](../Libraries_Manual_guide/node0149.html) structures used with a custom bitmap requester should have
their [GadgetRender](../Libraries_Manual_guide/node0149.html#line91), [SelectRender](../Libraries_Manual_guide/node0149.html#line102) and [GadgetText](../Libraries_Manual_guide/node0149.html#line111) fields set to NULL as
these will be ignored.  Other gadget information--select box dimensions,
highlighting, and gadget type--is still relevant.  The select box
information is especially important since the select box must have a well
defined correspondence with the custom bitmap imagery supplied.  The basic
idea is to make sure that the user understands the requester imagery and
gadgets.

