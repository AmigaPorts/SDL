# graphics.library/DrawEllipse



NAME

    DrawEllipse -- Draw an ellipse centered at cx,cy with vertical
       and horizontal radii of a,b respectively.
SYNOPSIS

```c
    DrawEllipse( rp, cx, cy, a, b )
                 a1  d0  d1  d2 d3

    void DrawEllipse( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT, SHORT, SHORT);
```
FUNCTION
   Creates an elliptical outline within the rectangular region

    specified by the parameters, using the current foreground pen color.
INPUTS

```c
    rp - pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) into which the ellipse will be drawn.
    cx - x coordinate of the centerpoint relative to the rastport.
    cy - y coordinate of the centerpoint relative to the rastport.
    a - the horizontal radius of the ellipse (note: a must be > 0)
    b - the vertical radius of the ellipse (note: b must be > 0)
```
BUGS

NOTES

    this routine does not clip the ellipse to a non-layered rastport.
SEE ALSO

```c
    DrawCircle(), [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
