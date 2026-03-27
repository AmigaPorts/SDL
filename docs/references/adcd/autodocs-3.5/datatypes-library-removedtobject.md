---
title: datatypes.library/RemoveDTObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-removedtobject
functions: [RemoveGList]
libraries: [intuition.library]
---

# datatypes.library/RemoveDTObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RemoveDTObject - [Remove](autodocs-3.5/exec-library-remove-2.md) an object from a window.        (V39)

    SYNOPSIS
	position = RemoveDTObject (window, object);
	d0			    a0	    a1

	[LONG](autodocs-3.5/include-exec-types-h.md) RemoveDTObject (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *);

    FUNCTION
	Removes the object from the window's object list.  This will wait
	until the AsyncLayout process is complete.  The object will
	receive a DTM_REMOVEDTOBJECT message to inform the object it has
	been removed.

    INPUTS
	window - Pointer to the window.

	object - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

    RETURNS
	Returns the ordinal position of the removed object.  If the
	object wasn't found in the appropriate list then a -1 is
	returned.

    SEE ALSO
	[AddDTObject()](autodocs-3.5/datatypes-library-adddtobject.md), [intuition.library/RemoveGList()](autodocs-3.5/intuition-library-removeglist-2.md)

---

## See Also

- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
