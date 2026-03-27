---
title: amiga.lib/ArgInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-argint-2
functions: []
libraries: []
---

# amiga.lib/ArgInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ArgInt -- return an integer value from a ToolTypes array. (V36)

   SYNOPSIS
	value = ArgInt(tt,entry,defaultval)

	[LONG](autodocs-3.5/include-exec-types-h.md) ArgInt(UBYTE **,[STRPTR](autodocs-3.5/include-exec-types-h.md),LONG);

   FUNCTION
	This function looks in the ToolTypes array 'tt' returned
	by [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md) for 'entry' and returns the value associated
	with it. 'tt' is in standard ToolTypes format such as:

		ENTRY=Value

	The Value string is passed to atoi() and the result is returned by
	this function.

	If 'entry' is not found, the integer 'defaultval' is returned.

   INPUTS
	tt - a ToolTypes array as returned by [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md)
	entry - the entry in the ToolTypes array to search for
	defaultval - the value to return in case 'entry' is not found within
		     the ToolTypes array

   RESULTS
	value - the value associated with 'entry', or defaultval if 'entry'
		is not in the ToolTypes array

   NOTES
	This function requires that dos.library V36 or higher be opened.

   SEE ALSO
	[ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md)

