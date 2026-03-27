# gadtools.library/GT_RefreshWindow



NAME

```c
    GT_RefreshWindow -- Refresh all the GadTools gadgets. (V36)
```
SYNOPSIS

```c
    GT_RefreshWindow(win, req)
                     A0   A1

    VOID GT_RefreshWindow(struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *);
```
FUNCTION

```c
    Perform the initial refresh of all the GadTools gadgets you have
    created.  After you have opened your window, you must call this
    function.  Or, if you have opened your window without gadgets,
    you add the gadgets with [intuition.library/AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html),
    refresh them using [intuition.library/RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html), then call
    this function.
    You should not need this function at other times.
```
INPUTS

```c
    win - Pointer to the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) containing GadTools gadgets.
    req - Pointer to requester, or NULL if not a requester (currently
        ignored - use NULL).
```
RESULT

    None.
EXAMPLE

NOTES

    req must currently be NULL.  GadTools gadgets are not supported
    in requesters.  This field may allow such support at a future date.
BUGS

SEE ALSO

```c
    [GT_BeginRefresh()](../Includes_and_Autodocs_2._guide/node03EF.html)
```
