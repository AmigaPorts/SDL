# dos.library/ChangeMode



   NAME
	ChangeMode - Change the current mode of a lock or filehandle (V36)

   SYNOPSIS
	success = ChangeMode(type, object, newmode)
	D0                    D1     D2      D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ChangeMode(ULONG, [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129), ULONG)

   FUNCTION
	This allows you to attempt to change the mode in use by a lock or
	filehandle.  For example, you could attempt to turn a shared lock
	into an exclusive lock.  The handler may well reject this request.
	Warning: if you use the wrong type for the object, the system may
	crash.

   INPUTS
	type    - Either CHANGE_FH or CHANGE_LOCK
	object  - A lock or filehandle
	newmode - The new mode you want

   RESULT
	success - Boolean

   BUGS
	Did not work in 2.02 or before (V36).  Works in V37.  In the
	earlier versions, it can crash the machine.

   SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [Open()](../Includes_and_Autodocs_3._guide/node0196.html)

