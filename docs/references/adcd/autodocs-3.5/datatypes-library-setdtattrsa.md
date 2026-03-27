---
title: datatypes.library/SetDTAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-setdtattrsa
functions: [SetGadgetAttrsA]
libraries: [intuition.library]
---

# datatypes.library/SetDTAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetDTAttrsA - Set attributes for an object.             (V39)

    SYNOPSIS
	retval = SetDTAttrsA (o, win, req, attrs);
	d0		      a0  a1   a2   a3

	ULONG SetDTAttrsA (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *,
			   struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	retval = SetDTAttrs (o, win, req, tag1, ...);

	ULONG SetDTAttrs (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *,
			  [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);

    FUNCTION
	This function is used to set the attributes of a data type
	object.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

	win - [Window](autodocs-3.5/include-intuition-intuition-h.md) that the object has been added to.

	attrs - Attributes to set, terminated with TAG_DONE.

    TAGS
	see [<datatypes/datatypesclass.h>](autodocs-3.5/include-datatypes-datatypesclass-h.md) for tags.

    SEE ALSO
	[GetDTAttrsA()](autodocs-3.5/datatypes-library-getdtattrsa.md), [intuition.library/SetGadgetAttrsA()](autodocs-3.5/intuition-library-setgadgetattrsa-2.md)

---

## See Also

- [SetGadgetAttrsA — intuition.library](../autodocs/intuition.library.md#setgadgetattrsa)
