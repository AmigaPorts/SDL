---
title: intuition.library/ModifyProp
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-modifyprop-2
functions: [ModifyProp, NewModifyProp]
libraries: [intuition.library]
---

# intuition.library/ModifyProp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ModifyProp -- Modify the current parameters of a proportional gadget.

    SYNOPSIS
	ModifyProp( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md),
		    A0	    A1	    A2
```c
           	    Flags, HorizPot, VertPot, HorizBody, VertBody )
```
		    D0	   D1	     D2	      D3	 D4

	VOID ModifyProp( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
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
	For more refined display updating, use [NewModifyProp()](autodocs-3.5/intuition-library-newmodifyprop-2.md).

	New for V36: ModifyProp() refreshing consists of redrawing gadgets
	completely.  [NewModifyProp()](autodocs-3.5/intuition-library-newmodifyprop-2.md) has changed this behavior (see
	[NewModifyProp()](autodocs-3.5/intuition-library-newmodifyprop-2.md)).

    INPUTS
	PropGadget = pointer to a proportional gadget
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window containing the gadget or the window
	    containing the requester containing the gadget.
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (may be NULL if this isn't
	    a requester gadget)
	Flags = value to be stored in the Flags field of the [PropInfo](autodocs-3.5/include-intuition-intuition-h.md)
	HorizPot = value to be stored in the HorizPot field of the [PropInfo](autodocs-3.5/include-intuition-intuition-h.md)
	VertPot = value to be stored in the VertPot field of the [PropInfo](autodocs-3.5/include-intuition-intuition-h.md)
	HorizBody = value to be stored in the HorizBody field of the [PropInfo](autodocs-3.5/include-intuition-intuition-h.md)
	VertBody = value to be stored in the VertBody field of the [PropInfo](autodocs-3.5/include-intuition-intuition-h.md)

    RESULT
	None

    BUGS

    SEE ALSO
	[NewModifyProp()](autodocs-3.5/intuition-library-newmodifyprop-2.md)
	The Intuition Reference Manual and Amiga ROM Kernel Manual contain
	more information on Proportional Gadgets.

---

## See Also

- [ModifyProp — intuition.library](../autodocs/intuition.library.md#modifyprop)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
