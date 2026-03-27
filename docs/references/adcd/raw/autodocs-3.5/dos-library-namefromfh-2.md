# dos.library/NameFromFH



   NAME
	NameFromFH -- Get the name of an open filehandle (V36)

   SYNOPSIS
	success = NameFromFH(fh, buffer, len)
	D0                   D1    D2    D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) NameFromFH(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), LONG)

   FUNCTION
	Returns a fully qualified path for the filehandle.  This routine is
	guaranteed not to write more than len characters into the buffer.  The
	name will be null-terminated.  See [NameFromLock()](../Includes_and_Autodocs_3._guide/node0193.html) for more information.

	Note: Older filesystems that don't support [ExamineFH()](../Includes_and_Autodocs_3._guide/node015D.html) will cause
	NameFromFH() to fail with ERROR_ACTION_NOT_SUPPORTED.

   INPUTS
	fh     - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) of object to be examined.
	buffer - Buffer to store name.
	len    - Length of buffer.

   RESULT
	success - Success/failure indicator.

   SEE ALSO
	[NameFromLock()](../Includes_and_Autodocs_3._guide/node0193.html), [ExamineFH()](../Includes_and_Autodocs_3._guide/node015D.html)

