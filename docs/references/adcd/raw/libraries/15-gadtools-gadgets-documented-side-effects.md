# 15 / GadTools Gadgets / Documented Side-Effects


There are certain aspects of the behavior of GadTools gadgets that should
not be depended on. This will help current applications remain compatible
with future releases of the GadTools library.

When using [GT_FilterIMsg()](../Libraries_Manual_guide/node0271.html) and [GT_PostFilterIMsg()](../Libraries_Manual_guide/node0271.html), never make assumptions
about the message before or after filtering.  I.e., do not interpret the
unfiltered message, assume that it will or will not result in certain
kinds of filtered message or assume it will result in a consumed message
(i.e., when GT_FilterIMsg() returns NULL).

[IDCMP_INTUITICKS](../Libraries_Manual_guide/node01E1.html#line80) messages are consumed when a scroller's arrows are
repeating.  That is, IDCMP_INTUITICKS will not be received while the user
is pressing a scroller arrows.  Do not depend or rely on this side effect,
though, it will not necessarily remain so in the future.

A single call to [CreateGadget()](../Libraries_Manual_guide/node025A.html) may create one or more actual gadgets.
These gadgets, along with the corresponding code in GadTools, define the
behavior of the particular kind of GadTools gadget requested.  Only the
behavior of these gadgets is documented, the number or type of actual
gadgets is subject to change.  Always refer to the gadget pointer received
from CreateGadget() when calling [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html).  Never refer to
other gadgets created by GadTools, nor create code which depends on their
number or form.

For text-display gadgets, the [GTTX_CopyText](../Libraries_Manual_guide/node0269.html#line24) tag does not cause the text to
be copied when the text is later changed with [GTTX_Text](../Libraries_Manual_guide/node0269.html#line16).

The PLACETEXT [ng_Flags](../Libraries_Manual_guide/node0259.html#line38) are currently ignored by [GENERIC_KIND](../Libraries_Manual_guide/node026A.html) gadgets.
However, this may not always be so.

All GadTools gadgets set GADTOOL_TYPE in the gadget's [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field.
Do not use this flag to identify GadTools gadgets, as this flag is not
guaranteed to be set in the future.

The palette gadget subdivides its total area into the individual color
squares. Do not assume that the subdivision algorithm won't change.

