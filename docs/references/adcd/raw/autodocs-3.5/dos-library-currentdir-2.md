# dos.library/CurrentDir



    NAME
	CurrentDir -- Make a directory lock the current directory

    SYNOPSIS
	oldLock = CurrentDir( lock )
	D0		      D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) CurrentDir(BPTR)

    FUNCTION
	CurrentDir() causes a directory associated with a lock to be made
	the current directory.	The old current directory lock is returned.

	A value of zero is a valid result here, this 0 lock represents the
	root of file system that you booted from.

	Any call that has to [Open()](../Includes_and_Autodocs_3._guide/node0196.html) or [Lock()](../Includes_and_Autodocs_3._guide/node0186.html) files (etc) requires that
	the current directory be a valid lock or 0.

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	oldLock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html)

