# intuition.library/FreeClass



    NAME
	FreeClass -- Frees a boopsi class created by [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html). (V36)

    SYNOPSIS
	success = FreeClass( ClassPtr )
	D0                   A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) FreeClass( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) * );

    FUNCTION
	For class implementors only.

	Tries to free a boopsi class created by [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html).  This
	won't always succeed: classes with outstanding objects or
	with subclasses cannot be freed.  You cannot allow the code
	which implements the class to be unloaded in this case.

	For public classes, this function will *always* remove
	the class (see [RemoveClass()](../Includes_and_Autodocs_3._guide/node03E1.html) ) making it unavailable, whether
	it succeeds or not.

	If you have a dynamically allocated data for your class (hanging
	off of cl_UserData), try to free the class before you free the
	user data, so you don't get stuck with a half-freed class.

    INPUTS
	ClassPtr - pointer to a class created by [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html).

    RESULT
	Returns FALSE if the class could not be freed.  Reasons include,
	but will not be limited to, having non-zero cl_ObjectCount or
	cl_SubclassCount.

	Returns TRUE if the class could be freed.

	Calls [RemoveClass()](../Includes_and_Autodocs_3._guide/node03E1.html) for the class in either case.

    EXAMPLE
	Freeing a private class with dynamically allocated user data:

	freeMyClass( cl )
	struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35)	*cl;
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
	[MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

