# graphics.library/AreaMove



NAME


    AreaMove -- Define a new starting point for a new
                shape in the vector list.
SYNOPSIS

```c
    error =  AreaMove( rp,   x,     y)
     d0                a1  d0:16  d1:16

    LONG AreaMove( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT );
```
FUNCTION

```c
    Close  the last polygon and start another polygon
    at  (x,y). Add the necessary  points  to  vector
    buffer. Closing a polygon may result in the generation
    of another [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) to close previous polygon.
    [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) to have an initialized [AreaInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line22) structure attached
    to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
INPUTS

```c
    rp  - points to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    x,y - positions in the raster
```
RETURNS

    error - zero for success, or -1 if there is no space left in the
    vector list
BUGS

SEE ALSO

```c
    [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html) [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html) [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
