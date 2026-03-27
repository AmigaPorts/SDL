# B / modelclass / Changed Methods: OM_NOTIFY/OM_UPDATE


This method tells an object to forward the message in the form of an
OM_UPDATE message to all the objects in its broadcast list.  The
[modelclass](../Libraries_Manual_guide/node04CC.html) does not map the attributes in these OM_UPDATE messages.
Because modelclass inherits behavior from [icclass](../Libraries_Manual_guide/node04C6.html), if the model has an
[ICA_TARGET](../Libraries_Manual_guide/node04C9.html) and [ICA_MAP](../Libraries_Manual_guide/node04CA.html), it will also send a mapped OM_UPDATE message to
its ICA_TARGET.  The return values for these methods are not explicitly
defined.  See the [rootclass](../Libraries_Manual_guide/node04BB.html) [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html)/[OM_UPDATE](../Libraries_Manual_guide/node04C4.html) and icclass
[OM_NOTIFY/OM_UPDATE](../Libraries_Manual_guide/node04C8.html) descriptions for more information.

