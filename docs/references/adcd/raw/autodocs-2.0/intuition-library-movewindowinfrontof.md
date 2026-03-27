# intuition.library/MoveWindowInFrontOf



NAME

```c
    MoveWindowInFrontOf -- Arrange the relative depth of a window. (V36)
```
SYNOPSIS

```c
    MoveWindowInFrontOf( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), BehindWindow )
                         A0      A1

    VOID MoveWindowInFrontOf( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    Depth-arranges a window in front of an another window.
    Brings out the layers.library [MoveLayerInFrontOf()](../Includes_and_Autodocs_2._guide/node039F.html) to the
    Intuition user.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) =  window to re-position in front of another window
    BehindWindow =  window to re-position in front of
```
RESULT

    Repositions window.
BUGS

    Doesn't respect backdrop windows.
SEE ALSO

```c
    [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html), [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html), [layers.library/MoveLayerInFrontOf()](../Includes_and_Autodocs_2._guide/node039F.html)
```
