---
title: intuition.library/AddClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-addclass-2
functions: [FreeClass, MakeClass, RemoveClass]
libraries: [intuition.library]
---

# intuition.library/AddClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	AddClass -- Make a public class available (V36)

    SYNOPSIS
	AddClass( Class )
	          A0

	VOID AddClass( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) * );

    FUNCTION
	Adds a public boopsi class to the internal list of classes available
	for public consumption.

	You must call this function after you call [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md).

    INPUTS
	Class = pointer returned by [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md)

    RESULT
	Nothing returned.

    NOTES

    BUGS
	Although there is some protection against creating classes
	with the same name as an existing class, this function
	does not do any checking or other dealings with like-named
	classes.  Until this is rectified, only officially registered
	names can be used for public classes, and there is no
	"class replacement" policy in effect.

    SEE ALSO
	[MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md), [FreeClass()](autodocs-3.5/intuition-library-freeclass-2.md), [RemoveClass()](autodocs-3.5/intuition-library-removeclass-2.md)
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
