---
title: dos.library/Delay
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-delay-2
functions: [Delay]
libraries: [dos.library]
---

# dos.library/Delay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Delay -- Delay a process for a specified time

    SYNOPSIS
	Delay( ticks )
	       D1

	void Delay(ULONG)

    FUNCTION
	The argument 'ticks' specifies how many ticks (50 per second) to
	wait before returning control.

    INPUTS
	ticks - integer

    BUGS
	Due to a bug in the timer.device in V1.2/V1.3, specifying a timeout
	of zero for Delay() can cause the unreliable timer & floppy disk
	operation.  This is fixed in V36 and later.


    SEE ALSO

---

## See Also

- [Delay — dos.library](../autodocs/dos.library.md#delay)
