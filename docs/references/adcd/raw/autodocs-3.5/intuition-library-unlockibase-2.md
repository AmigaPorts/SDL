# intuition.library/UnlockIBase



    NAME
	UnlockIBase -- Surrender an Intuition lock gotten by [LockIBase()](../Includes_and_Autodocs_3._guide/node03C0.html).

    SYNOPSIS
	UnlockIBase( [Lock](../Includes_and_Autodocs_3._guide/node0186.html) )
		     A0

	VOID UnlockIBase( ULONG );


    FUNCTION
	Surrenders lock gotten by [LockIBase()](../Includes_and_Autodocs_3._guide/node03C0.html).

	Calling this function when you do not own the specified lock will
	immediately crash the system.

    INPUTS
	The value returned by [LockIBase()](../Includes_and_Autodocs_3._guide/node03C0.html) should be passed to this function,
	to specify which internal lock is to be freed.

	Note that the parameter is passed in A0, not D0, for historical reasons.

    RESULT
	None

    BUGS

    SEE ALSO
	[LockIBase()](../Includes_and_Autodocs_3._guide/node03C0.html)

