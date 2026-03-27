# dos.library/DupLock



    NAME
	DupLock -- Duplicate a lock

    SYNOPSIS
	lock = DupLock( lock )
	D0		D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) DupLock(BPTR)

    FUNCTION
	DupLock() is passed a shared filing system lock.  This is the ONLY
	way to obtain a duplicate of a lock... simply copying is not
	allowed.

	Another lock to the same object is then returned.  It is not
	possible to create a copy of a exclusive lock.

	A zero return indicates failure.

    INPUTS
	lock - BCPL pointer to a lock

    RESULTS
	newLock - BCPL pointer to a lock

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [DupLockFromFH()](../Includes_and_Autodocs_3._guide/node0157.html), [ParentOfFH()](../Includes_and_Autodocs_3._guide/node019A.html)

