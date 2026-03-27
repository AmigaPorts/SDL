# B Boopsi Class Reference / rootclass


Class:                  rootclass
Superclass:             None
Include File:           <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html)>

This is the universal base class for all other classes.

New Methods:
------------
 [OM_NEW](../Libraries_Manual_guide/node04BC.html)        [OM_ADDTAIL](../Libraries_Manual_guide/node04BE.html) 
 [OM_DISPOSE](../Libraries_Manual_guide/node04BD.html)    [OM_REMOVE](../Libraries_Manual_guide/node04BF.html) 

The following methods are described at the rootclass level although its up
to the subclasses to actually implement them.  If a class does not
implement these methods, it should either return zero, indicating that
this class does not support the method, or defer processing on to its
superclass.

 [OM_ADDMEMBER](../Libraries_Manual_guide/node04C0.html)    [OM_GET](../Libraries_Manual_guide/node04C2.html)    [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) 
 [OM_REMMEMBER](../Libraries_Manual_guide/node04C1.html)    [OM_SET](../Libraries_Manual_guide/node04C3.html)    [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html) 

Changed Methods:
----------------
Not applicable.

Attributes:
-----------
None.

