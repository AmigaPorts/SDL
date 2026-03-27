# dos.library/MakeDosEntry



   NAME
	MakeDosEntry -- Creates a [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) structure (V36)

   SYNOPSIS
	newdlist = MakeDosEntry(name, type)
	D0                       D1    D2

	struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *MakeDosEntry(STRPTR, LONG)

   FUNCTION
	Create a [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) structure, including allocating a name and correctly
	null-terminating the BSTR.  It also sets the dol_Type field, and sets
	all other fields to 0.  This routine should be eliminated and replaced
	by a value passed to AllocDosObject()!

   INPUTS
	name - name for the device/volume/assign node.
	type - type of node.

   RESULT
	newdlist - The new device entry or NULL.

   SEE ALSO
	[AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html), [RemDosEntry()](../Includes_and_Autodocs_3._guide/node01A6.html), [FindDosEntry()](../Includes_and_Autodocs_3._guide/node0167.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html),
	[NextDosEntry()](../Includes_and_Autodocs_3._guide/node0195.html), [FreeDosEntry()](../Includes_and_Autodocs_3._guide/node0171.html)

