# dos.library/FindCliProc



   NAME
	FindCliProc -- returns a pointer to the requested CLI process (V36)

   SYNOPSIS
	proc = FindCliProc(num)
	D0             D1

	struct [Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) *FindCliProc(ULONG)

   FUNCTION
	This routine returns a pointer to the CLI process associated with the
	given CLI number.  If the process isn't an active CLI process, NULL is
	returned.  NOTE: should normally be called inside a [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html), if you
	must use this function at all.

   INPUTS
	num  - [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) number of CLI process (range 1-N)

   RESULT
	proc - Pointer to given CLI process

   SEE ALSO
	[Cli()](../Includes_and_Autodocs_3._guide/node0146.html), [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html), [MaxCli()](../Includes_and_Autodocs_3._guide/node0191.html)

