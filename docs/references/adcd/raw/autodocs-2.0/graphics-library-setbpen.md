# graphics.library/SetBPen



NAME

```c
    SetBPen -- Set secondary pen for a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
SYNOPSIS

```c
    SetBPen( rp, pen )
             a1  d0

    void SetBPen( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UBYTE );
```
FUNCTION

    Set the secondary drawing pen for lines, fills, and text.
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure.
    pen - (0-255)
```
RESULT

```c
    Changes the minterms in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to reflect new secondary pen.
    Sets line drawer to restart pattern.
```
BUGS

SEE ALSO

```c
    [SetAPen()](../Includes_and_Autodocs_2._guide/node0475.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
