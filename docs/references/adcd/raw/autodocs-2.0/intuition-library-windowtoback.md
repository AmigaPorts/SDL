# intuition.library/WindowToBack



NAME

    WindowToBack -- Ask Intuition to send a window behind others.
SYNOPSIS

```c
    WindowToBack( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                  A0

    VOID WindowToBack( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to send the window
    in back of all other windows in the screen.

    Note that the window will not be depth-arranged immediately, but rather
    will be arranged the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) that WFLG_BACKDROP windows cannot be depth-arranged.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the structure of the window to be sent to the back
```
RESULT

    None
BUGS

SEE ALSO

```c
    [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html), [MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html)
```
