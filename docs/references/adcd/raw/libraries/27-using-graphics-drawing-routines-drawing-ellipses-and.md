# 27 / / Using Graphics Drawing Routines / Drawing Ellipses and Circles


Two functions are associated with drawing ellipses: [DrawCircle()](../Includes_and_Autodocs_2._guide/node00B6.html#line42) and
[DrawEllipse()](../Includes_and_Autodocs_2._guide/node0437.html). DrawCircle(), a macro that calls DrawEllipse(), will draw a
circle from the specified center point using the specified radius.  This
function is executed by the statement:


```c
    DrawCircle(&rastPort, center_x, center_y, radius);
```
Similarly, [DrawEllipse()](../Includes_and_Autodocs_2._guide/node0437.html) draws an ellipse with the specified radii from
the specified center point:


```c
    DrawEllipse(&rastPort, center_x, center_y, horiz_r, vert_r);
```
Neither function performs clipping on a non-layered [RastPort](../Libraries_Manual_guide/node034A.html).

