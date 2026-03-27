# 5 / / Initialization of Proportional Gadget / of the Gadget Structure


In the [Gadget](../Libraries_Manual_guide/node0149.html) structure, set the [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field to [GTYP_PROPGADGET](../Libraries_Manual_guide/node0149.html#line71) and
place the address of the [PropInfo](../Libraries_Manual_guide/node0161.html) structure in the [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125) field.

When using [AUTOKNOB](../Libraries_Manual_guide/node0161.html#line23), the [GadgetRender](../Libraries_Manual_guide/node0149.html#line91) field must point to an [Image](../Libraries_Manual_guide/node01BA.html)
structure. The Image need not be initialized when using AUTOKNOB, but the
structure must be provided. These Image structures may not be shared
between gadgets, each must have its own.

To use application imagery for the [knob](../Libraries_Manual_guide/node015A.html), set [GadgetRender](../Libraries_Manual_guide/node0149.html#line91) to point to an
initialized [Image](../Libraries_Manual_guide/node01BA.html) structure. If the knob highlighting is done by alternate
image ([GFLG_GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16)), the alternate image must be the same size and
type as the normal knob image.

