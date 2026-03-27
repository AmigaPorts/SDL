---
title: intuition.library/SetMouseQueue
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setmousequeue-2
functions: [OpenWindow]
libraries: [intuition.library]
---

# intuition.library/SetMouseQueue

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetMouseQueue -- Change limit on pending mouse messages. (V36)

    SYNOPSIS
	oldQueueLength = SetMouseQueue( [Window](autodocs-3.5/include-intuition-intuition-h.md), QueueLength )
	D0                              A0      D0

	[LONG](autodocs-3.5/include-exec-types-h.md) SetMouseQueue( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Changes the number of mouse messages that Intuition will allow
	to be outstanding for your window.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = your window
	QueueLength = the new value of outstanding mouse movement messages
	  you wish to allow.

    RESULT
	-1 if 'Window' is not known
	Otherwise the previous value of the queue limit.
	The corresponding function for changing the repeat key
	queue limit is not yet implemented.

    BUGS

    SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
