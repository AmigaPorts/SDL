# graphics.library/SetRast



NAME

    SetRast - Set an entire drawing area to a specified color.
SYNOPSIS

```c
    SetRast( rp, pen )
             a1  d0

    void SetRast( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UBYTE );
```
FUNCTION

```c
    Set the entire contents of the specified [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to the
    specified pen.
```
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    pen - the pen number (0-255) to jam into bitmap
```
RESULT

    All pixels within the drawing area are set to the
    selected pen number.
BUGS

SEE ALSO

```c
    [RectFill()](../Includes_and_Autodocs_2._guide/node046D.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
