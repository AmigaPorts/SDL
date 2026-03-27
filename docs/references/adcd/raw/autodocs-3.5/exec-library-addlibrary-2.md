# exec.library/AddLibrary



   NAME
	AddLibrary -- add a library to the system

   SYNOPSIS
	AddLibrary(library)
		   A1

	void AddLibrary(struct [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) *);

   FUNCTION
	This function adds a new library to the system, making it available
	to other programs.  The library should be ready to be opened at
	this time.  It will be added to the system library name list, and
	the checksum on the library entries will be calculated.

   INPUTS
	library - pointer to a properly initialized library structure

   SEE ALSO
	[RemLibrary()](../Includes_and_Autodocs_3._guide/node022D.html), [CloseLibrary()](../Includes_and_Autodocs_3._guide/node01F7.html), [OpenLibrary()](../Includes_and_Autodocs_3._guide/node0222.html), [MakeLibrary()](../Includes_and_Autodocs_3._guide/node021B.html)

