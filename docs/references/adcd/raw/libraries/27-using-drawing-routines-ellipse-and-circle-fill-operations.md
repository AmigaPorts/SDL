# 27 / / Using Drawing Routines / Ellipse and Circle-fill Operations


Two functions are associated with drawing filled ellipses: [AreaCircle()](../Includes_and_Autodocs_2._guide/node0416.html)
and [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html). AreaCircle()  (a macro that calls AreaEllipse()) will
draw a circle from the specified center point using the specified radius.
This function is executed by the statement:


```c
    AreaCircle(&rastPort, center_x, center_y, radius);
```
Similarly, [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html) draws a filled ellipse with the specified radii
from the specified center point:


```c
    AreaEllipse(&rastPort, center_x, center_y, horiz_r, vert_r);
```
Outlining with [SetOPen()](../Includes_and_Autodocs_2._guide/node047A.html) is not currently supported by the [AreaCircle()](../Includes_and_Autodocs_2._guide/node0416.html)
and [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html) routines.


```c
    Caution:
    --------
    If you attempt to fill an area outside the bounds of the [BitMap](../Libraries_Manual_guide/node032B.html#line74),
    using the basic initialized [RastPort](../Libraries_Manual_guide/node034A.html), it may crash the system. You
    must either do your own software clipping to assure that the area is
    in range, or use the layers library.
```
