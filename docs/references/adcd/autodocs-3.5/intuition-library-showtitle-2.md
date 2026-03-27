---
title: intuition.library/ShowTitle
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-showtitle-2
functions: []
libraries: []
---

# intuition.library/ShowTitle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ShowTitle -- Set the screen title bar display mode.

    SYNOPSIS
	ShowTitle( [Screen](autodocs-3.5/include-intuition-screens-h.md), ShowIt )
		   A0      D0

	VOID ShowTitle( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, [BOOL](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	This routine sets the SHOWTITLE flag of the specified screen, and
	then coordinates the redisplay of the screen and its windows.

	The screen title bar can appear either in front of or behind
	WFLG_BACKDROP windows.  This is contrasted with the fact that
	non-WFLG_BACKDROP windows always appear in front of the screen title
	bar.  You specify whether you want the screen title bar to be in front
	of or behind the screen's WFLG_BACKDROP windows by calling this
	routine.

	The ShowIt argument should be set to either TRUE or FALSE.  If TRUE,
       the screen's title bar will be shown in front of WFLG_BACKDROP windows
.

```c
       If FALSE, the title bar will be rendered behind all windows.

       When a screen is first opened, the default setting of the SHOWTITLE
       flag is TRUE.

    INPUTS
       [Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a [Screen](autodocs-3.5/include-intuition-screens-h.md) structure
       ShowIt = Boolean TRUE or FALSE describing whether to show or hide the
           screen title bar

    RESULT
       None

    BUGS

    SEE ALSO
```
