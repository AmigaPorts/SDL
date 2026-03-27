# intuition.library/SetMenuStrip



NAME

    SetMenuStrip -- Attach a menu strip to a window.
SYNOPSIS

```c
    Success = SetMenuStrip( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) )
    D0                      A0      A1

    BOOL SetMenuStrip( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) * );
```
FUNCTION

```c
    Attaches the menu strip to the window.  After calling this routine,
    if the user presses the menu button, this specified menu strip
    will be displayed and accessible by the user.

    Menus with zero menu items are not allowed.

    NOTE:  You should always design your menu strip changes to be a
    two-way operation, where for every menu strip you add to your
    window you should always plan to clear that strip sometime.  Even
    in the simplest case, where you will have just one menu strip for
    the lifetime of your window, you should always clear the menu strip
    before closing the window.  If you already have a menu strip attached
    to this window, the correct procedure for changing to a new menu
    strip involves calling [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html) to clear the old first.

    The sequence of events should be:
    - [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
    - zero or more iterations of:
    - SetMenuStrip()
    - [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html)
    - [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to a [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure
    [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) = pointer to the first menu in the menu strip
```
RESULT

    TRUE if there were no problems.  TRUE always, since this routine
    will wait until it is OK to proceed.
BUGS

SEE ALSO

```c
    [ClearMenuStrip()](../Includes_and_Autodocs_2._guide/node0205.html), [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html)
```
