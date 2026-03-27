# dos.library/FreeDosEntry



   NAME
	FreeDosEntry -- Frees an entry created by [MakeDosEntry](../Includes_and_Autodocs_3._guide/node018A.html) (V36)

   SYNOPSIS
	FreeDosEntry(dlist)
	               D1

	void FreeDosEntry(struct [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) *)

   FUNCTION
	Frees an entry created by [MakeDosEntry()](../Includes_and_Autodocs_3._guide/node018A.html).  This routine should be
	eliminated and replaced by a value passed to FreeDosObject()!

   INPUTS
	dlist - [DosList](../Includes_and_Autodocs_3._guide/node05D9.html#line371) to free.

   SEE ALSO
	[AddDosEntry()](../Includes_and_Autodocs_3._guide/node013B.html), [RemDosEntry()](../Includes_and_Autodocs_3._guide/node01A6.html), [FindDosEntry()](../Includes_and_Autodocs_3._guide/node0167.html), [LockDosList()](../Includes_and_Autodocs_3._guide/node0187.html),
	[NextDosEntry()](../Includes_and_Autodocs_3._guide/node0195.html), [MakeDosEntry()](../Includes_and_Autodocs_3._guide/node018A.html)

