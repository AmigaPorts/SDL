# B / gadgetclass / Attributes: GA_Previous (I)


This attribute is used to insert a new gadget into a list of gadgets
linked by their [Gadget.NextGadget](../Libraries_Manual_guide/node0149.html#line21) field.  When the [OM_NEW](../Libraries_Manual_guide/node04F8.html) method creates
the new gadget, it inserts the new gadget into the list following the
GA_Previous gadget.  This attribute is a pointer to the gadget  (struct
Gadget *) that the new gadget will follow.  This attribute cannot be used
to link new gadgets into the gadget list of an open window or requester,
use [AddGList()](../Libraries_Manual_guide/node0133.html#line7) instead.

