# B / gadgetclass / Attributes: ICA_TARGET (IS)


This attribute stores the address of the gadget's target object.  Whenever
the gadget receives an [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) message, it sends an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) message to
its target.  If the gadget has an attribute mapping list (see the [ICA_MAP](../Libraries_Manual_guide/node04FC.html)
attribute below), it also maps the IDs from the OM_NOTIFY message.

If the value of ICA_TARGET is ICTARGET_IDCMP, the gadget sends an
[IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) [IntuiMessage](../Libraries_Manual_guide/node01D9.html) to its window.  See the [rootclass](../Libraries_Manual_guide/node04BB.html)
description of [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) for more information.

