# intuition.library/WindowToFront



NAME

    WindowToFront -- Ask Intuition to bring a window to the front.
SYNOPSIS

```c
    WindowToFront( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                   A0

    VOID WindowToFront( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to bring the window
    in front of all other windows in the screen.

    Note that the window will not be depth-arranged immediately, but rather
    will be arranged the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    [Remember](../Includes_and_Autodocs_2._guide/node00D4.html#line1233) that WFLG_BACKDROP windows cannot be depth-arranged.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the structure of the window to be brought to front
```
RESULT

    None
BUGS

SEE ALSO

```c
    [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html), [MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html)
```
