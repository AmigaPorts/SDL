# intuition.library/LockIBase



    NAME
	LockIBase -- Invoke semaphore arbitration of [IntuitionBase](../Includes_and_Autodocs_3._guide/node061E.html#line65).

    SYNOPSIS
	[Lock](../Includes_and_Autodocs_3._guide/node0186.html) = LockIBase( LockNumber )
	D0                D0

	ULONG LockIBase( ULONG );

    FUNCTION
	Grabs Intuition internal semaphore so that caller may examine
	[IntuitionBase](../Includes_and_Autodocs_3._guide/node061E.html#line65) safely.  This function is not a magic "fix all my
	race conditions" panacea.

	The idea here is that you can get the locks Intuition needs before
	such [IntuitionBase](../Includes_and_Autodocs_3._guide/node061E.html#line65) fields as ActiveWindow and FirstScreen are
	changed, or linked lists of windows and screens are changed.

	Do Not Get Tricky with this entry point, and do not hold these locks
	for long, as all Intuition input processing will wait for you to
	surrender the lock by a call to [UnlockIBase()](../Includes_and_Autodocs_3._guide/node03FD.html).

	NOTE WELL: A call to this function MUST be paired with a subsequent
	call to [UnlockIBase()](../Includes_and_Autodocs_3._guide/node03FD.html), and soon, please.

	NOTE WELL: Do not call any Intuition functions (nor any graphics,
	layers, dos, or other high-level system function) while
	holding this lock.

    INPUTS
	A long unsigned integer, LockNumber, specifies which of Intuition's
	internal locks you want to get.  This parameter should be zero for all
	forseeable uses of this function, which will let you examine active
	fields and linked lists of screens and windows with safety.

    RESULT
	Returns another ULONG which should be passed to [UnlockIBase()](../Includes_and_Autodocs_3._guide/node03FD.html) to
	surrender the lock gotten by this call.

    BUGS
	This function must not be called while holding any other system locks
	such as layer or LayerInfo locks.

    SEE ALSO
	[UnlockIBase()](../Includes_and_Autodocs_3._guide/node03FD.html), [layers.library/LockLayerInfo()](../Includes_and_Autodocs_3._guide/node0428.html),
	[exec.library/ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html)

