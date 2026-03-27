# dos.library/FilePart



   NAME
	FilePart -- Returns the last component of a path (V36)

   SYNOPSIS
	fileptr = FilePart( path )
	D0		     D1

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) FilePart( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) )

   FUNCTION
	This function returns a pointer to the last component of a string path
	specification, which will normally be the file name.  If there is only
	one component, it returns a pointer to the beginning of the string.

   INPUTS
	path - pointer to an path string.  May be relative to the current
	       directory or the current disk.

   RESULT
	fileptr - pointer to the last component of the path.

   EXAMPLE
	FilePart("xxx:yyy/zzz/qqq") would return a pointer to the first 'q'.
	FilePart("xxx:yyy") would return a pointer to the first 'y').

   SEE ALSO
	[PathPart()](../Includes_and_Autodocs_3._guide/node019D.html), [AddPart()](../Includes_and_Autodocs_3._guide/node013C.html)

