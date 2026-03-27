---
title: expansion.library/ConfigBoard
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-configboard-2
functions: []
libraries: []
---

# expansion.library/ConfigBoard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
	has already had [ReadExpansionRom()](autodocs-3.5/expansion-library-readexpansionrom-2.md) called on it.

	ConfigBoard will allocate expansion memory and place
	the board at its new address.  It will update configDev
	accordingly.  If there is not enough expansion memory
	for this board then an error will be returned.

   INPUTS
	board - the current address that the expansion board is
		responding.
	configDev - an initialized [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure, returned
		by [AllocConfigDev](autodocs-3.5/expansion-library-allocconfigdev-2.md).

   RESULTS
	error - non-zero if there was a problem configuring this board
		(Can return EE_OK or EE_NOEXPANSION)

   SEE ALSO
	[FreeConfigDev()](autodocs-3.5/expansion-library-freeconfigdev-2.md)

