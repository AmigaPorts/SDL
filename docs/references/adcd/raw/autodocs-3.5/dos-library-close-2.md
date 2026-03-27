# dos.library/Close



    NAME
	Close -- Close an open file

    SYNOPSIS
	success = Close( file )
	   D0             D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Close(BPTR)

    FUNCTION
	The file specified by the file handle is closed. You must close all
	files you explicitly opened, but you must not close inherited file
	handles that are passed to you (each filehandle must be closed once
	and ONLY once).  If Close() fails, the file handle is still
	deallocated and should not be used.

    INPUTS
	file - BCPL pointer to a file handle

    RESULTS
	success - returns if Close() succeeded.  Note that it might fail
		  depending on buffering and whatever IO must be done to
		  close a file being written to.  NOTE: this return value
		  did not exist before V36!

    SEE ALSO
	[Open()](../Includes_and_Autodocs_3._guide/node0196.html), [OpenFromLock()](../Includes_and_Autodocs_3._guide/node0197.html)

