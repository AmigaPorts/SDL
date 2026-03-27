# dos.library/SetOwner



    NAME
	SetOwner -- Set owner information for a file or directory (V39)

    SYNOPSIS
	success = SetOwner( name, owner_info )
	D0		     D1       D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetOwner (STRPTR, LONG)

    FUNCTION
	SetOwner() sets the owner information for the file or directory.
	This value is a 32-bit value that is normally split into 16 bits
	of owner user id (bits 31-16), and 16 bits of owner group id (bits
	15-0).  However, other than returning them as shown by Examine()/
	[ExNext()/ExAll()](../Includes_and_Autodocs_3._guide/node015A.html), the filesystem take no interest in the values.
	These are primarily for use by networking software (clients and
	hosts), in conjunction with the FIBF_OTR_xxx and FIBF_GRP_xxx
	protection bits.

	This entrypoint did not exist in V36, so you must open at least V37
	dos.library to use it.  V37 dos.library will return FALSE to this
	call.

    INPUTS
	name	   - pointer to a null-terminated string
	owner_info - owner uid (31:16) and group id (15:0)

    RESULTS
	success - boolean

    SEE ALSO
	SetProtect(), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [ExAll()](../Includes_and_Autodocs_3._guide/node015A.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html)

