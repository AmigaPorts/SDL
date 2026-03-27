# dos.library/SetFileDate



   NAME
	SetFileDate -- Sets the modification date for a file or dir (V36)

   SYNOPSIS
	success = SetFileDate(name, date)
	D0                     D1    D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetFileDate(STRPTR, struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *)

   FUNCTION
	Sets the file date for a file or directory.  Note that for the Old
	File System and the Fast File System, the date of the root directory
	cannot be set.  Other filesystems may not support setting the date
	for all files/directories.

   INPUTS
	name - Name of object
	date - New modification date

   RESULT
	success - Success/failure indication

   SEE ALSO
	[DateStamp()](../Includes_and_Autodocs_3._guide/node014F.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html)

