# 15 / / The Kinds of GadTools Gadgets / Generic Gadgets


If the application requires a specialized gadget which does not fit into
any of the defined GadTools kinds but would still like to use the GadTools
gadget creation and deletion functions, it may create a GadTools generic
gadget and use it any way it sees fit.  In fact, all of the kinds of
GadTools gadgets are created out of GadTools GENERIC_KIND gadgets.

The gadget that gets created will heed almost all the information
contained in the [NewGadget](../Libraries_Manual_guide/node0259.html) structure supplied.

If [ng_GadgetText](../Libraries_Manual_guide/node0259.html#line27) is supplied, the [Gadget](../Libraries_Manual_guide/node0149.html)'s [GadgetText](../Libraries_Manual_guide/node0149.html#line111) will point to an
[IntuiText](../Libraries_Manual_guide/node01C7.html) structure with the provided string and font.  However, do not
specify any of the PLACETEXT [ng_Flags](../Libraries_Manual_guide/node0259.html#line38), as they are currently ignored by
GENERIC_KIND gadgets.  PLACETEXT flags may be supported by generic
GadTools gadgets in the future.

It is up to the program to set the [Flags](../Libraries_Manual_guide/node0149.html#line48), [Activation](../Libraries_Manual_guide/node0149.html#line53), [GadgetRender](../Libraries_Manual_guide/node0149.html#line91),
[SelectRender](../Libraries_Manual_guide/node0149.html#line102), [MutualExclude](../Libraries_Manual_guide/node0149.html#line119) and [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125) fields of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.

The application must also set the [GadgetType](../Libraries_Manual_guide/node0149.html#line58) field, but be certain to
preserve the bits set by [CreateGadget()](../Libraries_Manual_guide/node025A.html). For instance, to make a gadget
boolean, use:


```c
    gad->GadgetType |= GTYP_BOOLGADGET;
```
and not


```c
    gad->GadgetType = GTYP_BOOLGADGET;
```
Using direct assignment, (the = operator), clears all other flags in the
[GadgetType](../Libraries_Manual_guide/node0149.html#line58) field and the gadget may not be properly freed by [FreeGadgets()](../Libraries_Manual_guide/node025D.html).

