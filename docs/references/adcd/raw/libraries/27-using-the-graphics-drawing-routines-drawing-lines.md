# 27 / / Using the Graphics Drawing Routines / Drawing Lines


Two functions are associated with line drawing: [Move()](../Includes_and_Autodocs_2._guide/node045D.html) and [Draw()](../Includes_and_Autodocs_2._guide/node0436.html). Move()
simply moves the cursor to a new position.  It is like picking up a
drawing pen and placing it at a new location. This function is executed by
the statement:


```c
    Move(&rastPort, x, y);
```
[Draw()](../Includes_and_Autodocs_2._guide/node0436.html) draws a line from the current x,y position to a new x,y position
specified in the statement itself. The drawing pen is left at the new
position. This is done by the statement:


```c
    Draw(&rastPort, x, y);
```
[Draw()](../Includes_and_Autodocs_2._guide/node0436.html) uses the pen color specified for [FgPen](../Libraries_Manual_guide/node0350.html#line3). Here is a sample sequence
that draws a line from location (0,0) to (100,50).


```c
    SetAPen(&rastPort, COLOR1);    /* Set A pen color. */
    Move(&rastPort, 0, 0);    /* Move to this location. */
    Draw(&rastPort, 100,50);    /* Draw to a this location. */


    Caution:
    --------
    If you attempt to draw a line outside the bounds of the [BitMap](../Libraries_Manual_guide/node032B.html#line74),
    using the basic initialized [RastPort](../Libraries_Manual_guide/node034A.html), you may crash the system.
    You must either do your own software clipping to assure that the line
    is in range, or use the layers library. Software clipping means that
    you need to determine if the line will fall outside your BitMap
    before you draw it, and render only the part which falls inside
    the BitMap.
```
