# dos.library/Examine



    NAME
	Examine -- Examine a directory or file associated with a lock

    SYNOPSIS
	success = Examine( lock, [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) )
	D0		    D1	      D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Examine(BPTR,struct [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) *)

    FUNCTION
	Examine() fills in information in the [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) concerning the
	file or directory associated with the lock. This information
	includes the name, size, creation date and whether it is a file or
	directory.  [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) must be longword aligned.  Examine() gives
	a return code of zero if it fails.

	You may make a local copy of the [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60), as long as it is
	never passed to [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html).

    INPUTS
	lock	  - BCPL pointer to a lock
	infoBlock - pointer to a [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) (MUST be longword aligned)

    RESULTS
	success - boolean

    SPECIAL NOTE
	[FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) must be longword-aligned.  [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html) will
	allocate them correctly for you.

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [ExamineFH()](../Includes_and_Autodocs_3._guide/node015D.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html),
	[ExAll()](../Includes_and_Autodocs_3._guide/node015A.html)

