# intuition.library/ViewPortAddress



NAME

    ViewPortAddress -- Return the address of a window's viewport.
SYNOPSIS

```c
    [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) = ViewPortAddress( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
    D0                          A0

    struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *ViewPortAddress( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

    Returns the address of the viewport associated with the specified
    window.  The viewport is actually the viewport of the screen within
    which the window is displayed.  If you want to use any of the graphics,
    text, or animation primitives in your window and that primitive
    requires a pointer to a viewport, you can use this call.

    This pointer is only valid as long as your window's screen remains
    open, which is ensured by keeping your window open.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window for which you want the viewport address
```
RESULT

```c
    Returns the address of the Intuition [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure for
    your window's screen .
```
BUGS

    This routine is unnecessary: you can just use the expression
    &Window->WScreen->ViewPort.
SEE ALSO

    graphics.library
