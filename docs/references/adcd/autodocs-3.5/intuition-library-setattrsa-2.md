---
title: intuition.library/SetAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setattrsa-2
functions: [DisposeObject, GetAttr, MakeClass, NewObject, SetAttrsA]
libraries: [intuition.library]
---

# intuition.library/SetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetAttrsA -- Specify attribute values for an object. (V36)
	SetAttrs -- Varargs stub for SetAttrsA(). (V36)

    SYNOPSIS
	result = SetAttrsA( [Object](autodocs-3.5/include-intuition-classusr-h.md), TagList )
	D0                  A0      A1

	ULONG SetAttrsA( [APTR](autodocs-3.5/include-exec-types-h.md), struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	result = SetAttrs( [Object](autodocs-3.5/include-intuition-classusr-h.md), Tag1, ... )

	ULONG SetAttrs( [APTR](autodocs-3.5/include-exec-types-h.md), ULONG, ... );

    FUNCTION
	Specifies a set of attribute/value pairs with meaning as
	defined by a 'boopsi' object's class.

	This function does not provide enough context information or
	arbitration for boopsi gadgets which are attached to windows
	or requesters.  For those objects, use SetGadgetAttrs().

    INPUTS
	[Object](autodocs-3.5/include-intuition-classusr-h.md) = abstract pointer to a boopsi object.
	TagList = array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures with attribute/value pairs.

    RESULT
	The object does whatever it wants with the attributes you provide.
	The return value tends to be non-zero if the changes would require
	refreshing gadget imagery, if the object is a gadget.

    NOTES
	This function invokes the OM_SET method with a NULL [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md)
	parameter.

    BUGS

    SEE ALSO
	[NewObject()](autodocs-3.5/intuition-library-newobject-2.md), [DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetAttrsA — intuition.library](../autodocs/intuition.library.md#setattrsa)
