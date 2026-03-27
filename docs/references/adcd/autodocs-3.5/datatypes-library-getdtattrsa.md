---
title: datatypes.library/GetDTAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-getdtattrsa
functions: [GetAttr]
libraries: [intuition.library]
---

# datatypes.library/GetDTAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetDTAttrsA - Obtain attributes for an object.          (V39)

    SYNOPSIS
	retval = GetDTAttrsA (o, attrs);
	d0		      a0  a2

	ULONG GetDTAttrsA (Object *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	retval = GetDTAttrs (o, tag1, ...);

	ULONG GetDTAttrs (Object *, [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);

    FUNCTION
	This function is used to get the attributes of a data type
	object.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

	attrs - Attributes to get, terminated with TAG_DONE.  The data
	    element of each pair contains the address of the storage
	    variable.

    RETURNS
	retval - Contains the number of attributes the system was able
	    to obtain.

    SEE ALSO
	[SetDTAttrsA()](autodocs-3.5/datatypes-library-setdtattrsa.md), [intuition.library/GetAttr()](autodocs-3.5/intuition-library-getattr-2.md)

---

## See Also

- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
