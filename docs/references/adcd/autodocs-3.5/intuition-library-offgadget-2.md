---
title: intuition.library/OffGadget
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-offgadget-2
functions: [AddGList, AddGadget, OnGadget, RefreshGList, RefreshGadgets]
libraries: [intuition.library]
---

# intuition.library/OffGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OffGadget -- [Disable](autodocs-3.5/exec-library-disable-2.md) the specified gadget.

    SYNOPSIS
	OffGadget( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md) )
		   A0      A1      A2

	VOID OffGadget( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This command disables the specified gadget.  When a gadget is
	disabled, these things happen:
	     - its imagery is displayed ghosted
	     - the GFLG_DISABLED flag is set
	     - the gadget cannot be selected by User

	The window parameter must point to the window which contains the
	gadget, or which contains the requester that contains the gadget.
	The requester parameter must only be valid if the gadget has the
	GTYP_REQGADGET flag set, a requirement for all requester gadgets.

       NOTE:  it's never safe to tinker with the gadget list yourself.  Don't
       supply some gadget that Intuition hasn't already processed in
       the usual way.

    	NOTE: for compatibility reasons, this function will refresh all
	gadgets in a requester, and all gadgets from gadget to the
	end of the gadget list if gadget is in a window.

	If you want to improve on this behavior, you may perform the
	equivalent operation yourself: remove a gadget or gadgets,
	change the state of their GFLG_DISABLED flag, replace the
	gadgets using [AddGList()](autodocs-3.5/intuition-library-addglist-2.md), and selectively call [RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md).

    INPUTS
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the gadget that you want disabled
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a window structure containing the gadget or
	    containing the requester which contains the gadget
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (may by NULL if this isn't
```c
           a requester gadget (i.e. GTYP_REQGADGET is not set)).

    RESULT
```
	None

    BUGS

    SEE ALSO
	[OnGadget()](autodocs-3.5/intuition-library-ongadget-2.md), [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md), [RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
