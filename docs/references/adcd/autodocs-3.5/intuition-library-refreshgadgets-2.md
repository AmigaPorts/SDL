---
title: intuition.library/RefreshGadgets
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-refreshgadgets-2
functions: [AddGList, AddGadget, RefreshGList, RefreshGadgets, RemoveGList, RemoveGadget]
libraries: [intuition.library]
---

# intuition.library/RefreshGadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RefreshGadgets -- Refresh (redraw) the gadget display.

    SYNOPSIS
	RefreshGadgets( Gadgets, [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md) )
		        A0       A1      A2

	VOID RefreshGadgets( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Refreshes (redraws) all of the gadgets in the gadget list starting
	from the specified gadget.

	The window parameter must point to the window which contains the
	gadget, or which contains the requester that contains the gadget
	The requester parameter must only be valid if the gadget has the
	GTYP_REQGADGET flag set, a requirement for all requester gadgets.

	The Pointer argument points to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure.

	The two main reasons why you might want to use this routine are:
	first, that you've modified the imagery of the gadgets in your
	display and you want the new imagery to be displayed; secondly,
	if you think that some graphic operation you just performed
	trashed the gadgetry of your display, this routine will refresh
	the imagery for you.

	Note that to modify the imagery of a gadget, you must first remove
	that gadget from the window's gadget list, using [RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md) (or
	RemoveGList()).  After changing the image, border, text (including
	text for a string gadget), the gadget is replaced in the gadget list
	(using [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md) or [AddGList()](autodocs-3.5/intuition-library-addglist-2.md)).  Adding gadgets does not cause
	them to be displayed (refreshed), so this function, or [RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md)
	is typically called.

	A common technique is to set or reset the GFLG_SELECTED flag of a
	Boolean gadget and then call RefreshGadgets() to see it displayed
	highlighted if and only if GFLG_SELECTED is set.  If you wish to do
	this and be completely proper, you must [RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md), change the
	GFLG_SELECTED flag, [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md), and RefreshGadgets(), or the
	equivalent.

	The gadgets argument can be a copy of the FirstGadget variable in
	the [Window](autodocs-3.5/include-intuition-intuition-h.md) structure that you want refreshed:
	the effect of this will be that all gadgets will be redrawn.
	However, you can selectively refresh just some of the gadgets
	by starting the refresh part-way into the list:  for instance,
	redrawing your window non-GTYP_GZZGADGET gadgets only, which you've
	conveniently grouped at the end of your gadget list.

	Even more control is available using the [RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md) routine which
	enables you to refresh a single gadget, or number of your choice.

	NOTE:  It's never safe to tinker with the gadget list yourself.  Don't
	supply some gadget list that Intuition hasn't already processed in
	the usual way.

    INPUTS
	Gadgets = pointer to the first in the list of gadgets wanting
	    refreshment
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window containing the gadget or its requester
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (ignored if gadget is not attached
	    to a requester).

    RESULT
	None

    BUGS

    SEE ALSO
	[RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md), [RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md), [RemoveGList()](autodocs-3.5/intuition-library-removeglist-2.md), [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md), [AddGList()](autodocs-3.5/intuition-library-addglist-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
- [RemoveGadget — intuition.library](../autodocs/intuition.library.md#removegadget)
