---
title: intuition.library/RefreshGList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-refreshglist-2
functions: [RefreshGadgets]
libraries: [intuition.library]
---

# intuition.library/RefreshGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RefreshGList -- Refresh (redraw) a chosen number of gadgets.

    SYNOPSIS
	RefreshGList( Gadgets, [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md), NumGad )
		      A0       A1      A2         D0

	VOID RefreshGList( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, WORD );

    FUNCTION
	Refreshes (redraws) gadgets in the gadget list starting
	from the specified gadget.  At most NumGad gadgets are redrawn.
	If NumGad is -1, all gadgets until a terminating NULL value
	in the NextGadget field is found will be refreshed, making this
	routine a superset of [RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md).

	The [Requester](autodocs-3.5/include-intuition-intuition-h.md) parameter can point to a [Requester](autodocs-3.5/include-intuition-intuition-h.md) structure.  If
	the first gadget in the list has the GTYP_REQGADGET flag set, the
	gadget list refers to gadgets in a requester and the pointer
	must necessarily point to a window.  If these are not the gadgets
	of a requester, the requester argument may be NULL.

	Be sure to see the [RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md) function description, as this
	function is simply an extension of that.

    INPUTS
	Gadgets = pointer to the first in the list of gadgets wanting
	    refreshment
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window containing the gadget or its requester
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (ignored if [Gadget](autodocs-3.5/include-intuition-intuition-h.md) is not attached
	    to a Requester).
	NumGad  = maximum number of gadgets to be refreshed.  A value of -1
	  will cause all gadgets to be refreshed from gadget to the
	  end of the list.  A value of -2 will also do this, but if 'Gadgets'
	  points to a [Requester](autodocs-3.5/include-intuition-intuition-h.md) [Gadget](autodocs-3.5/include-intuition-intuition-h.md) (GTYP_REQGADGET) ALL gadgets in the
	  requester will be refreshed (this is a mode compatible with v1.1
	  RefreshGadgets().)

    RESULT
	None

    BUGS

    SEE ALSO
	[RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md)

---

## See Also

- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
