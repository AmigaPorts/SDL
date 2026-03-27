# dos.library/ParentOfFH



   NAME
	ParentOfFH -- returns a lock on the parent directory of a file (V36)

   SYNOPSIS
	lock = ParentOfFH(fh)
	D0               D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) ParentOfFH(BPTR)

   FUNCTION
	Returns a shared lock on the parent directory of the filehandle.

   INPUTS
	fh   - Filehandle you want the parent of.

   RESULT
	lock - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on parent directory of the filehandle or NULL for failure.

   SEE ALSO
	Parent(), [Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html) [DupLockFromFH()](../Includes_and_Autodocs_3._guide/node0157.html)

