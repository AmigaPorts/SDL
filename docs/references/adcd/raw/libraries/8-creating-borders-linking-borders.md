# 8 / Creating Borders / Linking Borders


The [NextBorder](../Libraries_Manual_guide/node01C1.html#line41) field can point to another instance of a [Border](../Libraries_Manual_guide/node01C1.html) structure.
This allows complex graphic objects to be created by linking together
Border structures, each with its own data points, color and draw mode.
This might be used, for instance, to draw a double border around a
requester or gadget where the outer border is a second Border structure,
linked to the first inner border.

Note that the borders can share data.  For instance, to create a border
with a shadow, link two borders together each of which points to the same
[XY](../Libraries_Manual_guide/node01C1.html#line38) data.  Set the first border to draw in a dark pen (such as the
[SHADOWPEN](../Libraries_Manual_guide/node00EC.html#line79) from the screen's [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure) and position the border
down and to the right a few pixels by changing [LeftEdge](../Libraries_Manual_guide/node01C1.html#line15) and [TopEdge](../Libraries_Manual_guide/node01C1.html#line15) in the
[Border](../Libraries_Manual_guide/node01C1.html) structure.

The second border should be set to a bright pen (such as the [SHINEPEN](../Libraries_Manual_guide/node00EC.html#line76) in
the screen's [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure).  When the border is drawn, the first
border will draw in a dark color and then the second border will be drawn
over it in a light color.  Since they use the same data set, and the dark
border is shifted down and to the right, the border will have a three
dimensional appearance.  This technique is demonstrated in the [example](../Libraries_Manual_guide/node05AB.html)
listed earlier in this section.

