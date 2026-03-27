# graphics.library/AreaEnd



NAME


```c
    AreaEnd -- [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) table of vectors and ellipses and produce areafill.
```
SYNOPSIS

```c
    error = AreaEnd(rp)
      d0            A1

    LONG AreaEnd( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) * );
```
FUNCTION

```c
    Trigger the filling operation.
    [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) the vector buffer and generate required
    fill into the raster planes. After the fill is complete, reinitialize
    for the next [AreaMove](../Includes_and_Autodocs_2._guide/node041A.html) or [AreaEllipse](../Includes_and_Autodocs_2._guide/node0418.html). Use the raster set up by
    [InitTmpRas](../Includes_and_Autodocs_2._guide/node0455.html) when generating an areafill mask.
```
RESULT

    error - zero for success, or -1 if an error occured anywhere.
INPUTS

```c
    rp - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure which specifies where the filled
         regions will be rendered to.
```
BUGS

SEE ALSO

```c
    [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html) [AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html) [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html) [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html)  [InitTmpRas()](../Includes_and_Autodocs_2._guide/node0455.html)
    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
