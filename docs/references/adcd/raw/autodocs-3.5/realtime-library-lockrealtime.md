# realtime.library/LockRealTime



   NAME
	LockRealTime -- prevent other tasks from changing internal structures.
			(V37)

   SYNOPSIS
	lockHandle = LockRealTime(lockType);
	D0                        D0

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) LockRealTime(ULONG);

   FUNCTION
	This routine will lock the internal sempahores in the RealTime library.
	If they are already locked by another task, this routine will wait
	until they are free.

   INPUTS
	lockType - the internal list to lock. Only RT_CONDUCTORS is
		   currently defined.

   RESULT
	handle - if lockType is valid, returns a value that must be passed
		 later to [UnlockRealTime()](../Includes_and_Autodocs_3._guide/node053C.html) to unlock the list. Returns NULL
		 if passed an invalid lock type.

   SEE ALSO
	[UnlockRealTime()](../Includes_and_Autodocs_3._guide/node053C.html)

