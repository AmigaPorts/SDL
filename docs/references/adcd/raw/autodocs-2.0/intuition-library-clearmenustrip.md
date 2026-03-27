# intuition.library/ClearMenuStrip



NAME

```c
    ClearMenuStrip -- Clear (detach) the menu strip from the window.
```
SYNOPSIS

```c
    ClearMenuStrip( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                    A0

    VOID ClearMenuStrip( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    Detaches the current menu strip from the window; menu strips
    are attached to windows using the [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html) function
    (or, for V36, [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html) ).

    If the menu is in use (for that matter if any menu is in use)
    this function will block (Wait()) until the user has finished.

    Call this function before you make any changes to the data
    in a [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) or [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) structure which is part of a menu
    strip linked into a window.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to a window structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [SetMenuStrip()](../Includes_and_Autodocs_2._guide/node0253.html), [ResetMenuStrip()](../Includes_and_Autodocs_2._guide/node024A.html)
```
