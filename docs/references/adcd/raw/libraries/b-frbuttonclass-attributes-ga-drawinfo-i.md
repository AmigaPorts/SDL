# B / frbuttonclass / Attributes: GA_DrawInfo (I)


This attribute passes a pointer to a valid [DrawInfo](../Libraries_Manual_guide/node04BD.html#line6) structure.  If the
[frbuttonclass](../Libraries_Manual_guide/node0524.html) gadget is going to frame plain text (passed to it in the
[GA_Text](../Libraries_Manual_guide/node04FF.html) attribute), the frbuttonclass gadget requires a DrawInfo structure
to properly calculate the dimensions of the text.

