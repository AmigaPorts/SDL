# graphics.library/AreaEllipse



NAME


    AreaEllipse -- add a ellipse to areainfo list for areafill.
SYNOPSIS

```c
    error = AreaEllipse( rp, cx,   cy,   a,    b    )
    d0                   a1  d0:16 d1:16 d2:16 d3:16

    LONG AreaEllipse( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT, SHORT, SHORT)
```
FUNCTION

```c
    Add an ellipse to the vector buffer. It will be draw when [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) is
    called.
```
INPUTS

```c
    rp - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    cx - x coordinate of the centerpoint relative to the rastport.
    cy - y coordinate of the centerpoint relative to the rastport.
    a  - the horizontal radius of the ellipse (note: a must be > 0)
    b  - the vertical radius of the ellipse (note: b must be > 0)
```
RESULT

    error - zero for success, or -1 if there is no space left in the
            vector list
SEE ALSO

```c
    [AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) [AreaCircle()](../Includes_and_Autodocs_2._guide/node0416.html) [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html) [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html)
    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
