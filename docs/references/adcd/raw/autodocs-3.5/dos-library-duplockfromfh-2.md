# dos.library/DupLockFromFH



   NAME
	DupLockFromFH -- Gets a lock on an open file (V36)

   SYNOPSIS
	lock = DupLockFromFH(fh)
	D0                   D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) DupLockFromFH(BPTR)

   FUNCTION
	Obtain a lock on the object associated with fh.  Only works if the
	file was opened using a non-exclusive mode.  Other restrictions may be
	placed on success by the filesystem.

   INPUTS
	fh   - Opened file for which to obtain the lock

   RESULT
	lock - Obtained lock or NULL for failure

   SEE ALSO
	[DupLock()](../Includes_and_Autodocs_3._guide/node0156.html), [Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html)

