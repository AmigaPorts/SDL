# intuition.library/ZipWindow



NAME

```c
    ZipWindow -- Change window to "alternate" position and
                 dimensions. (V36)
```
SYNOPSIS

```c
    ZipWindow( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
               A0

    VOID ZipWindow( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    Changes the position and dimension of a window to the values
    at the last occasion of ZipWindow being called (or invoked
    via the "zoom" gadget).

    Typically this is used to snap between a normal, large, working
    dimension of the window to a smaller, more innocuous position
    and dimension.

    Like [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), and [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html), the action of
    this function is deferred to the Intuition input handler.

    More tuning needs to be done to establish initial values for
    the first invocation of this function for a window.  You can
    provide initial values using the [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) tag item
    WA_Zoom.

    It could also use a new name, but "ZoomWindow" is misleading,
    since "Zoom" normally implies "scale."

    The zoom gadget will appear (in the place of the old "toback"
    gadget) when you open your window if you either specify a
    sizing gadget or use WA_Zoom.

    You can detect that this function has taken effect by receiving
    an IDCMP_CHANGEWINDOW IDCMP message.
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) -- window to be changed.
```
RESULT

    None
BUGS

```c
    [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) assumes that the proper default "other" dimensions
    are "full size."
```
SEE ALSO

```c
    [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html), [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html)
```
