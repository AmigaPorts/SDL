# B Boopsi Class Reference / icclass


Class:                  icclass (interconnection class)
Superclass:             [rootclass](../Libraries_Manual_guide/node04BB.html)
Include File:           <intuition/[icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html)>

Base class of simple OM_UPDATE forwarding objects.  When an icclass object
gets an [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) message, it maps the attributes in the OM_UPDATE message
according to its mapping list (its [ICA_MAP](../Libraries_Manual_guide/node04CA.html) attribute) and forwards the
[OM_UPDATE](../Libraries_Manual_guide/node04C8.html) to its target (its [ICA_TARGET](../Libraries_Manual_guide/node04C9.html) attribute).

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_SET](../Libraries_Manual_guide/node04C7.html)    [OM_UPDATE/OM_NOTIFY](../Libraries_Manual_guide/node04C8.html) 

Attributes:
-----------
 [ICA_TARGET (IS)](../Libraries_Manual_guide/node04C9.html)    [ICA_MAP (IS)](../Libraries_Manual_guide/node04CA.html)    [ICSPECIAL_CODE (*)](../Libraries_Manual_guide/node04CB.html) 

