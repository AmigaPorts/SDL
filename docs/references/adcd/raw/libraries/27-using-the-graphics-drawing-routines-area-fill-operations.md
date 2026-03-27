# 27 / / Using the Graphics Drawing Routines / Area-fill Operations


Assuming that you have properly initialized your [RastPort](../Libraries_Manual_guide/node034A.html) structure to
include a properly initialized [AreaInfo](../Libraries_Manual_guide/node034D.html), you can perform area fill by
using the functions described in this section.

[AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) tells the system to begin a new polygon, closing off any other
polygon that may already be in process by connecting the end-point of the
previous polygon to its starting point. AreaMove() is executed with the
statement:


```c
    LONG result;
    result = AreaMove(&rastPort, x, y);
```
[AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) returns 0 if successful, -1 if there was no more space left in
the vector list. [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) tells the system to add a new vertex to a list
that it is building.  No drawing takes place until [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) is executed.
AreaDraw is executed with the statement:


```c
    LONG result;
    result = AreaDraw(&rastPort, x, y);
```
[AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) returns 0 if successful, -1 if there was no more space left in
the vector list. [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) tells the system to draw all of the defined
shapes and fill them.  When this function is executed, it obeys the
drawing mode and uses the line pattern and area pattern specified in your
[RastPort](../Libraries_Manual_guide/node034A.html) to render the objects you have defined.

To fill an area, you do not have to [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) back to the first point
before calling [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html).  AreaEnd() automatically closes the polygon.
AreaEnd() is executed with the following statement:


```c
    LONG result;
    result = AreaEnd(&rastPort);
```
[AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) returns 0 if successful, -1 if there was an error. To turn off
the outline function, you have to set the [RastPort](../Libraries_Manual_guide/node034A.html) [Flags](../Libraries_Manual_guide/node034A.html#line21) variable back to
0 with [BNDRYOFF()](../Includes_and_Autodocs_2._guide/node00B6.html#line35):


```c
    #include "graphics/gfxmacros.h"

    BNDRYOFF(&rastPort);
```
Otherwise, every subsequent area-fill or rectangle-fill operation will
outline their rendering with the outline pen ([AOlPen](../Libraries_Manual_guide/node0350.html#line9)).

