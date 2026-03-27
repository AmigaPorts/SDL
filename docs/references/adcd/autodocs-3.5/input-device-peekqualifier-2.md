---
title: input.device/PeekQualifier
manual: autodocs-3.5
chapter: autodocs-3.5
section: input-device-peekqualifier-2
functions: [PeekQualifier]
libraries: [input.device]
---

# input.device/PeekQualifier

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PeekQualifier -- get the input device's current qualifiers (V36)

   SYNOPSIS
	qualifier = PeekQualifier()
	d0

	[UWORD](autodocs-3.5/include-exec-types-h.md) PeekQualifier( VOID );

   FUNCTION
	This function takes a snapshot of what the input device thinks
	the current qualifiers are.

   RESULTS
	qualifier - a word with the following bits set according to
	    what the input device knows their state to be:
		IEQUALIFIER_LSHIFT, IEQUALIFIER_RSHIFT,
		IEQUALIFIER_CAPSLOCK, IEQUALIFIER_CONTROL,
		IEQUALIFIER_LALT, IEQUALIFIER_RALT,
		IEQUALIFIER_LCOMMAND, IEQUALIFIER_RCOMMAND,
		IEQUALIFIER_LEFTBUTTON, IEQUALIFIER_RBUTTON,
		IEQUALIFIER_MIDBUTTON

   NOTE
	This function is new for V36.

   SEE ALSO
	[devices/inputevent.h](autodocs-3.5/include-devices-inputevent-h.md)

---

## See Also

- [PeekQualifier — input.device](../autodocs/input.device.md#peekqualifier)
