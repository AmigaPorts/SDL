# 5 Intuition Gadgets / Gadget Size and Position


The position and dimensions of the gadget's select box are defined in the
[Gadget](../Libraries_Manual_guide/node0149.html) structure.  The [LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [TopEdge](../Libraries_Manual_guide/node0149.html#line33), [Width](../Libraries_Manual_guide/node0149.html#line33) and [Height](../Libraries_Manual_guide/node0149.html#line33) values can be
absolute numbers or values relative to the size of the window.  When using
absolute numbers, the values are set once, when the gadget is created.
When using relative numbers, the size and position of the select box are
adjusted dynamically every time the window size changes.

The gadget image is positioned relative to the select box so when the
select box moves the whole gadget moves.  The size of the gadget image,
however, is not usually affected by changes in the select box size
([proportional](../Libraries_Manual_guide/node0153.html) gadgets are the exception).  To create a gadget image that
changes size when the select box and window change size, you have to
handle gadget rendering yourself or use a BOOPSI gadget.

 [Select Box Position](../Libraries_Manual_guide/node013B.html)     [Positioning Gadgets in Window Borders](../Libraries_Manual_guide/node013D.html) 
 [Select Box Dimension](../Libraries_Manual_guide/node013C.html) 

