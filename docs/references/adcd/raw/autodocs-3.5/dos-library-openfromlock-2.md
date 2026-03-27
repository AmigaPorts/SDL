# dos.library/OpenFromLock



   NAME
	OpenFromLock -- Opens a file you have a lock on (V36)

   SYNOPSIS
	fh = OpenFromLock(lock)
	D0                 D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) OpenFromLock(BPTR)

   FUNCTION
	Given a lock, this routine performs an open on that lock.  If the open
	succeeds, the lock is (effectively) relinquished, and should not be
	UnLock()ed or used.  If the open fails, the lock is still usable.
	The lock associated with the file internally is of the same access
	mode as the lock you gave up - shared is similar to MODE_OLDFILE,
	exclusive is similar to MODE_NEWFILE.

   INPUTS
	lock - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on object to be opened.

   RESULT
	fh   - Newly opened file handle or NULL for failure

   BUGS
	In the original V36 autodocs, this was shown (incorrectly) as
	taking a Mode parameter as well.  The prototypes and pragmas were
	also wrong.

   SEE ALSO
	[Open()](../Includes_and_Autodocs_3._guide/node0196.html), [Close()](../Includes_and_Autodocs_3._guide/node0149.html), [Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html)

