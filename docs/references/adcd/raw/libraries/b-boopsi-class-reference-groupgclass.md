# B Boopsi Class Reference / groupgclass


Class:                  groupgclass
Superclass:             [gadgetclass](../Libraries_Manual_guide/node04F2.html)
Include File:           <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html)>

This is a class of objects that maintains an internal list of gadgets.
Its purpose is to make it easier to layout a group of gadgets.  Any
gadgets that are a member of a groupgclass object are rendered relative to
the groupgclass object's GA_Left and GA_Top attributes.  As new gadgets
are added to the groupgclass object, the groupgclass object's dimensions
grow to enclose the new gadgets.  When the groupgclass object receives an
[OM_DISPOSE](../Libraries_Manual_guide/node04BD.html) message, it not only disposes of itself, it also disposes of
all the gadgets in its list.  Groupgclass does not support the gadget
relative flags ([GA_RelWidth, GA_RelHeight, GA_RelBottom, and GA_RelRight](../Libraries_Manual_guide/node04FE.html)).

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_SET](../Libraries_Manual_guide/node052C.html)          [GM_HITTEST](../Libraries_Manual_guide/node0530.html) 
 [OM_ADDMEMBER](../Libraries_Manual_guide/node052D.html)    [GM_RENDER](../Libraries_Manual_guide/node0531.html) 
 [OM_REMMEMBER](../Libraries_Manual_guide/node052E.html)    [GM_GOACTIVE/GM_GOINACTIVE/GM_HANDLEINPUT](../Libraries_Manual_guide/node0532.html) 
 [OM_DISPOSE](../Libraries_Manual_guide/node052F.html) 

Attributes:
-----------
 [GA_Left, GA_Top (IS)](../Libraries_Manual_guide/node0533.html) 

