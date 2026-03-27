# graphics.library/AreaDraw



NAME


    AreaDraw -- Add a point to a list of end points for areafill.
SYNOPSIS

```c
    error = AreaDraw( rp,  x,     y)
      d0              A1 D0:16 D1:16

    ULONG AreaDraw( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT);
```
FUNCTION


    Add point to the vector buffer.
INPUTS

```c
    rp      - points to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure.
    x,y     - are coordinates of a point in the raster.
```
RESULT

    error   - zero for success, else -1 if no there was no space
              left in the vector list.
BUGS

SEE ALSO

```c
    [AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html) [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
