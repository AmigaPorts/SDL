---
title: datatypes.library/RefreshDTObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-refreshdtobjecta
functions: [RefreshGList]
libraries: [intuition.library]
---

# datatypes.library/RefreshDTObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RefreshDTObjectA - Refresh a datatypes object.          (V39)

    SYNOPSIS
	RefreshDTObjectA (object, window, req, attrs)
			   a0	   a1	   a2	a3

	VOID RefreshDTObjectA (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
			        struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	RefreshDTObject (object, window, req, tag1, ...);

	VOID RefreshDTObject (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
			       struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);

    FUNCTION
	Refreshes the specified object, by sending the GM_RENDER method to
	the object.

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

	window - Pointer to the window.

	req - Must be NULL.

	attrs - Additional attributes (currently none are defined).

    SEE ALSO
	[AddDTObject()](autodocs-3.5/datatypes-library-adddtobject.md), [RemoveDTObject()](autodocs-3.5/datatypes-library-removedtobject.md), [intuition.library/RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md)

---

## See Also

- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
