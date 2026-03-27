# intuition.library/MakeClass



    NAME
	MakeClass -- Create and initialize a boopsi class. (V36)

    SYNOPSIS
	iclass = MakeClass( [ClassID](../Includes_and_Autodocs_3._guide/node0636.html#line20), SuperClassID, SuperClassPtr,
	D0                  A0       A1            A2
		InstanceSize, Flags )
	        D0            D1

	struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) *MakeClass( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) *,
		[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), ULONG );

    FUNCTION
	For class implementors only.

	This function creates a new public or private boopsi class.
	The superclass should be defined to be another boopsi class:
	all classes are descendants of the class "rootclass".

	Superclasses can be public or private.  You provide a name/ID
	for your class if it is to be a public class (but you must
	have registered your class name and your attribute ID's with
	Commodore before you do this!).  For a public class, you would
	also call [AddClass()](../Includes_and_Autodocs_3._guide/node0391.html) to make it available after you have
	finished your initialization.

	Returns pointer to an [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) data structure for your
	class.  You then initialize the [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) cl_Dispatcher for
	your class methods code.  You can also set up special data
	shared by all objects in your class, and point cl_UserData at it.
	The last step for public classes is to call [AddClass()](../Includes_and_Autodocs_3._guide/node0391.html).

	You dispose of a class created by this function by calling
	[FreeClass()](../Includes_and_Autodocs_3._guide/node03AF.html).

    INPUTS
	[ClassID](../Includes_and_Autodocs_3._guide/node0636.html#line20) = NULL for private classes, the name/ID string for public
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
    [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) myTable[] = {
```
	5, 4, 3, 2, 1, 0
```c
    };

    struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35)	*
    initMyClass()
    {
```
	ULONG __saveds	myDispatcher();
	ULONG	hookEntry();	/* asm-to-C interface glue	*/
	struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35)	*cl;
	struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35)	*MakeClass();

	if ( cl =  MakeClass( NULL,
		    SUPERCLASSID, NULL,		/* superclass is public      */
		    sizeof (struct MyInstanceData),
		    0 ))
	{
	    /* initialize the cl_Dispatcher [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27)	*/
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
	used blindly should be [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), or struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) for class implementors.

    SEE ALSO
	[FreeClass()](../Includes_and_Autodocs_3._guide/node03AF.html), [AddClass()](../Includes_and_Autodocs_3._guide/node0391.html), [RemoveClass()](../Includes_and_Autodocs_3._guide/node03E1.html), [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

