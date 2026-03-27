# expansion.library/AllocConfigDev



   NAME
	AllocConfigDev - allocate a [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure

   SYNOPSIS
	configDev = AllocConfigDev()
	D0

   FUNCTION
	This routine returns the address of a [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure.
	It is provided so new fields can be added to the structure
	without breaking old, existing code.  The structure is cleared
	when it is returned to the user.

   INPUTS

   RESULTS
	configDev - either a valid [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure or NULL.

   EXCEPTIONS

   SEE ALSO
	[FreeConfigDev()](../Includes_and_Autodocs_3._guide/node0263.html)

   BUGS

