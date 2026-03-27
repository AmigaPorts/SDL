# intuition.library/MoveWindow



NAME

    MoveWindow -- Ask Intuition to move a window.
SYNOPSIS

```c
    MoveWindow( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), DeltaX, DeltaY )
                A0      D0      D1

    VOID MoveWindow( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, WORD, WORD );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to move the window
    the specified distance.  The delta arguments describe how far to
    move the window along the respective axes.

    Note that the window will not be moved immediately, but rather
    will be moved the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    Interactions with other arbitration of Intuition data structures
    may defer this operation longer.  For V36, you can use the new
    IDCMP class IDCMP_CHANGEWINDOW to detect when this operation has
    completed.

    New for V36: Intuition now will do validity checking on the final
    position.  To send absolute movements, or to move and size a
    window in one step, use [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html).
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the structure of the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) to be moved
    DeltaX = how far to move the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) on the x-axis
    DeltaY = how far to move the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) on the y-axis
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html), [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html)
```
