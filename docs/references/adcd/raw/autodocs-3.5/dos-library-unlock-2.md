# dos.library/UnLock



    NAME
	UnLock -- Unlock a directory or file

    SYNOPSIS
	UnLock( lock )
		D1

	void UnLock(BPTR)

    FUNCTION
	The filing system lock (obtained from [Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html), or
	[CreateDir()](../Includes_and_Autodocs_3._guide/node014B.html)) is removed and deallocated.

    INPUTS
	lock - BCPL pointer to a lock

    NOTE
	passing zero to UnLock() is harmless

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html), [ParentOfFH()](../Includes_and_Autodocs_3._guide/node019A.html), [DupLockFromFH()](../Includes_and_Autodocs_3._guide/node0157.html)

