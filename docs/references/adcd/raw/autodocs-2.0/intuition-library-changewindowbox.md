# intuition.library/ChangeWindowBox



NAME

```c
    ChangeWindowBox -- Change window position and dimensions. (V36)
```
SYNOPSIS

```c
    ChangeWindowBox( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), Left, Top, Width, Height )
                     A0      D0    D1   D2     D3

    VOID ChangeWindowBox( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, WORD, WORD, WORD, WORD );
```
FUNCTION

```c
    Makes simultaneous changes in window position and dimensions,
    in absolute (not relative) coordinates.

    Like [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html) and [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), the effect of this function
    is deferred until the next input comes along.  Unlike these
    functions, ChangeWindowBox() specifies absolute window position
    and dimensions, not relative.  This makes for more reliable
    results considering that the action is deferred, so this
    function is typically preferable to [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html) and [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html)
    paired.

    You can detect that this operation has completed by receiving
    the IDCMP_CHANGEWINDOW IDCMP message

    The dimensions are limited to legal range, but you should still
    take care to specify sensible inputs based on the window's dimension
    limits and the size of its screen.

    This function limits the position and dimensions to legal
    values.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = the window to change position/dimension
    Left, Top, Width, Height = new position and dimensions
```
RESULT

    Position and dimension are changed to your specification,
    or as close as possible.
    Returns nothing.
BUGS

SEE ALSO

```c
    [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html),
    [layers.library/MoveSizeLayer()](../Includes_and_Autodocs_2._guide/node03A0.html)
```
