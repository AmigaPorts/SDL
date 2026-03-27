# dos.library/Info



    NAME
	Info -- Returns information about the disk

    SYNOPSIS
	success = Info( lock, parameterBlock )
	D0		D1    D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Info(BPTR, struct [InfoData](../Includes_and_Autodocs_3._guide/node05F8.html#line146) *)

    FUNCTION
	Info() can be used to find information about any disk in use.
	'lock' refers to the disk, or any file on the disk. The parameter
	block is returned with information about the size of the disk,
	number of free blocks and any soft errors.

    INPUTS
	lock	       - BCPL pointer to a lock
	parameterBlock - pointer to an [InfoData](../Includes_and_Autodocs_3._guide/node05F8.html#line146) structure
			 (longword aligned)

    RESULTS
	success - boolean

    SPECIAL NOTE:
	Note that [InfoData](../Includes_and_Autodocs_3._guide/node05F8.html#line146) structure must be longword aligned.

