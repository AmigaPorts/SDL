---
title: 5 Intuition Gadgets / Gadget Enabling and Disabling
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-enabling-and-disabling
functions: [AddGList, OffGadget, OnGadget, RefreshGList, RemoveGList]
libraries: [intuition.library]
---

# 5 Intuition Gadgets / Gadget Enabling and Disabling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A gadget may be disabled so that it cannot be chosen by the user.  When a
gadget is disabled, its image is ghosted.  A ghosted gadget is overlaid
with a pattern of dots, thereby making the imagery less distinct.  The
dots are drawn into the select box of the gadget and any imagery that
extends outside of the select box is not affected by the ghosting.

The application may initialize whether a gadget is disabled by setting the
[GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md) flag in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure's [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field before a gadget
is submitted to Intuition.  Clear this flag to create an enabled gadget.

After a gadget is submitted to Intuition for display, its current enable
state may be changed by calling [OnGadget()](autodocs-2.0/intuition-library-ongadget.md) or [OffGadget()](autodocs-2.0/intuition-library-offgadget.md).  If the gadget
is in a requester, the requester must currently be displayed when calling
these functions.


```c
    void OnGadget ( struct Gadget *gadget, struct Window *window,
                    struct Requester *requester );
    void OffGadget( struct Gadget *gadget, struct Window *window,
                    struct Requester *requester );
```
Depending on what sort of imagery you choose for your gadget, [OnGadget()](autodocs-2.0/intuition-library-ongadget.md)
may not be smart enough to correct the gadget's displayed imagery.  See
the section on "[Updating a Gadget's Imagery](libraries/5-gadget-refreshing-by-the-program-updating-a-gadget-s.md)" for more details.

Multiple gadgets may be enabled or disabled by calling [OnGadget()](autodocs-2.0/intuition-library-ongadget.md) or
[OffGadget()](autodocs-2.0/intuition-library-offgadget.md) for each gadget, or by removing the gadgets with
[RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md), setting or clearing the [GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md) flag on each,
replacing the gadgets with [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md), and refreshing with [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md).

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
