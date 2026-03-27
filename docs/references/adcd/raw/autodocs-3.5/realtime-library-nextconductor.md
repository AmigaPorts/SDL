# realtime.library/NextConductor



   NAME
	NextConductor -- return the next conductor on realtime.library's
			 conductor list. (V37)

   SYNOPSIS
	conductor = NextConductor(previousConductor);
	D0			  A0

	struct [Conductor](../Includes_and_Autodocs_3._guide/node05F0.html#line57) *NextConductor(struct [Conductor](../Includes_and_Autodocs_3._guide/node05F0.html#line57) *);

   FUNCTION
	Returns the next conductor on realtime.library's conductor list. If
	previousConductor is NULL, returns the first conductor in the list.
	Returns NULL if no more conductors.

	The conductor list must be locked before calling this function. This
	is done by calling LockRealTime(RT_CONDUCTORS).

   INPUTS
	previousConductor - previous conductor or NULL to get first conductor.

   RESULTS
	conductor - next conductor on the list, or NULL if no more.

   SEE ALSO
	[FindConductor()](../Includes_and_Autodocs_3._guide/node0536.html), [LockRealTime()](../Includes_and_Autodocs_3._guide/node0538.html), [UnlockRealTime()](../Includes_and_Autodocs_3._guide/node053C.html)

