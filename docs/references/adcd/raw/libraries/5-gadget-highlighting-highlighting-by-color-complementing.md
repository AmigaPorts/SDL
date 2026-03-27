# 5 / Gadget Highlighting / Highlighting by Color Complementing


Highlighting may be accomplished by complementing all of the colors in the
gadget's select box. In this context, complementing means the complement
of the binary number used to represent a particular color register.  For
example, if the color in color register 2 is used (binary 10) in a
specific pixel of the gadget, the complemented value of that pixel will be
the color in color register 1 (binary 01).

To use this highlighting method, set the [GFLG_GADGHCOMP](../Libraries_Manual_guide/node014A.html#line8) flag.

Only the select box of the gadget is complemented; any portion of the
text, image, or border which is outside of the select box is not
disturbed. See the chapter "[Intuition Images, Line Drawing, and Text](../Libraries_Manual_guide/node01BE.html)," for
more information about complementing and about color in general.

