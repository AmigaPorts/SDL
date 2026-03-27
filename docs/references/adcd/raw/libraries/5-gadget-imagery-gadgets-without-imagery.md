# 5 / Gadget Imagery / Gadgets Without Imagery


Gadgets can be created without any defining imagery.  This type of gadget
may be used where mouse information is required but graphical definition
of the gadget is not, or where the existing graphics sufficiently define
the gadget that no additional imagery is required.  A gadget with no
imagery may be created by clearing the [GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag in the gadget's
[Flags](../Libraries_Manual_guide/node0149.html#line48) field, and by setting the gadget's [GadgetRender](../Libraries_Manual_guide/node0149.html#line91) and [GadgetText](../Libraries_Manual_guide/node0149.html#line111)
fields to NULL.

The text display of a word processor is a case where mouse information is
required without any additional graphics.  If a large gadget is placed
over the text display, gadget and mouse event messages may be received at
the IDCMP ([Window.UserPort](../Libraries_Manual_guide/node01D6.html#line16)) when the mouse select button is either pressed
or released.  The mouse information is used to position the pointer in the
text, or to allow the user to mark blocks of text.  The drag bar of a
window is another example of a gadget where existing imagery defines the
gadget such that additional graphics are not required.

