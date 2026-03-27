---
title: intuition.library/RemoveGList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-removeglist-2
functions: [AddGList, AddGadget, RemoveGadget]
libraries: [intuition.library]
---

# intuition.library/RemoveGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RemoveGList -- [Remove](autodocs-3.5/exec-library-remove-2.md) a sublist of gadgets from a window.

    SYNOPSIS
	Position = RemoveGList( [Window](autodocs-3.5/include-intuition-intuition-h.md), [Gadget](autodocs-3.5/include-intuition-intuition-h.md), Numgad )
	D0			A0	A1	D0

	[UWORD](autodocs-3.5/include-exec-types-h.md) RemoveGList( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, WORD );

    FUNCTION
	Removes 'Numgad' gadgets from the gadget list of the specified
	window.  Will remove gadgets from a requester if the first
	gadget's GadgetType flag GTYP_REQGADGET is set.

	Otherwise identical to [RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md).

    NOTE
	The last gadget in the list does NOT have its link zeroed.
	New with V36: OK, last gadget's NextGadget field is set to NULL.

	New with V37: If one of the gadgets you wish to remove
	is the active gadget, this routine will wait for the user
	to release the mouse button before deactivating and removing
	the gadget.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window containing the gadget or the requester
	    containing the gadget to be removed.
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the gadget to be removed.  The gadget itself
           describes whether this is a gadget that should be removed
           from the window or some requester.
	Numgad = number of gadgets to be removed.  If -1, remove all gadgets
	    to end of window gadget list

    RESULT
	Returns the ordinal position of the removed gadget.  If the gadget
	wasn't found in the appropriate list, or if there are no gadgets in
	the list, returns -1.

    BUGS

    SEE ALSO
	[RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md), [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md), [AddGList()](autodocs-3.5/intuition-library-addglist-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [RemoveGadget — intuition.library](../autodocs/intuition.library.md#removegadget)
