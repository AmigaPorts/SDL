---
title: intuition.library/ModifyProp
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-modifyprop
functions: [ModifyProp, NewModifyProp]
libraries: [intuition.library]
---

# intuition.library/ModifyProp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ModifyProp -- Modify the current parameters of a proportional gadget.
SYNOPSIS

```c
    ModifyProp( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Requester](autodocs-2.0/includes-intuition-intuition-h.md),
                A0      A1      A2
                Flags, HorizPot, VertPot, HorizBody, VertBody )
                D0     D1        D2       D3         D4

    VOID ModifyProp( struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD, UWORD, UWORD, UWORD, UWORD );
```
FUNCTION

```c
    Modifies the parameters of the specified proportional gadget.  The
    gadget's internal state is then recalculated and the imagery
    is redisplayed in the window or requester that contains the gadget.

    The requester variable can point to a requester structure.  If the
    gadget has the GTYP_REQGADGET flag set, the gadget is in a requester
    and the window pointer must point to the window of the requester.
    If this is not the gadget of a requester, the requester argument may
    be NULL.

    NOTE: this function causes all gadgets from the proportional
    gadget to the end of the gadget list to be refreshed, for
    reasons of compatibility.
    For more refined display updating, use [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md).

    New for V36: ModifyProp() refreshing consists of redrawing gadgets
    completely.  [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md) has changed this behavior (see
    [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md)).
```
INPUTS

```c
    PropGadget = pointer to a proportional gadget
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window containing the gadget or the window
        containing the requester containing the gadget.
    [Requester](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a requester (may be NULL if this isn't
        a requester gadget)
    Flags = value to be stored in the Flags field of the [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
    HorizPot = value to be stored in the HorizPot field of the [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
    VertPot = value to be stored in the VertPot field of the [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
    HorizBody = value to be stored in the HorizBody field of the [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
    VertBody = value to be stored in the VertBody field of the [PropInfo](autodocs-2.0/includes-intuition-intuition-h.md)
```
RESULT

    None
BUGS

SEE ALSO

```c
    [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md)
    The Intuition Reference Manual and Amiga Rom Kernel Manual contain
    more information on Proportional Gadgets.
```

---

## See Also

- [ModifyProp — intuition.library](../autodocs/intuition.library.md#modifyprop)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
