# B / icclass / Attributes: ICA_TARGET (IS)


This attribute stores the address of the [icclass](../Libraries_Manual_guide/node04C6.html) object's target object.
Whenever the icclass object receives an [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) or [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) message, it
forwards that message to its target in the form of an OM_UPDATE message.
If the icclass object has an attribute mapping list (see the [ICA_MAP](../Libraries_Manual_guide/node04CA.html)
attribute below), it also maps the [OM_NOTIFY/OM_UPDATE](../Libraries_Manual_guide/node04C8.html) message's attribute
IDs to new ones before forwarding the message.

If the value of ICA_TARGET is ICTARGET_IDCMP, the [icclass](../Libraries_Manual_guide/node04C6.html) object sends an
[IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) [IntuiMessage](../Libraries_Manual_guide/node01D9.html) to its window instead of forwarding an
OM_UPDATE message.  See the [rootclass](../Libraries_Manual_guide/node04BB.html) description of [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) for more
information.

