# dos.library/UnLockDosList



   NAME
	UnLockDosList -- Unlocks the Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) (V36)

   SYNOPSIS
	UnLockDosList(flags)
			D1

	void UnLockDosList(ULONG)

   FUNCTION
	Unlocks the access on the Dos [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) [List](../Includes_and_Autodocs_3._guide/node0628.html#line19).  You MUST pass the same
	flags you used to lock the list.

   INPUTS
	flags - MUST be the same flags passed to (Attempt)LockDosList()

   SEE ALSO
	[AttemptLockDosList()](../Includes_and_Autodocs_3._guide/node0143.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html), [Permit()](../Includes_and_Autodocs_3._guide/node0224.html)

