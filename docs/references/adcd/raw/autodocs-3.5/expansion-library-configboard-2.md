# expansion.library/ConfigBoard



   NAME
	ConfigBoard - configure a board

   SYNOPSIS
	error = ConfigBoard( board, configDev )
	D0                   A0     A1

   FUNCTION
	This routine configures an expansion board.  The board
	will generally live at E_EXPANSIONBASE, but the base is
	passed as a parameter to allow future compatibility.
	The configDev parameter must be a valid configDev that
	has already had [ReadExpansionRom()](../Includes_and_Autodocs_3._guide/node0269.html) called on it.

	ConfigBoard will allocate expansion memory and place
	the board at its new address.  It will update configDev
	accordingly.  If there is not enough expansion memory
	for this board then an error will be returned.

   INPUTS
	board - the current address that the expansion board is
		responding.
	configDev - an initialized [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure, returned
		by [AllocConfigDev](../Includes_and_Autodocs_3._guide/node025F.html).

   RESULTS
	error - non-zero if there was a problem configuring this board
		(Can return EE_OK or EE_NOEXPANSION)

   SEE ALSO
	[FreeConfigDev()](../Includes_and_Autodocs_3._guide/node0263.html)

