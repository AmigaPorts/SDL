# dos.library/ExamineFH



   NAME
	ExamineFH -- Gets information on an open file (V36)

   SYNOPSIS
	success = ExamineFH(fh, fib)
	D0                  D1  D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ExamineFH(BPTR, struct [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) *)

   FUNCTION
	Examines a filehandle and returns information about the file in the
	[FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60).  There are no guarantees as to whether the fib_Size
	field will reflect any changes made to the file size it was opened,
	though filesystems should attempt to provide up-to-date information
	for it.

   INPUTS
	fh  - Filehandle you wish to examine
	fib - [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60), must be longword aligned.

   RESULT
	success - Success/failure indication

   SEE ALSO
	[Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html)

