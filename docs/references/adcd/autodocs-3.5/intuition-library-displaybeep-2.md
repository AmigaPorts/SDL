---
title: intuition.library/DisplayBeep
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-displaybeep-2
functions: [DisplayBeep, SetFunction]
libraries: [exec.library, intuition.library]
---

# intuition.library/DisplayBeep

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DisplayBeep -- Flash the video display.

    SYNOPSIS
	DisplayBeep( [Screen](autodocs-3.5/include-intuition-screens-h.md) )
		     A0

	VOID DisplayBeep( struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * );

    FUNCTION
	"Beeps" the video display by flashing the background color of the
	specified screen.  If the screen argument is NULL, every screen
	in the display will be beeped.  Flashing everyone's screen is not
	a polite thing to do, so this should be reserved for dire
	circumstances.

	The reason such a routine is supported is because the Amiga has
	no internal bell or speaker.  When the user needs to know of
	an event that is not serious enough to require the use of a requester,
	the DisplayBeep() function may be called.

	New for V36:  Intuition now calls DisplayBeep through the
	external library vector.  This means that if you call [SetFunction()](autodocs-3.5/exec-library-setfunction-2.md)
	to replace DisplayBeep with an audible beep, for example, then
	your change will affect even Intuition's calls to DisplayBeep.

    INPUTS
	[Screen](autodocs-3.5/include-intuition-screens-h.md) = pointer to a screen.  If NULL, every screen in the display
           will be flashed

    RESULT
	None

    NOTES
	Since this function changes color zero of the affected screen(s),
	surprising results could occur if the screen's owner reading
	colors or perhaps cycling them.


    BUGS

    SEE ALSO

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
