# intuition.library/ResetMenuStrip



NAME

```c
    ResetMenuStrip -- Re-attach a menu strip to a window. (V36)
```
SYNOPSIS

```c
    Success = ResetMenuStrip( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) )
    D0                        A0      A1

    BOOL ResetMenuStrip( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) * );
```
FUNCTION

```c
    This function is simply a "fast" version of [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html) that
    doesn't perform the precalculations of menu page sizes that
    [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html) does.

    You may call this function ONLY IF the menu strip and all items
    and sub-items have not changed since the menu strip was passed to
    [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html), with the following exceptions:

    - You may change the CHECKED flag to turn a checkmark on or off.
    - You may change the ITEMENABLED flag to enable/disable some
      [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) or [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) structures.

    In all other ways, this function performs like [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html).

    The new sequence of events you can use is:
    - [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
    - [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html)
    zero or more iterations of:
        - [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html)
        - change CHECKED or ITEMENABLED flags
        - ResetMenuStrip()
    - [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html)
    - [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to a [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure
    [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) = pointer to the first menu in the menu strip
```
RESULT

    TRUE always.
BUGS

SEE ALSO

```c
    [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html), [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html)
```
