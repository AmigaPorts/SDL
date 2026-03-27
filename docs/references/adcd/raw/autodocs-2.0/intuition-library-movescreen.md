# intuition.library/MoveScreen



NAME

    MoveScreen -- Attempt to move the screen by the increments provided.
SYNOPSIS

```c
    MoveScreen( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97), DeltaX, DeltaY )
                A0      D0      D1

    VOID MoveScreen( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, WORD, WORD );
```
FUNCTION

```c
    Moves the screen the specified increment, specified in screen
    pixel resolution coordinates.

    New for V36: [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) movement limits have been greatly relaxed,
    to support screen scrolling.  In particular, negative values
    for screen LeftEdge and TopEdge may now be valid.
```
   If the DeltaX and DeltaY variables you specify would move the screen
   in a way that violates any restrictions, the screen will be moved
   as far as possible.  You may examine the LeftEdge and TopEdge fields

```c
    of the [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) structure after this function returns to see where
    the screen really ended up.

    In operation, this function determines what the resulting position
    values that are actually to be used, sets these up, and calls
    [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html) and [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html).
```
INPUTS

```c
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = pointer to a [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) structure
    DeltaX = amount to move the screen on the x-axis
            Note that DeltaX no longer (V36) need be set to zero
    DeltaY = amount to move the screen on the y-axis
            Note that these coordinates are in the same resolution
            as the screen (such as HIRES or INTERLACE)
```
RESULT

    None
BUGS

SEE ALSO

```c
    [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html)
```
