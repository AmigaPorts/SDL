# 8 / Creating Borders / Border Coordinates


Intuition draws lines between points that are specified as sets of X, Y
coordinates.  [Border](../Libraries_Manual_guide/node01C1.html) data does not have to be in Chip memory.

The [XY](../Libraries_Manual_guide/node01C1.html#line38) field contains a pointer to an array of coordinate pairs.  All of
these coordinates are offsets relative to the [Border](../Libraries_Manual_guide/node01C1.html) position, which is
determined by the sum of the external and internal position components as
described above.  The coordinate pairs are ordered sequentially.  The
first two numbers make up the first coordinate pair, the next two numbers
make up the second pair, and so on.  Within a coordinate pair, the first
number is the X offset and the second number is the Y offset.

The first coordinate pair describes the starting point of the first line.
When the [Border](../Libraries_Manual_guide/node01C1.html) is rendered, a line is drawn between each pair of points.
The first line is drawn from point one to point two, the second line is
drawn from point two to point three, and so on, until the final point is
reached.

The numbers specified in the [XY](../Libraries_Manual_guide/node01C1.html#line38) array may be positive or negative.
Negative values move up and to the left relative to the [Border](../Libraries_Manual_guide/node01C1.html) position,
positive values move down and to the right. Again, the Border position is
determined by adding the external position component and the internal
position component.  For example, a Border attached to a [Gadget](../Libraries_Manual_guide/node0149.html) has an
external component equal to the upper left corner of the gadget's select
box.  The internal component is set within the Border structure itself.
These two components are added together and offsets from the resulting
position, specified within the XY array, determine where the lines of the
Border will appear.

Suppose the top left corner of the select box of the gadget is at window
position (10,5).  If the [Border](../Libraries_Manual_guide/node01C1.html) has [LeftEdge](../Libraries_Manual_guide/node01C1.html#line15) set to 10 and [TopEdge](../Libraries_Manual_guide/node01C1.html#line15) set to
10, then the Border is positioned at (10+10,5+10), that is (20,15).  All
[XY](../Libraries_Manual_guide/node01C1.html#line38) coordinates will be relative to this Border position.  If the XY array
contains `0,5, 15,5, 15,0', then the relative coordinates will be (0,5),
(15,5) and (15,0).  Adding each coordinate to the Border position gives
the absolute position of the lines within the window.  This Border will
draw two lines in the window, one from (20,20) to (35,20) and the second
from (35,20) to (35,15).




```c
          0    5   10   15   20   25   30   35   40   45   50
          |         |         |         |         |         |
       0__|____|____|____|____|____|____|____|____|____|____|
          |   Top left corner of the
          | gadget's select box (10,5)
       5 _|         * _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
          |
          |         |
      10__|                Border          Third
          |         |     Position       Coordinate
          |                (20,15)      (20+15,15+0)
      15 _|         |         *              *
          |                                  |
          |         |                        |
      20__|                   *______________*
          |         |       First          Second
          |              Coordinate      Coordinate
      25 _|         |    (20+0,15+5)    (20+15,15+5)
          |
          |         |
      30__|


             Figure 8-3: Example of Border Relative Position
```
To create a border that is outside the select box of a gadget, specify
negative values in the internal component or use negative values for the
initial [XY](../Libraries_Manual_guide/node01C1.html#line38) values.  For example, setting [LeftEdge](../Libraries_Manual_guide/node01C1.html#line15) to -1 and [TopEdge](../Libraries_Manual_guide/node01C1.html#line15) to -1
moves the position of the [Border](../Libraries_Manual_guide/node01C1.html) one pixel above and one pixel to the left
of the gadget's select box.

