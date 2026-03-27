---
title: intuition.library/MakeClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-makeclass-2
functions: [AddClass, FreeClass, MakeClass, NewObject, RemoveClass]
libraries: [intuition.library]
---

# intuition.library/MakeClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MakeClass -- Create and initialize a boopsi class. (V36)

    SYNOPSIS
	iclass = MakeClass( [ClassID](autodocs-3.5/include-intuition-classusr-h.md), SuperClassID, SuperClassPtr,
	D0                  A0       A1            A2
		InstanceSize, Flags )
	        D0            D1

	struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *MakeClass( [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *,
		[UWORD](autodocs-3.5/include-exec-types-h.md), ULONG );

    FUNCTION
	For class implementors only.

	This function creates a new public or private boopsi class.
	The superclass should be defined to be another boopsi class:
	all classes are descendants of the class "rootclass".

	Superclasses can be public or private.  You provide a name/ID
	for your class if it is to be a public class (but you must
	have registered your class name and your attribute ID's with
	Commodore before you do this!).  For a public class, you would
	also call [AddClass()](autodocs-3.5/intuition-library-addclass-2.md) to make it available after you have
	finished your initialization.

	Returns pointer to an [IClass](autodocs-3.5/include-intuition-classes-h.md) data structure for your
	class.  You then initialize the [Hook](autodocs-3.5/include-utility-hooks-h.md) cl_Dispatcher for
	your class methods code.  You can also set up special data
	shared by all objects in your class, and point cl_UserData at it.
	The last step for public classes is to call [AddClass()](autodocs-3.5/intuition-library-addclass-2.md).

	You dispose of a class created by this function by calling
	[FreeClass()](autodocs-3.5/intuition-library-freeclass-2.md).

    INPUTS
	[ClassID](autodocs-3.5/include-intuition-classusr-h.md) = NULL for private classes, the name/ID string for public
		classes
	SuperClassID = name/ID of your new class's superclass.  NULL if
		superclass is a private class
	SuperClassPtr = pointer to private superclass.  Only used if
		SuperClassID is NULL.  You are required never to provide
		a NULL superclass.
	InstanceSize = the size of the instance data that your class's
		objects will require, beyond that data defined for
		your superclass's objects.
	Flags = for future enhancement, including possible additional
		parameters.  Provide zero for now.

    RESULT
	Pointer to the resulting class, or NULL if not possible:
	- no memory for class data structure
	- public superclass not found
	- public class of same name/ID as this one already exists

    NOTES

    EXAMPLE
	Creating a private subclass of a public class:

```c
    /* per-object instance data defined by my class	*/
    struct MyInstanceData {
```
	ULONG	mid_SomeData;
```c
    };

    /* some useful table I'll share use for all objects */
    [UWORD](autodocs-3.5/include-exec-types-h.md) myTable[] = {
```
	5, 4, 3, 2, 1, 0
```c
    };

    struct [IClass](autodocs-3.5/include-intuition-classes-h.md)	*
    initMyClass()
    {
```
	ULONG __saveds	myDispatcher();
	ULONG	hookEntry();	/* asm-to-C interface glue	*/
	struct [IClass](autodocs-3.5/include-intuition-classes-h.md)	*cl;
	struct [IClass](autodocs-3.5/include-intuition-classes-h.md)	*MakeClass();

	if ( cl =  MakeClass( NULL,
		    SUPERCLASSID, NULL,		/* superclass is public      */
		    sizeof (struct MyInstanceData),
		    0 ))
	{
	    /* initialize the cl_Dispatcher [Hook](autodocs-3.5/include-utility-hooks-h.md)	*/
	    cl->cl_Dispatcher.h_Entry = hookEntry;
	    cl->cl_Dispatcher.h_SubEntry = myDispatcher;
	    cl->cl_Dispatcher.h_Data = (VOID *) 0xFACE;	/* unused */

	    cl-cl_UserData = (ULONG) myTable;
	}
	return ( cl );
```c
    }

    BUGS
```
	The typedef 'Class' isn't consistently used.  Class pointers
	used blindly should be [APTR](autodocs-3.5/include-exec-types-h.md), or struct [IClass](autodocs-3.5/include-intuition-classes-h.md) for class implementors.

    SEE ALSO
	[FreeClass()](autodocs-3.5/intuition-library-freeclass-2.md), [AddClass()](autodocs-3.5/intuition-library-addclass-2.md), [RemoveClass()](autodocs-3.5/intuition-library-removeclass-2.md), [NewObject()](autodocs-3.5/intuition-library-newobject-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
