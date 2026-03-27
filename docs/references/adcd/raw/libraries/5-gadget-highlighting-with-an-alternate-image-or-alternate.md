# 5 / Gadget Highlighting / With an Alternate Image or Alternate Border


An alternate image may be supplied as highlighting for gadgets that use
image rendering, similarly an alternate border may be supplied for gadgets
that use border rendering.  When the gadget is active or selected, the
alternate image or border is displayed in place of the default image or
border.  For this highlighting method, set the [SelectRender](../Libraries_Manual_guide/node0149.html#line102) field of the
[Gadget](../Libraries_Manual_guide/node0149.html) structure to point to the [Image](../Libraries_Manual_guide/node01BA.html) structure or [Border](../Libraries_Manual_guide/node01C1.html) structure for
the alternate display.

Specify that highlighting is to be done with alternate imagery by setting
the [GFLG_GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16) flag in the [Flags](../Libraries_Manual_guide/node0149.html#line48) field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.  When
using GFLG_GADGHIMAGE, remember to set the [GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag for images,
clear it for borders.

When using alternate images and borders for highlighting, gadgets rendered
with images must highlight with another image and gadgets rendered with
borders must highlight with another border.  For information about how to
create an [Image](../Libraries_Manual_guide/node01B9.html) or [Border](../Libraries_Manual_guide/node01C0.html) structure, see the chapter "Intuition Images,
Line Drawing, and Text."

