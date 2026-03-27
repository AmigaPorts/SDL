---
title: intuition.library/DisposeObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-disposeobject-2
functions: [DisposeObject, GetAttr, MakeClass, NewObject]
libraries: [intuition.library]
---

# intuition.library/DisposeObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DisposeObject -- Deletes a 'boopsi' object. (V36)

    SYNOPSIS
	DisposeObject( [Object](autodocs-3.5/include-intuition-classusr-h.md) )
	               A0

	VOID DisposeObject( [APTR](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Deletes a boopsi object and all of it auxiliary data.
	These objects are all created by [NewObject()](autodocs-3.5/intuition-library-newobject-2.md).  Objects
	of certain classes "own" other objects, which will also
	be deleted when the object is passed to DisposeObject().
	[Read](autodocs-3.5/dos-library-read-2.md) the per-class documentation carefully to be aware
	of these instances.

    INPUTS
	[Object](autodocs-3.5/include-intuition-classusr-h.md) = abstract pointer to a boopsi object returned by [NewObject()](autodocs-3.5/intuition-library-newobject-2.md).
		The pointer may be NULL, in which case this function has
		no effect.

    NOTES
	This function invokes the OM_DISPOSE method.

    RESULT
	None.

    BUGS

    SEE ALSO
	[NewObject()](autodocs-3.5/intuition-library-newobject-2.md), SetAttrs(), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
