# graphics.library/SetDrMd



NAME

```c
    SetDrMd -- Set drawing mode for a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
SYNOPSIS

```c
    SetDrMd( rp, mode )
             a1  d0:8

    void SetDrMd( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UBYTE );
```
FUNCTION

    Set the drawing mode for lines, fills and text.
    Get the bit definitions from rastport.h
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure.
    mode - 0-255, some combinations may not make much sense.
```
RESULT

    The mode set is dependant on the bits selected.
    Changes minterms to reflect new drawing mode.
    Sets line drawer to restart pattern.
BUGS

SEE ALSO

```c
    [SetAPen()](../Includes_and_Autodocs_2._guide/node0475.html) [SetBPen()](../Includes_and_Autodocs_2._guide/node0476.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
