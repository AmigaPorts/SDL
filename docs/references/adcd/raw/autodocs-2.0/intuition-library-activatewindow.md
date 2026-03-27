# intuition.library/ActivateWindow



NAME

    ActivateWindow -- Activate an Intuition window.
SYNOPSIS

```c
    [success =] ActivateWindow( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
    [D0]                        A0

    [LONG] ActivateWindow( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
    /* returns LONG in V36 and higher */
```
FUNCTION

    Activates an Intuition window.

    Note that this call may have its action deferred: you cannot assume
    that when this call is made the selected window has become active.
    This action will be postponed while the user plays with gadgets and
    menus, or sizes and drags windows.  You may detect when the window
    actually has become active by the IDCMP_ACTIVEWINDOW IDCMP message.

    This call is intended to provide flexibility but not to confuse the
    user.  Please call this function synchronously with some action
    by the user.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = a pointer to a [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure
```
RESULT

    V35 and before: None.
    V36 and later: returns zero if no problem queuing up
        the request for deferred action
BUGS

    Calling this function in a tight loop can blow out Intuition's deferred
    action queue.
SEE ALSO

```c
    [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html), and the WFLG_ACTIVATE window flag
```
