# exec.library/CloseLibrary



   NAME
	CloseLibrary -- conclude access to a library

   SYNOPSIS
	CloseLibrary(library)
		     A1

	void CloseLibrary(struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *);

   FUNCTION
	This function informs the system that access to the given library
	has been concluded.  The user must not reference the library or any
	function in the library after this close.

	Starting with V36, it is safe to pass a NULL instead of
	a library pointer.

   INPUTS
	library - pointer to a library node

   NOTE
	[Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) writers must pass a SegList pointer or NULL back from their
	open point.  This value is used by the system, and not visible as
	a return code from CloseLibrary.

   SEE ALSO
	[OpenLibrary()](../Includes_and_Autodocs_3._guide/node0222.html)

