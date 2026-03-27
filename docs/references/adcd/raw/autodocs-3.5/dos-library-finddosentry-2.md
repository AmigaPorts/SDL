# dos.library/FindDosEntry



   NAME
	FindDosEntry -- Finds a specific Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) entry (V36)

   SYNOPSIS
	newdlist = FindDosEntry(dlist,name,flags)
	D0                       D1    D2   D3

	struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *FindDosEntry(struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),ULONG)

   FUNCTION
	Locates an entry on the device list.  Starts with the entry dlist.
	NOTE: must be called with the device list locked, no references may be
	made to dlist after unlocking.

   INPUTS
	dlist    - The device entry to start with.
	name     - Name of device entry (without ':') to locate.
	flags    - Search control flags.  Use the flags you passed to
		   [LockDosList](../Includes_and_Autodocs_3._guide/node0187.html), or a subset of them.  LDF_READ/LDF_WRITE are
		   not required for this call.

   RESULT
	newdlist - The device entry or NULL

   SEE ALSO
	[AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html), [RemDosEntry()](../Includes_and_Autodocs_3._guide/node01A6.html), [NextDosEntry()](../Includes_and_Autodocs_3._guide/node0195.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html),
	[MakeDosEntry()](../Includes_and_Autodocs_3._guide/node018A.html), [FreeDosEntry()](../Includes_and_Autodocs_3._guide/node0171.html)

