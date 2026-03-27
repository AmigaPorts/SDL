# dos.library/RemDosEntry



   NAME
	RemDosEntry -- Removes a Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) entry from it's list (V36)

   SYNOPSIS
	success = RemDosEntry(dlist)
	D0                     D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemDosEntry(struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *)

   FUNCTION
	This removes an entry from the Dos [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) list.  The memory associated
	with the entry is NOT freed.  NOTE: you must have locked the Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19)
	with the appropriate flags before calling this routine.  Handler
	writers should see the [AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html) caveats about locking and use
	a similar workaround to avoid deadlocks.

   INPUTS
	dlist   - [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) list entry to be removed.

   RESULT
	success - Success/failure indicator

   SEE ALSO
	[AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html), [FindDosEntry()](../Includes_and_Autodocs_3._guide/node0167.html), [NextDosEntry()](../Includes_and_Autodocs_3._guide/node0195.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html),
	[MakeDosEntry()](../Includes_and_Autodocs_3._guide/node018A.html), [FreeDosEntry()](../Includes_and_Autodocs_3._guide/node0171.html)

