# B / frbuttonclass / Changed Methods: OM_NEW


When this class creates an object, it sets the object's embedded
[Gadget.Width](../Libraries_Manual_guide/node0149.html#line33) and [Gadget.Height](../Libraries_Manual_guide/node0149.html#line33) fields according to the frame image in
[GA_Image](../Libraries_Manual_guide/node0500.html).  If the GA_Image understands the [IM_FRAMEBOX](../Libraries_Manual_guide/node04D8.html) method, the gadget
asks the GA_Image what it dimensions would be if it had to surround the
display element.  If the GA_Image does not support IM_FRAMEBOX, it just
copies the GA_Image image's width and height into the [Gadget](../Libraries_Manual_guide/node0149.html) structure.

