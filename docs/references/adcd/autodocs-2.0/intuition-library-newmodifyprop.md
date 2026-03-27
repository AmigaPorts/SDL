---
title: intuition.library/NewModifyProp
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-newmodifyprop
functions: [ModifyProp]
libraries: [intuition.library]
---

# intuition.library/NewModifyProp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NewModifyProp -- [ModifyProp()](autodocs-2.0/intuition-library-modifyprop.md), but with selective refresh.
```
SYNOPSIS

```c
    NewModifyProp( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Requester](autodocs-2.0/includes-intuition-intuition-h.md), Flags,
                   A0      A1      A2         D0
            HorizPot, VertPot, HorizBody, VertBody, NumGad )
            D1        D2       D3         D4        D5

    VOID NewModifyProp( struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD, UWORD, UWORD, UWORD, UWORD, WORD );
```
FUNCTION

```c
    Performs the function of [ModifyProp()](autodocs-2.0/intuition-library-modifyprop.md), but refreshes
    gadgets in the list as specified by the NumGad parameter.
    With NumGad = -1, this function is identical to [ModifyProp()](autodocs-2.0/intuition-library-modifyprop.md).

    New for V36: When NumGad = 1, this function will now perform
    an incremental update of the proportional gadget knob image,
    rather than refreshing the entire gadget.  This means much
    less flashing when programmatically scrolling a proportional
    gadget.
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
    NumGad = number of gadgets to be refreshed after propgadget internals
        have been adjusted.  -1 means "to end of list."
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ModifyProp()](autodocs-2.0/intuition-library-modifyprop.md)
    The Intuition Reference Manual contains more information on
    Proportional Gadgets.
```

---

## See Also

- [ModifyProp — intuition.library](../autodocs/intuition.library.md#modifyprop)
