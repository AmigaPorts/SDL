---
title: intuition.library/WBenchToFront
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-wbenchtofront-2
functions: [ScreenToBack, WBenchToBack, WBenchToFront]
libraries: [intuition.library]
---

# intuition.library/WBenchToFront

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME 
	WBenchToFront -- Bring the Workbench screen in front of all screens.

    SYNOPSIS 
	Success = WBenchToFront()
	D0

	[BOOL](autodocs-3.5/include-exec-types-h.md) WBenchToFront( VOID );

    FUNCTION 
	Causes the Workbench [Screen](autodocs-3.5/include-intuition-screens-h.md), if it's currently opened, to come to
	the foreground.  This does not 'move' the screen up or down, instead
	only affects the depth-arrangement of the screen.

    INPUTS 
	None

    RESULT 
	If the Workbench screen was opened, this function returns TRUE,
	otherwise it returns FALSE.

    BUGS 

    SEE ALSO 
	[WBenchToBack()](autodocs-3.5/intuition-library-wbenchtoback-2.md), [ScreenToBack()](autodocs-3.5/intuition-library-screentoback-2.md)

---

## See Also

- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
- [WBenchToBack — intuition.library](../autodocs/intuition.library.md#wbenchtoback)
- [WBenchToFront — intuition.library](../autodocs/intuition.library.md#wbenchtofront)
