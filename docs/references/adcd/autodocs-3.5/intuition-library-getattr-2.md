---
title: intuition.library/GetAttr
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-getattr-2
functions: [DisposeObject, MakeClass, NewObject]
libraries: [intuition.library]
---

# intuition.library/GetAttr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetAttr -- Inquire the value of some attribute of an object. (V36)

    SYNOPSIS
	attr = GetAttr( AttrID, [Object](autodocs-3.5/include-intuition-classusr-h.md), StoragePtr )
	D0		D0	A0	A1

	ULONG GetAttr( ULONG, [APTR](autodocs-3.5/include-exec-types-h.md), ULONG * );

    FUNCTION
	Inquires from the specified object the value of the specified attribute.

	You always pass the address of a long variable, which will
	receive the same value that would be passed to SetAttrs() in
	the ti_Data portion of a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) element.  See the documentation
	for the class for exceptions to this general rule.

	Not all attributes will respond to this function.  Those that
	will are documented on a class-by-class basis.

    INPUTS
	AttrID = the attribute tag ID understood by the object's class
	[Object](autodocs-3.5/include-intuition-classusr-h.md) = abstract pointer to the boopsi object you are interested in
	StoragePtr = pointer to appropriate storage for the answer

    RESULT
	Returns FALSE (0) if the inquiries of attribute are not provided
	by the object's class.

    NOTES
	This function invokes the OM_GET method of the object.

    BUGS

    SEE ALSO
	[NewObject()](autodocs-3.5/intuition-library-newobject-2.md), [DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), SetAttrs(), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
