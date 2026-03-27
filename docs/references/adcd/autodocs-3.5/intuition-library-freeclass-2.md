---
title: intuition.library/FreeClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-freeclass-2
functions: [MakeClass, RemoveClass]
libraries: [intuition.library]
---

# intuition.library/FreeClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	FreeClass -- Frees a boopsi class created by [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md). (V36)

    SYNOPSIS
	success = FreeClass( ClassPtr )
	D0                   A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) FreeClass( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) * );

    FUNCTION
	For class implementors only.

	Tries to free a boopsi class created by [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md).  This
	won't always succeed: classes with outstanding objects or
	with subclasses cannot be freed.  You cannot allow the code
	which implements the class to be unloaded in this case.

	For public classes, this function will *always* remove
	the class (see [RemoveClass()](autodocs-3.5/intuition-library-removeclass-2.md) ) making it unavailable, whether
	it succeeds or not.

	If you have a dynamically allocated data for your class (hanging
	off of cl_UserData), try to free the class before you free the
	user data, so you don't get stuck with a half-freed class.

    INPUTS
	ClassPtr - pointer to a class created by [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md).

    RESULT
	Returns FALSE if the class could not be freed.  Reasons include,
	but will not be limited to, having non-zero cl_ObjectCount or
	cl_SubclassCount.

	Returns TRUE if the class could be freed.

	Calls [RemoveClass()](autodocs-3.5/intuition-library-removeclass-2.md) for the class in either case.

    EXAMPLE
	Freeing a private class with dynamically allocated user data:

	freeMyClass( cl )
	struct [IClass](autodocs-3.5/include-intuition-classes-h.md)	*cl;
	{
	    struct MyPerClassData	*mpcd;

	    mpcd = (struct MyPerClassData *) cl->cl_UserData;
	    if ( FreeClass( cl ) )
	    {
		FreeMem( mpcd, sizeof mpcd );
		return ( TRUE );
	    }
	    else
	    {
		return ( FALSE );
	    }
	}

    BUGS

    SEE ALSO
	[MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
