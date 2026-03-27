# B Boopsi Class Reference / imageclass


Class:                  imageclass
Superclass:             [rootclass](../Libraries_Manual_guide/node04BB.html)
Include File:           <intuition/[imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html)>

This class is the base class for Boopsi Images.  These images are
backwards compatible with the conventional Intuition Images.  Every Boopsi
image has an Intuition [Image](../Libraries_Manual_guide/node01BA.html) structure embedded in it so Intuition can
access the Boopsi image as a conventional Image structure when necessary.
Normally there are no direct instances of this class, only instances of
subclasses of imageclass.

New Methods:
------------
 [IM_DRAW](../Libraries_Manual_guide/node04D2.html)       [IM_ERASE](../Libraries_Manual_guide/node04D4.html)        [IM_HITFRAME](../Libraries_Manual_guide/node04D6.html)      [IM_FRAMEBOX](../Libraries_Manual_guide/node04D8.html) 
 [IM_HITTEST](../Libraries_Manual_guide/node04D3.html)    [IM_DRAWFRAME](../Libraries_Manual_guide/node04D5.html)    [IM_ERASEFRAME](../Libraries_Manual_guide/node04D7.html) 

Changed Methods:
----------------
 [OM_NEW](../Libraries_Manual_guide/node04D9.html)    [OM_SET](../Libraries_Manual_guide/node04DA.html) 

Attributes:
-----------
 [IA_Left, IA_Top, IA_Width, IA_Height (ISG)](../Libraries_Manual_guide/node04DB.html) 
 [IA_FGPen, IA_BGPen (ISG)](../Libraries_Manual_guide/node04DC.html) 
 [IA_Data (ISG)](../Libraries_Manual_guide/node04DD.html) 
 [IA_Pens ()](../Libraries_Manual_guide/node04DE.html) 

