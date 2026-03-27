# dos.library/RemAssignList



   NAME
	RemAssignList -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) an entry from a multi-dir assign (V36)

   SYNOPSIS
	success = RemAssignList(name,lock)
	D0                  	 D1   D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemAssignList(STRPTR,BPTR)

   FUNCTION
	Removes an entry from a multi-directory assign.  The entry removed is
	the first one for which [SameLock](../Includes_and_Autodocs_3._guide/node01AC.html) with 'lock' returns that they are on
	the same object.  The lock for the entry in the list is unlocked (not
	the entry passed in).

   INPUTS
	name - Name of device to remove lock from (without trailing ':')
	lock - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) associated with the object to remove from the list

   RESULT
	success - Success/failure indicator.

   BUGS
	In V36 through V39.23 dos, it would fail to remove the first lock
	in the assign.  Fixed in V39.24 dos (after the V39.106 kickstart).

   SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [AssignLock()](../Includes_and_Autodocs_3._guide/node0141.html), [AssignPath()](../Includes_and_Autodocs_3._guide/node0142.html), [AssignLate()](../Includes_and_Autodocs_3._guide/node0140.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html),
	[AssignAdd()](../Includes_and_Autodocs_3._guide/node013F.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html)

