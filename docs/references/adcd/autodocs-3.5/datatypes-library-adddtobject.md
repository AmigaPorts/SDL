---
title: datatypes.library/AddDTObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-adddtobject
functions: [AddGList]
libraries: [intuition.library]
---

# datatypes.library/AddDTObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AddDTObject - Add an object to a window or requester.   (V39)

    SYNOPSIS
	realposition = AddDTObject (window, requester, object, position);
	d0			    a0      a1	       a2      d0

	[LONG](autodocs-3.5/include-exec-types-h.md) AddDTObject (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *,
			  [Object](autodocs-3.5/include-intuition-classusr-h.md) *, LONG);

    FUNCTION
	This function adds a single object to the gadget list of the given
	window or requester at the position in the list specified by the
	position argument.

	When the object is added to the gadget list, the object will
	receive a GM_LAYOUT message with the gpl_Initial field set to
	one.

    INPUTS
	window - Pointer to the window.

	requester - Must be NULL.

	object - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

	position - Integer position in the list for the new gadget.
	    -1 to add to the end of the list.

    RETURNS
	Returns the position of where the object was actually added.

    SEE ALSO
	[RemoveDTObject()](autodocs-3.5/datatypes-library-removedtobject.md), [intuition.library/AddGList()](autodocs-3.5/intuition-library-addglist-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
