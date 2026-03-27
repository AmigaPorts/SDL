# intuition.library/AddClass



    NAME
	AddClass -- Make a public class available (V36)

    SYNOPSIS
	AddClass( Class )
	          A0

	VOID AddClass( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) * );

    FUNCTION
	Adds a public boopsi class to the internal list of classes available
	for public consumption.

	You must call this function after you call [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html).

    INPUTS
	Class = pointer returned by [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html)

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
	[MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html), [FreeClass()](../Includes_and_Autodocs_3._guide/node03AF.html), [RemoveClass()](../Includes_and_Autodocs_3._guide/node03E1.html)
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

