# dos.library/CreateDir



    NAME
	CreateDir -- Create a new directory

    SYNOPSIS
	lock = CreateDir( name )
	D0		  D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) CreateDir(STRPTR)

    FUNCTION
	CreateDir creates a new directory with the specified name. An error
	is returned if it fails.  Directories can only be created on
	devices which support them, e.g. disks.  CreateDir returns an
	exclusive lock on the new directory if it succeeds.

    INPUTS
	name - pointer to a null-terminated string

    RESULTS
	lock - BCPL pointer to a lock or NULL for failure.

    SEE ALSO
	[Lock()](../Includes_and_Autodocs_3._guide/node0186.html), [UnLock()](../Includes_and_Autodocs_3._guide/node01C8.html)

