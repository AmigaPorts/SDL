# intuition.library/DrawImage



NAME

```c
    DrawImage -- Draw the specified [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structure into a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    DrawImage( [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621), LeftOffset, TopOffset )
               A0        A1     D0          D1

    VOID DrawImage( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, struct [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621)    *, WORD, WORD );
```
FUNCTION

```c
    First, sets up the draw mode and pens in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) according to the
    arguments of the [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) structure.  Then, moves the image data of
    the image argument into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), offset by the left and top
    offsets.

    This routine does window layer clipping if you pass your window's
    (layered) [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) -- if you draw an image outside of your window,
    your imagery will be clipped at the window's edge.  If you pass
    a (non-layered) screen [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55), you MUST be sure your image is
    wholly contained within the rastport bounds.

    If the NextImage field of the image argument is non-NULL,
    the next image is rendered as well, and so on until some
    NextImage field is found to be NULL.
```
INPUTS

```c
    [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to receive image rendering
    [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621) = pointer to an image structure
    LeftOffset = the offset which will be added to the image's x coordinate
    TopOffset = the offset which will be added to the image's y coordinate
```
RESULT

    None
NOTES

```c
    Intuition always has and will continue to assume there are
    at least as many planes of data pointed to by ImageData as there
    are '1' bits in the PlanePick field.  Please ensure that
    this is so.  (See the intuition.h include file for full details
    on using PlanePick).
```
BUGS

SEE ALSO

```c
    [DrawImageState()](../Includes_and_Autodocs_2._guide/node0211.html), [EraseImage()](../Includes_and_Autodocs_2._guide/node0215.html)
```
