# 27 / / / Drawing Multiple Lines with a Single Command


You can use multiple [Draw()](../Includes_and_Autodocs_2._guide/node0436.html) statements to draw connected line figures. If
the shapes are all definable as interconnected, continuous lines, you can
use a simpler function, called [PolyDraw()](../Includes_and_Autodocs_2._guide/node0467.html). PolyDraw() takes a set of line
endpoints and draws a shape using these points. You call PolyDraw() with
the statement:


```c
    PolyDraw(&rastPort, count, arraypointer);
```
[PolyDraw()](../Includes_and_Autodocs_2._guide/node0467.html) reads the array of points and draws a line from the first pair
of coordinates to the second, then a connecting line to each succeeding
pair in the array until count points have been connected. This function
uses the current drawing mode, pens, line pattern, and write mask
specified in the target [RastPort](../Libraries_Manual_guide/node034A.html); for example, this fragment draws a
rectangle, using the five defined pairs of x,y coordinates.


```c
    SHORT linearray[] =
        {
         3, 3,
        15, 3,
        15,15,
         3,15,
         3, 3
        };

    PolyDraw(&rastPort, 5, linearray);
```
