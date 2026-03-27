---
title: intuition.library/NewObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-newobject-2
functions: [DisposeObject, GetAttr, MakeClass]
libraries: [intuition.library]
---

# intuition.library/NewObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	NewObjectA -- Create an object from a class. (V36)
	NewObject -- Varargs stub for NewObjectA(). (V36)

    SYNOPSIS
	object = NewObjectA( class, classID, tagList )
	D0                   A0     A1       A2

	[APTR](autodocs-3.5/include-exec-types-h.md) NewObjectA( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	object = NewObject( class, classID, Tag1, ... )

	[APTR](autodocs-3.5/include-exec-types-h.md) NewObject( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, ULONG, ... );

    FUNCTION
	This is the general method of creating objects from 'boopsi' classes.
	('Boopsi' stands for "basic object-oriented programming system for
	Intuition".)

	You specify a class either as a pointer (for a private class) or
	by its ID string (for public classes).  If the class pointer
	is NULL, then the classID is used.

	You further specify initial "create-time" attributes for the
	object via a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list, and they are applied to the resulting
	generic data object that is returned.  The attributes, their meanings,
	attributes applied only at create-time, and required attributes
	are all defined and documented on a class-by-class basis.

    INPUTS
	class = abstract pointer to a boopsi class gotten via [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md).
	classID = the name/ID string of a public class.  This parameter is
		only used if 'class' is NULL.
	tagList = pointer to array of TagItems containing attribute/value
		pairs to be applied to the object being created

    RESULT
	A boopsi object, which may be used in different contexts such
	as a gadget or image, and may be manipulated by generic functions.
	You eventually free the object using [DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md).

    NOTES
	This function invokes the OM_NEW "method" for the class specified.

    BUGS
	Typedef's for 'Object' and 'Class' are defined in the include
	files but not used consistently.  The generic type [APTR](autodocs-3.5/include-exec-types-h.md) is
	probably best used for object and class "handles", with the
	type (UBYTE *) used for classID strings.

    SEE ALSO
	[DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), SetAttrs(), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
