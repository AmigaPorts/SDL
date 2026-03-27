# realtime.library/FindConductor



   NAME
	FindConductor -- find a conductor by name. (V37)

   SYNOPSIS
	conductor = FindConductor(name);
	D0			  A0

	struct [Conductor](../Includes_and_Autodocs_3._guide/node05F0.html#line57) *FindConductor(STRPTR);

   FUNCTION
	Returns the conductor with the given name or NULL if not found.

	The conductor list must be locked before calling this function. This
	is done by calling LockRealTime(RT_CONDUCTORS).

   INPUTS
	name - name of conductor to find.

   RESULTS
	conductor - pointer to a [Conductor](../Includes_and_Autodocs_3._guide/node05F0.html#line57) structure, or NULL if not found.

   SEE ALSO
	[NextConductor()](../Includes_and_Autodocs_3._guide/node0539.html), [LockRealTime()](../Includes_and_Autodocs_3._guide/node0538.html), [UnlockRealTime()](../Includes_and_Autodocs_3._guide/node053C.html)

