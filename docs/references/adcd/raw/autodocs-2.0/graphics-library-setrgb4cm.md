# graphics.library/SetRGB4CM



NAME

```c
    SetRGB4CM -- Set one color register for this [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113).
```
SYNOPSIS

```c
    SetRGB4CM(  cm,  n,   r,    g,    b)
                a0  d0  d1:4  d2:4  d3:4

    void SetRGB4CM( struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) *, SHORT, UBYTE, UBYTE, UBYTE );
```
INPUTS

```c
    cm = colormap
    n = the number of the color register to set. Ranges from 0 to 31
         on current amiga displays.
    r = red level (0-15)
    g = green level (0-15)
    b = blue level (0-15)
```
RESULT

```c
    Store the (r,g,b) triplet at index n of the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) structure.
    This function can be used to set up a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) before before
    linking it into a viewport.
```
BUGS

SEE ALSO

```c
    [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html) [GetRGB4()](../Includes_and_Autodocs_2._guide/node0448.html) [SetRGB4()](../Includes_and_Autodocs_2._guide/node047C.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
