# intuition.library/ClearPointer



NAME

    ClearPointer -- Clear the mouse pointer definition from a window.
SYNOPSIS

```c
    ClearPointer( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                  A0

    VOID ClearPointer( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    Clears the window of its own definition of the Intuition mouse pointer.
    After calling ClearPointer(), every time this window is the active
    one the default Intuition pointer will be the pointer displayed
    to the user.  If your window is the active one when this routine
    is called, the change will take place immediately.

    [Custom](../Includes_and_Autodocs_2._guide/node00CD.html#line26) definitions of the mouse pointer which this function clears
    are installed by a call to [SetPointer()](../Includes_and_Autodocs_2._guide/node0255.html).
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window to be cleared of its pointer definition
```
RESULT

    None
BUGS

SEE ALSO

```c
    [SetPointer()](../Includes_and_Autodocs_2._guide/node0255.html)
```
