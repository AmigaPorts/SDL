# realtime.library/UnlockRealTime



   NAME
	UnlockRealTime -- unlock internal lists. (V37)

   SYNOPSIS
	UnlockRealTime(lockHandle);
	               A0

	VOID UnlockRealTime(APTR);

   FUNCTION
	Undoes the effects of [LockRealTime()](../Includes_and_Autodocs_3._guide/node0538.html).

   INPUTS
	lockHandle - value returned by [LockRealTime()](../Includes_and_Autodocs_3._guide/node0538.html). May be NULL.

   SEE ALSO
	[LockRealTime()](../Includes_and_Autodocs_3._guide/node0538.html)

