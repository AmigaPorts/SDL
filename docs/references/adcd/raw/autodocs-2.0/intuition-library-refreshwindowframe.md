# intuition.library/RefreshWindowFrame



NAME

    RefreshWindowFrame -- Ask Intuition to redraw your window border.
SYNOPSIS

```c
    RefreshWindowFrame( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                        A0

    VOID RefreshWindowFrame( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

    Refreshes the border of a window, including title region and all
    of the window's gadgets.

    You may use this call if you wish to update the display of your
    borders.  The expected use of this is to correct unavoidable
    corruption.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = a pointer to a [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure
```
RESULT

    None
BUGS

SEE ALSO

