# graphics.library/AreaCircle



NAME


    AreaCircle -- add a circle to areainfo list for areafill.
SYNOPSIS

```c
    error = (int) AreaCircle( rp,  cx,  cy, radius)
    D0                        A1   D0   D1  D2

    ULONG AreaCircle(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, WORD, WORD, UWORD);
```
FUNCTION

```c
    Add circle to the vector buffer. It will be drawn to the rastport when
    [AreaEnd](../Includes_and_Autodocs_2._guide/node0419.html) is executed.
```
INPUTS

```c
    rp       - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure

    cx, cy   - the coordinates of the center of the desired circle.

    radius   - is the radius of the circle to draw around the centerpoint.
```
RESULTS

    0 if no error
    -1 if no space left in vector list
NOTES

```c
    This function is actually a macro which calls
        AreaEllipse(rp,cx,cy,radius,radius).
```
SEE ALSO

```c
    [AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) AreaCircle() [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html) [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html)
    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html) [graphics/gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html)
```
