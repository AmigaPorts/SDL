---
title: intuition.library/AddGList
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-addglist-2
functions: [AddGadget, RemoveGList, RemoveGadget]
libraries: [intuition.library]
---

# intuition.library/AddGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AddGList -- Add a linked list of gadgets to a window or requester.

    SYNOPSIS
	RealPosition = AddGList( [Window](autodocs-3.5/include-intuition-intuition-h.md), [Gadget](autodocs-3.5/include-intuition-intuition-h.md), Position, Numgad, [Requester](autodocs-3.5/include-intuition-intuition-h.md) )
	D0                       A0      A1      D0        D1      A2

	[UWORD](autodocs-3.5/include-exec-types-h.md) AddGList( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md), WORD,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Adds the list of gadgets to the gadget list of the given window
	or requester linked in at the position in the list specified by
	the position argument.

	See [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md) for more information about gadget list position,
	and more information about gadgets in general.

	The requester parameter will be ignored unless the GTYP_REQGADGET
	bit is set in the GadgetType field of the first gadget in the list.
	In that case, the gadget list is added to the requester gadgets.
	NOTE: be sure that GTYP_REQGADGET is either set or cleared consistently
	for all gadgets in the list.  NOTE ALSO: The window parameter
	should point to the window that the requester (will) appear in.

	Will add 'Numgad' gadgets from gadget list linked by the field
	NextGadget, or until some NextGadget field is found to be NULL.  Does
	not assume that the Numgad'th gadget has NextGadget equal to NULL.

	NOTE WELL: In order to link your gadget list in, the NextGadget
	field of the Numgad'th (or last) gadget will be modified.  Thus, if
	you are adding the first 3 gadgets from a linked list of five gadgets,
	this call will sever the connection between your third and fourth
	gadgets.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window to get your gadget
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the first gadget to be added
	Position = integer position in the list for the new gadget
	    (starting from zero as the first position in the list)
	Numgad = the number of gadgets from the linked list to be added
	    if Numgad equals -1, the entire null-terminated list of
	    gadgets will be added.
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = the requester the gadgets will be added to if the
	    GTYP_REQGADGET GadgetType flag is set for the first gadget
	    in the list

    RESULT
	Returns the position of where the first gadget in the list was actually
	added.

    BUGS

    SEE ALSO
	[AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md), [RemoveGadget()](autodocs-3.5/intuition-library-removegadget-2.md), [RemoveGList()](autodocs-3.5/intuition-library-removeglist-2.md)

---

## See Also

- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
- [RemoveGadget — intuition.library](../autodocs/intuition.library.md#removegadget)
