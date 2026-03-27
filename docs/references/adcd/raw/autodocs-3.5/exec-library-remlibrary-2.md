# exec.library/RemLibrary



   NAME
	RemLibrary -- remove a library from the system

   SYNOPSIS
	RemLibrary(library)
	           A1

	void RemLibrary(struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *);

   FUNCTION
	This function calls the library's EXPUNGE vector, which requests
	that a library delete itself.  The library may refuse to do this if
	it is busy or currently open. This is not typically called by user
	code.

	There are certain, limited circumstances where it may be
	appropriate to attempt to specifically flush a certain [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33).
	Example:

	 /* Attempts to flush the named library out of memory. */
	 #include [<exec/types.h>](../Includes_and_Autodocs_3._guide/node0654.html)
	 #include [<exec/execbase.h>](../Includes_and_Autodocs_3._guide/node0609.html)

	 void FlushLibrary(name)
	 [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) name;
	 {
	 struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *result;

	    Forbid();
	    if(result=(struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *)FindName(&SysBase->LibList,name))
		RemLibrary(result);
	    Permit();
	 }

   INPUTS
	library - pointer to a library node structure

