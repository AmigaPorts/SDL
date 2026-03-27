---
title: amiga.lib/ArgString
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-argstring-2
functions: []
libraries: []
---

# amiga.lib/ArgString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ArgString -- return a string pointer from a ToolTypes array. (V36)

   SYNOPSIS
	string = ArgString(tt,entry,defaultstring)

	[STRPTR](autodocs-3.5/include-exec-types-h.md) ArgString(UBYTE **,[STRPTR](autodocs-3.5/include-exec-types-h.md),STRPTR);

   FUNCTION
	This function looks in the ToolTypes array 'tt' returned
	by [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md) for 'entry' and returns the value associated
	with it. 'tt' is in standard ToolTypes format such as:

		ENTRY=Value

	This function returns a pointer to the Value string.

	If 'entry' is not found, 'defaultstring' is returned.

   INPUTS
	tt - a ToolTypes array as returned by [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md)
	entry - the entry in the ToolTypes array to search for
	defaultstring - the value to return in case 'entry' is not found within
		        the ToolTypes array

   RESULTS
	value - the value associated with 'entry', or defaultstring if 'entry'
		is not in the ToolTypes array

   SEE ALSO
	[ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md)

