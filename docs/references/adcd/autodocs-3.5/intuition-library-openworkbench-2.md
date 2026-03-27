---
title: intuition.library/OpenWorkBench
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-openworkbench-2
functions: [OpenWorkBench]
libraries: [intuition.library]
---

# intuition.library/OpenWorkBench

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME 
	OpenWorkBench -- [Open](autodocs-3.5/dos-library-open-2.md) the Workbench screen.

    SYNOPSIS 
	WBScreen = OpenWorkBench()
	D0

	ULONG OpenWorkBench( VOID );

    FUNCTION 
	This routine attempts to reopen the Workbench.  The actions taken are:
	    - general good stuff and nice things, and then return a non-null
	      pointer to the Workbench screen.
	    - find that something has gone wrong, and return NULL

	The return value, if not NULL, is indeed the address of the Workbench
	screen, although you should not use it as such.  This is because the
	Workbench may be closed by other programs, which can invalidate
	the address at any time.  We suggest that you regard the return
	value as a ULONG indication that the routine has succeeded, if
	you pay any attention to it at all.

    INPUTS 
	None

    RESULT 
	non-zero if Workbench screen opened successfully, or was already
		opened
	zero if anything went wrong and the Workbench screen isn't out there

    BUGS 
	The name of this routine is spelled wrong: it ought to have been
	OpenWorkbench().


    SEE ALSO 

---

## See Also

- [OpenWorkBench — intuition.library](../autodocs/intuition.library.md#openworkbench)
