# intuition.library/RefreshGadgets



NAME

```c
    RefreshGadgets -- Refresh (redraw) the gadget display.
```
SYNOPSIS

```c
    RefreshGadgets( Gadgets, [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) )
                    A0       A1      A2

    VOID RefreshGadgets( struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) * );
```
FUNCTION

```c
    Refreshes (redraws) all of the gadgets in the gadget list starting
    from the specified gadget.

    The window parameter must point to the window which contains the
    gadget, or which contains the requester that contains the gadget
    The requester parameter must only be valid if the gadget has the
    GTYP_REQGADGET flag set, a requirement for all requester gadgets.

    The Pointer argument points to a [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure.

    The two main reasons why you might want to use this routine are:
    first, that you've modified the imagery of the gadgets in your
    display and you want the new imagery to be displayed; secondly,
    if you think that some graphic operation you just performed
    trashed the gadgetry of your display, this routine will refresh
    the imagery for you.

    Note that to modify the imagery of a gadget, you must first remove
    that gadget from the window's gadget list, using [RemoveGadget()](../Includes_and_Autodocs_2._guide/node0246.html) (or
    RemoveGList()).  After changing the image, border, text (including
    text for a string gadget), the gadget is replaced in the gadget list
    (using [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html) or [AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html)).  Adding gadgets does not cause
    them to be displayed (refreshed), so this function, or [RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html)
    is typically called.

    A common technique is to set or reset the GFLG_SELECTED flag of a
    Boolean gadget and then call RefreshGadgets() to see it displayed
    highlighted if and only if GFLG_SELECTED is set.  If you wish to do
    this and be completely proper, you must [RemoveGadget()](../Includes_and_Autodocs_2._guide/node0246.html), change the
    GFLG_SELECTED flag, [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html), and RefreshGadgets(), or the
    equivalent.

    The gadgets argument can be a copy of the FirstGadget variable in
    the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure that you want refreshed:
    the effect of this will be that all gadgets will be redrawn.
    However, you can selectively refresh just some of the gadgets
    by starting the refresh part-way into the list:  for instance,
    redrawing your window non-GTYP_GZZGADGET gadgets only, which you've
    conveniently grouped at the end of your gadget list.

    Even more control is available using the [RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html) routine which
    enables you to refresh a single gadget, or number of your choice.

    NOTE:  It's never safe to tinker with the gadget list yourself.  Don't
    supply some gadget list that Intuition hasn't already processed in
    the usual way.
```
INPUTS

```c
    Gadgets = pointer to the first in the list of gadgets wanting
        refreshment
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the window containing the gadget or its requester
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = pointer to a requester (ignored if gadget is not attached
        to a requester).
```
RESULT

    None
BUGS

SEE ALSO

```c
    [RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html), [RemoveGadget()](../Includes_and_Autodocs_2._guide/node0246.html), [RemoveGList()](../Includes_and_Autodocs_2._guide/node0247.html), [AddGadget()](../Includes_and_Autodocs_2._guide/node01FC.html), [AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html)
```
