# B Boopsi Class Reference / buttongclass


Class:                  buttongclass
Superclass:             [gadgetclass](../Libraries_Manual_guide/node04F2.html)
Include File:           <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html)>

A class of button gadget that continually sends interim [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) messages
to its target while the user holds down the button.  The button sends a
final OM_UPDATE message when the user lets  go of the button.  The imagery
for these objects is not built directly into the gadget.  Instead, a
buttongclass object uses a Boopsi image object, which it gets from its
GA_Image attribute.

New Methods:
------------
None.

Changed Methods:
----------------
 [GM_HITTEST](../Libraries_Manual_guide/node0520.html)    [GM_HANDLEINPUT](../Libraries_Manual_guide/node0521.html)    [GM_RENDER](../Libraries_Manual_guide/node0522.html) 

Attributes:
-----------
 [GA_IMAGE (IS)](../Libraries_Manual_guide/node0523.html) 

