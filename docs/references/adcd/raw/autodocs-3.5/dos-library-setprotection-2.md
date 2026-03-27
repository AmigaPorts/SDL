# dos.library/SetProtection



    NAME
	SetProtection -- Set protection for a file or directory

    SYNOPSIS
	success = SetProtection( name, mask )
	D0			 D1    D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetProtection (STRPTR, LONG)

    FUNCTION
	SetProtection() sets the protection attributes on a file or
	directory.  See [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html) for a listing of protection bits.

	Before V36, the ROM filesystem didn't respect the [Read](../Includes_and_Autodocs_3._guide/node01A0.html) and [Write](../Includes_and_Autodocs_3._guide/node01D1.html)
	bits.  In V36 or later and in the FFS, the [Read](../Includes_and_Autodocs_3._guide/node01A0.html) and [Write](../Includes_and_Autodocs_3._guide/node01D1.html)
	bits are respected.

	The archive bit should be cleared by the filesystem whenever the file
	is changed.  Backup utilities will generally set the bit after
	backing up each file.

	The V36 Shell looks at the execute bit, and will refuse to execute
	a file if it is set.

	Other bits will be defined in the [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html) include files.  Rather
	than referring to bits by number you should use the definitions in
	[<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html).

    INPUTS
	name - pointer to a null-terminated string
	mask - the protection mask required

    RESULTS
	success - boolean

    SEE ALSO
	[SetComment()](../Includes_and_Autodocs_3._guide/node01B2.html), [Examine()](../Includes_and_Autodocs_3._guide/node015C.html), [ExNext()](../Includes_and_Autodocs_3._guide/node0160.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html)

