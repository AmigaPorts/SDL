# graphics.library/SetAPen



NAME

```c
    SetAPen -- Set the primary pen for a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    SetAPen( rp, pen )
             a1  d0

    void SetAPen( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UBYTE );
```
FUNCTION

    Set the primary drawing pen for lines, fills, and text.
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure.
    pen - (0-255)
```
RESULT

```c
    Changes the minterms in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to reflect new primary pen.
    Sets line drawer to restart pattern.
```
BUGS

SEE ALSO

```c
    [SetBPen()](../Includes_and_Autodocs_2._guide/node0476.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
