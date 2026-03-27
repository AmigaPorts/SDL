# dos.library/AttemptLockDosList



   NAME
	AttemptLockDosList -- Attempt to lock the Dos Lists for use (V36)

   SYNOPSIS
	dlist = AttemptLockDosList(flags)
	D0			    D1

	struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *AttemptLockDosList(ULONG)

   FUNCTION
	Locks the dos device list in preparation to walk the list.  If the
	list is 'busy' then this routine will return NULL.  See [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html)
	for more information.

   INPUTS
	flags - Flags stating which types of nodes you want to lock.

   RESULT
	dlist - Pointer to the beginning of the list or NULL.  Not a valid
		node!

   BUGS
	In V36 through V39.23 dos, this would return NULL or 0x00000001 for
	failure.  Fixed in V39.24 dos (after kickstart 39.106).

   SEE ALSO
	[LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html), [UnLockDosList()](../Includes_and_Autodocs_3._guide/node01C9.html), [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html), [NextDosEntry()](../Includes_and_Autodocs_3._guide/node0195.html)

