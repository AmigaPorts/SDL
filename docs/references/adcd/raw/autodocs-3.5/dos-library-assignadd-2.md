# dos.library/AssignAdd



   NAME
	AssignAdd -- Adds a lock to an assign for multi-directory assigns (V36)

   SYNOPSIS
	success = AssignAdd(name,lock)
	D0                   D1   D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AssignAdd(STRPTR,BPTR)

   FUNCTION
	Adds a lock to an assign, making or adding to a multi-directory
	assign.  Note that this only will succeed on an assign created with
	[AssignLock()](../Includes_and_Autodocs_3._guide/node0141.html), or an assign created with [AssignLate()](../Includes_and_Autodocs_3._guide/node0140.html) which has been
	resolved (converted into a AssignLock()-assign).

	NOTE: you should not use the lock in any way after making this call
	successfully.  It becomes the part of the assign, and will be unlocked
	by the system when the assign is removed.  If you need to keep the
	lock, pass a lock from [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html) to [AssignLock()](../Includes_and_Autodocs_3._guide/node0141.html).

   INPUTS
	name - Name of device to assign lock to (without trailing ':')
	lock - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) associated with the assigned name

   RESULT
	success - Success/failure indicator.  On failure, the lock is not
		  unlocked.

   SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [AssignLock()](../Includes_and_Autodocs_3._guide/node0141.html), [AssignPath()](../Includes_and_Autodocs_3._guide/node0142.html), [AssignLate()](../Includes_and_Autodocs_3._guide/node0140.html), [DupLock()](../Includes_and_Autodocs_3._guide/node0156.html),
	[RemAssignList()](../Includes_and_Autodocs_3._guide/node01A5.html)

