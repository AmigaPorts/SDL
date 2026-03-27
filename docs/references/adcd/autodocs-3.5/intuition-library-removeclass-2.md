---
title: intuition.library/RemoveClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-removeclass-2
functions: [AddClass, FreeClass, MakeClass]
libraries: [intuition.library]
---

# intuition.library/RemoveClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	RemoveClass -- Make a public boopsi class unavailable. (V36)

    SYNOPSIS
	RemoveClass( classPtr )
		     A0

	VOID RemoveClass( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) * );

    FUNCTION
	Makes a public class unavailable for public consumption.
	It's OK to call this function for a class which is not
	yet in the internal public class list, or has been
	already removed.

    INPUTS
	ClassPtr = pointer to *public* class created by [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
		may be NULL.

    RESULT
	None.

    NOTES

    BUGS

    SEE ALSO
	[MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md), [FreeClass()](autodocs-3.5/intuition-library-freeclass-2.md), [AddClass()](autodocs-3.5/intuition-library-addclass-2.md)
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
