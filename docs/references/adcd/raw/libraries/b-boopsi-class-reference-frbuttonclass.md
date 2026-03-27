# B Boopsi Class Reference / frbuttonclass


Class:                  frbuttonclass
Superclass:             [buttongclass](../Libraries_Manual_guide/node051F.html)
Include File:           <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html)>

This is a special class of button gadget that puts a Boopsi framing image
around some other display element.  This display element can be one of
three things: plain text from the [GA_Text](../Libraries_Manual_guide/node04FF.html) attribute, an [IntuiText](../Libraries_Manual_guide/node01C7.html) from the
[GA_IntuiText](../Libraries_Manual_guide/node04FF.html) attribute, or an Image from the [GA_LabelImage](../Libraries_Manual_guide/node04FF.html) attribute.

The user activates the gadget by clicking within the bounds of the
gadget's framing image, which it gets from the [GA_Image](../Libraries_Manual_guide/node0500.html) attribute.
Usually the framing image is an instance of an image class that supports
the IM_FRAMEBOX method (like [frameiclass](../Libraries_Manual_guide/node04DF.html)).  If the framing image supports
the IM_FRAMEBOX method, the frbuttonclass object centers the frame image
around the display element.  See the [imageclass](../Libraries_Manual_guide/node04D1.html) description of [IM_FRAMEBOX](../Libraries_Manual_guide/node04D8.html)
for more information.

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_NEW](../Libraries_Manual_guide/node0525.html)    [GM_HITTEST](../Libraries_Manual_guide/node0526.html)    [GM_RENDER](../Libraries_Manual_guide/node0527.html) 

Attributes:
-----------
 [GA_Width, GA_Height (S)](../Libraries_Manual_guide/node0528.html) 
 [GA_DrawInfo (I)](../Libraries_Manual_guide/node0529.html) 
 [GA_Text, GA_IntuiText, GA_LabelImage (IS)](../Libraries_Manual_guide/node052A.html) 

