# B / gadgetclass / Changed Methods: OM_NOTIFY


This method tells a gadget to send an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) message to its target
object.  Boopsi gadgets have a function similar to [icclass](../Libraries_Manual_guide/node04C6.html) objects--each
gadget can have an [ICA_TARGET](../Libraries_Manual_guide/node04FB.html) and [ICA_MAP](../Libraries_Manual_guide/node04FC.html) in order to notify some target
object of attribute changes.  When a Boopsi gadget sends an OM_NOTIFY
message, it always includes its GA_ID.  This makes it easy for an
application to tell which gadget initially sent the OM_NOTIFY.  See the
description of icclass's [OM_NOTIFY](../Libraries_Manual_guide/node04C8.html) and [OM_UPDATE](../Libraries_Manual_guide/node04C8.html) and the [rootclass](../Libraries_Manual_guide/node04BB.html)'s
[OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) and [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) methods for more details.

