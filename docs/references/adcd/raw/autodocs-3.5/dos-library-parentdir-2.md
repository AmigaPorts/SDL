# dos.library/ParentDir



    NAME
	ParentDir -- Obtain the parent of a directory or file

    SYNOPSIS
	newlock = ParentDir( lock )
	D0		     D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) ParentDir(BPTR)

    FUNCTION
	The argument 'lock' is associated with a given file or directory.
	ParentDir() returns 'newlock' which is associated the parent
	directory of 'lock'.

	Taking the ParentDir() of the root of the current filing system
	returns a NULL (0) lock.  Note this 0 lock represents the root of
	file system that you booted from (which is, in effect, the parent
	of all other file system roots.)

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	newlock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [ParentOfFH()](../Includes_and_Autodocs_3._guide/node019A.html), [DupLockFromFH()](../Includes_and_Autodocs_3._guide/node0157.html)

