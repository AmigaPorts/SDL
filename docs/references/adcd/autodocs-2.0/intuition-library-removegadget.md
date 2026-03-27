---
title: intuition.library/RemoveGadget
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-removegadget
functions: [AddGList, AddGadget, RemoveGList]
libraries: [intuition.library]
---

# intuition.library/RemoveGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemoveGadget -- Remove a gadget from a window.
SYNOPSIS

```c
    Position = RemoveGadget( [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) )
    D0                       A0      A1

    UWORD RemoveGadget( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

    Removes the given gadget from the gadget list of the specified
    window.  Returns the ordinal position of the removed gadget.

    If the gadget is in a requester attached the the window, this
    routine will look for it and remove it if it is found.

    If the gadget pointer points to a gadget that isn't in the
    appropriate list, -1 is returned.  If there aren't any gadgets in the
    list, -1 is returned.  If you remove the 65535th gadget from the list
    -1 is returned.
NOTES

    New with V37: If one of the gadgets you wish to remove
    is the active gadget, this routine will wait for the user
    to release the mouse button before deactivating and removing
    the gadget.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window containing the gadget or the requester
        containing the gadget to be removed.
    [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the gadget to be removed.  The gadget itself
        describes whether this is a gadget that should be removed from the
        window or some requester.
```
RESULT

    Returns the ordinal position of the removed gadget.  If the gadget
    wasn't found in the appropriate list, or if there are no gadgets in
    the list, returns -1.
BUGS

SEE ALSO

```c
    [AddGadget()](autodocs-2.0/intuition-library-addgadget.md), [AddGList()](autodocs-2.0/intuition-library-addglist.md), [RemoveGList()](autodocs-2.0/intuition-library-removeglist.md)
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
