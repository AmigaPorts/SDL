# dos.library/NextDosEntry



   NAME
	NextDosEntry -- Get the next Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) entry (V36)

   SYNOPSIS
	newdlist = NextDosEntry(dlist,flags)
	D0                       D1    D2

	struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *NextDosEntry(struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *,ULONG)

   FUNCTION
	Find the next Dos [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) entry of the right type.  You MUST have locked
	the types you're looking for.  Returns NULL if there are no more of
	that type in the list.

   INPUTS
	dlist    - The current device entry.
	flags	 - What type of entries to look for.

   RESULT
	newdlist - The next device entry of the right type or NULL.

   SEE ALSO
	[AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html), [RemDosEntry()](../Includes_and_Autodocs_3._guide/node01A6.html), [FindDosEntry()](../Includes_and_Autodocs_3._guide/node0167.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html),
	[MakeDosEntry()](../Includes_and_Autodocs_3._guide/node018A.html), [FreeDosEntry()](../Includes_and_Autodocs_3._guide/node0171.html)

