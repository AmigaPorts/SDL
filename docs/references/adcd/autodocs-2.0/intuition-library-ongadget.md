---
title: intuition.library/OnGadget
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-ongadget
functions: [AddGList, RefreshGList]
libraries: [intuition.library]
---

# intuition.library/OnGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OnGadget -- Enable the specified gadget.
SYNOPSIS

```c
    OnGadget( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Requester](autodocs-2.0/includes-intuition-intuition-h.md) )
              A0      A1      A2

    VOID OnGadget( struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This command enables the specified gadget.  When a gadget is
    enabled, these things happen:
    - its imagery is displayed normally (not ghosted)
    - the GFLG_DISABLED flag is cleared
    - the gadget can thereafter be selected by the user

    The window parameter must point to the window which contains the
    gadget, or which contains the requester that contains the gadget
    The requester parameter must only be valid if the gadget has the
    GTYP_REQGADGET flag set, a requirement for all requester gadgets.
```
   NOTE:  it's never safe to tinker with the gadget list yourself.  Don't
   supply some gadget that Intuition hasn't already processed in
   the usual way.


```c
    NOTE: for compatibility reasons, this function will refresh all
    gadgets in a requester, and all gadgets from gadget to the
    end of the gadget list if gadget is in a window.

    If you want to improve on this behavior, you may perform the
    equivalent operation yourself: remove a gadget or gadgets,
    change the state of their GFLG_DISABLED flag, replace the
    gadgets using [AddGList()](autodocs-2.0/intuition-library-addglist.md), and selectively call [RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md).
```
INPUTS

```c
    [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the gadget that you want disabled
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a window structure containing the gadget or
        containing the requester which contains the gadget
    [Requester](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a requester (may by NULL if this isn't
       a requester gadget (i.e. GTYP_REQGADGET is not set)).
```
RESULT

    None
BUGS

SEE ALSO

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
