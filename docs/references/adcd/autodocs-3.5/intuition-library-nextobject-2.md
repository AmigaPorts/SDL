---
title: intuition.library/NextObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-nextobject-2
functions: [DisposeObject, GetAttr, MakeClass, NextObject]
libraries: [intuition.library]
---

# intuition.library/NextObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	NextObject -- iterate through the object on an Exec list. (V36)

    SYNOPSIS
	object = NextObject( objectPtrPtr )
	D0                   A0

	[APTR](autodocs-3.5/include-exec-types-h.md) NextObject( [APTR](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	This function is for boopsi class implementors only.

	When you collect a set of boopsi objects on an Exec [List](autodocs-3.5/include-exec-lists-h.md)
	structure by invoking their OM_ADDMEMBER method, you
	can (only) retrieve them by iterations of this function.

	Works even if you remove and dispose the returned list
	members in turn.

    INPUTS
	Initially, you set a pointer variable to equal the
	lh_Head field of the list (or mlh_Head field of a MinList).
	You pass the *address* of that pointer repeatedly
	to NextObject() until it returns NULL.


    EXAMPLE
	/* here is the OM_DISPOSE case of some class's dispatcher */
	case OM_DISPOSE:
	    /* dispose members	*/
	    object_state = mydata->md_CollectionList.lh_Head;
	    while ( member_object = NextObject( &object_state ) )
	    {
		DoMethod( member_object, OM_REMOVE ); /* remove from list */
		DoMethodA( member, msg );	/* and pass along dispose	*/
	    }

    RESULT
	Returns pointers to each object in the list in turn, and NULL
	when there are no more.

    NOTES

    BUGS

    SEE ALSO
	[DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), SetAttrs(), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NextObject — intuition.library](../autodocs/intuition.library.md#nextobject)
