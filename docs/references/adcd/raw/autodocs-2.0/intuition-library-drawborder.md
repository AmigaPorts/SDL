# intuition.library/DrawBorder



NAME

```c
    DrawBorder -- Draw the specified [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600) structure into a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    DrawBorder( [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600), LeftOffset, TopOffset )
                A0        A1      D0          D1

    VOID DrawBorder( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600) *, WORD, WORD );
```
FUNCTION

```c
    First, sets up the draw mode and pens in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) according to the
    arguments of the [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600) structure.  Then, draws the vectors of
    the border argument into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), offset by the left and top
    offsets.

    As with all graphics rendering routines, the border will be clipped to
    to the boundaries of the RastPort's layer, if it exists.  This is
    the case with window RastPorts.

    This routine will draw all borders in the NULL-terminated list linked
    by the NextBorder field of the border argument.
```
INPUTS

```c
    [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to receive the border rendering
    [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600) = pointer to a [Border](../Includes_and_Autodocs_2._guide/node00D4.html#line600) structure
    LeftOffset = the offset to be added to each vector's x coordinate
    TopOffset = the offset to be added to each vector's y coordinate
```
RESULT

    None
BUGS

SEE ALSO

