# 5 / Gadget Imagery / Line Drawn Gadgets


Gadget imagery can also be created by specifying a series of lines to be
drawn.  These lines can go around or through the select box of the gadget,
and can be drawn using any color pen and draw mode.  Multiple groups of
lines may be specified, each with its own pen and draw mode.

The [Border](../Libraries_Manual_guide/node01C1.html) structure is used to describe the lines to be drawn.  The
Border structure is incorporated into the gadget by clearing the
[GFLG_GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23) flag in the gadget's [Flags](../Libraries_Manual_guide/node0149.html#line48) field.  The address of the
Border structure is placed into the gadget's [GadgetRender](../Libraries_Manual_guide/node0149.html#line91) field.  The
border imagery will be positioned relative to the gadget's select box.
For more information about creating a Border structure, see the chapter
"[Intuition Images, Line Drawing, and Text](../Libraries_Manual_guide/node01C0.html)."

