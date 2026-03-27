# dos.library/PathPart



   NAME
	PathPart -- Returns a pointer to the end of the next-to-last (V36)
		    component of a path.

   SYNOPSIS
	fileptr = PathPart( path )
	D0		     D1

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) PathPart( [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) )

   FUNCTION
	This function returns a pointer to the character after the next-to-last
	component of a path specification, which will normally be the directory
	name.  If there is only one component, it returns a pointer to the
	beginning of the string.  The only real difference between this and
	[FilePart()](../Includes_and_Autodocs_3._guide/node0164.html) is the handling of '/'.

   INPUTS
	path - pointer to an path string.  May be relative to the current
	       directory or the current disk.

   RESULT
	fileptr - pointer to the end of the next-to-last component of the path.

   EXAMPLE
	PathPart("xxx:yyy/zzz/qqq") would return a pointer to the last '/'.
	PathPart("xxx:yyy") would return a pointer to the first 'y').

   SEE ALSO
	[FilePart()](../Includes_and_Autodocs_3._guide/node0164.html), [AddPart()](../Includes_and_Autodocs_3._guide/node013C.html)

