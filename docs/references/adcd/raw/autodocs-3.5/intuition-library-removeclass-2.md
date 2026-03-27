# intuition.library/RemoveClass



    NAME
	RemoveClass -- Make a public boopsi class unavailable. (V36)

    SYNOPSIS
	RemoveClass( classPtr )
		     A0

	VOID RemoveClass( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) * );

    FUNCTION
	Makes a public class unavailable for public consumption.
	It's OK to call this function for a class which is not
	yet in the internal public class list, or has been
	already removed.

    INPUTS
	ClassPtr = pointer to *public* class created by [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
		may be NULL.

    RESULT
	None.

    NOTES

    BUGS

    SEE ALSO
	[MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html), [FreeClass()](../Includes_and_Autodocs_3._guide/node03AF.html), [AddClass()](../Includes_and_Autodocs_3._guide/node0391.html)
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

