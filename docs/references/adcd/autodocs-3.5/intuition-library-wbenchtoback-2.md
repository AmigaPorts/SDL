---
title: intuition.library/WBenchToBack
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-wbenchtoback-2
functions: [ScreenToFront, WBenchToBack, WBenchToFront]
libraries: [intuition.library]
---

# intuition.library/WBenchToBack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME 
	WBenchToBack -- Send the Workbench screen in back of all screens.

    SYNOPSIS 
	Success = WBenchToBack()
	D0

	[BOOL](autodocs-3.5/include-exec-types-h.md) WBenchToBack( VOID );

    FUNCTION 
	Causes the Workbench screen, if it's currently opened, to go behind
	all other screens.  This does not 'move' the screen up or down,
	instead only affects the depth-arrangement of the screens.

    INPUTS 
	None

    RESULT 
	If the Workbench screen was opened, this function returns TRUE,
	otherwise it returns FALSE.

    BUGS 

    SEE ALSO 
	[WBenchToFront()](autodocs-3.5/intuition-library-wbenchtofront-2.md), [ScreenToFront()](autodocs-3.5/intuition-library-screentofront-2.md)

---

## See Also

- [ScreenToFront — intuition.library](../autodocs/intuition.library.md#screentofront)
- [WBenchToBack — intuition.library](../autodocs/intuition.library.md#wbenchtoback)
- [WBenchToFront — intuition.library](../autodocs/intuition.library.md#wbenchtofront)
