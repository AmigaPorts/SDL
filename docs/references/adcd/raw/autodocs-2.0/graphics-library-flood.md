# graphics.library/Flood



NAME

    Flood -- Flood rastport like areafill.
SYNOPSIS

```c
    error = Flood( rp, mode, x, y)
    d0            a1   d2  d0  d1

    BOOL Flood(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, ULONG, SHORT, SHORT);
```
FUNCTION

```c
    Search the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) starting at (x,y).
    Fill all adjacent pixels if they are:
        Mode 0: not the same color as AOLPen
        Mode 1: the same color as the pixel at (x,y)

    When actually doing the fill use the modes that apply to
    standard areafill routine such as drawmodes and patterns.
```
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    (x,y) - coordinate in [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) to start the flood fill at.
    mode -  0 fill all adjacent pixels searching for border.
            1 fill all adjacent pixels that have same pen number
            as the one at (x,y).
```
NOTES

```c
    In order to use Flood, the destination [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) must
    have a valid [TmpRas](../Includes_and_Autodocs_2._guide/node00AF.html#line33) raster whose size is as large as
    that of the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SEE ALSO

```c
    [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) [InitTmpRas()](../Includes_and_Autodocs_2._guide/node0455.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
