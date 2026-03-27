# dos.library/ExNext



    NAME
	ExNext -- [Examine](../Includes_and_Autodocs_3._guide/node015C.html) the next entry in a directory

    SYNOPSIS
	success = ExNext( lock, [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) )
	D0		   D1	     D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ExNext(BPTR, struct [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) *)

    FUNCTION
	This routine is passed a directory lock and a [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) that
	have been initialized by a previous call to [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), or updated
	by a previous call to ExNext().  ExNext() gives a return code of zero
	on failure.  The most common cause of failure is reaching the end
	of the list of files in the owning directory.  In this case, [IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	will return ERROR_NO_MORE_ENTRIES and a good exit is appropriate.

	So, follow these steps to examine a directory:
	1) Pass a [Lock](../Includes_and_Autodocs_3._guide/node0186.html) and a [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) to [Examine()](../Includes_and_Autodocs_3._guide/node015C.html).  The lock must
	   be on the directory you wish to examine.
	2) Pass ExNext() the same lock and [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60).
	3) Do something with the information returned in the [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60).
	   Note that the fib_DirEntryType field is positive for directories,
	   negative for files.
	4) Keep calling ExNext() until it returns FALSE.  Check [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html)
	   to ensure that the reason for failure was ERROR_NO_MORE_ENTRIES.

	Note: if you wish to recursively scan the file tree and you find
	another directory while ExNext()ing you must [Lock](../Includes_and_Autodocs_3._guide/node0186.html) that directory and
	[Examine()](../Includes_and_Autodocs_3._guide/node015C.html) it using a new [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60).  Use of the same
	[FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) to enter a directory would lose important state
	information such that it will be impossible to continue scanning
	the parent directory.  While it is permissible to [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html) and [Lock()](../Includes_and_Autodocs_3._guide/node0186.html)
	the parent directory between ExNext() calls, this is NOT recommended.
	Important state information is associated with the parent lock, so
	if it is freed between ExNext() calls this information has to be
	rebuilt on each new ExNext() call, and will significantly slow down
	directory scanning.

	It is NOT legal to [Examine()](../Includes_and_Autodocs_3._guide/node015C.html) a file, and then to ExNext() from that
	[FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60).	You may make a local copy of the [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60), as
	long as it is never passed back to the operating system.

    INPUTS
	lock - BCPL pointer to a lock originally used for the [Examine()](../Includes_and_Autodocs_3._guide/node015C.html) call
	infoBlock - pointer to a [FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) used on the previous [Examine()](../Includes_and_Autodocs_3._guide/node015C.html)
		    or ExNext() call.

    RESULTS
	success - boolean

    SPECIAL NOTE
	[FileInfoBlock](../Includes_and_Autodocs_3._guide/node05F8.html#line60) must be longword-aligned.  [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html) will
	allocate them correctly for you.

    SEE ALSO
	[Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html), [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html), [ExamineFH()](../Includes_and_Autodocs_3._guide/node015D.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html),
	[ExAll()](../Includes_and_Autodocs_3._guide/node015A.html)

