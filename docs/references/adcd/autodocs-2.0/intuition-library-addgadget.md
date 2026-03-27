---
title: intuition.library/AddGadget
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-addgadget
functions: [AddGList, AddGadget, RemoveGList, RemoveGadget]
libraries: [intuition.library]
---

# intuition.library/AddGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddGadget -- Add a gadget to the gadget list of a window.
SYNOPSIS

```c
    RealPosition = AddGadget( [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), Position )
    D0                        A0      A1      D0

    UWORD  AddGadget( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD );
```
FUNCTION

```c
    Adds the specified gadget to the gadget list of the given window,
    linked in at the position in the list specified by the position
    argument (that is, if Position == 0, the gadget will be inserted
    at the head of the list, and if Position == 1 then the gadget will
    be inserted after the first gadget and before the second).  If the
    position you specify is greater than the number of gadgets in the
    list, your gadget will be added to the end of the list.

    Calling AddGadget() does not cause your gadget to be redisplayed.
    The benefit of this is that you may add several gadgets without
    having the gadget list redrawn every time.

    This procedure returns the position at which your gadget was added.

    NOTE:  A relatively safe way to add the gadget to the end of the
    list is to specify a position of -1 (i.e., (UWORD) ~0).  That way,
    only the 65536th (and multiples of it) will be inserted at the wrong
    position.  The return value of the procedure will tell you where it
    was actually inserted.

    NOTE:  The system window gadgets are initially added to the
    front of the gadget list.  The reason for this is:  If you position
    your own gadgets in some way that interferes with the graphical
    representation of the system gadgets, the system's ones will be "hit"
    first by user.  If you then start adding gadgets to the front of the
    list, you will disturb this plan, so beware.  On the other hand, if
    you don't violate the design rule of never overlapping your gadgets,
    there's no problem.

    NOTE:  You may not add your own gadgets to a screen.  Gadgets may
    be added to backdrop windows, however, which can be visually similar,
    but also provide an IDCMP channel for gadget input messages.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window to get your gadget
    [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the new gadget
    Position = integer position in the list for the new gadget (starting
        from zero as the first position in the list)
```
RESULT

    Returns the position of where the gadget was actually added.
BUGS

SEE ALSO

```c
    [AddGList()](autodocs-2.0/intuition-library-addglist.md), [RemoveGadget()](autodocs-2.0/intuition-library-removegadget.md), [RemoveGList()](autodocs-2.0/intuition-library-removeglist.md)
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
- [RemoveGadget — intuition.library](../autodocs/intuition.library.md#removegadget)
