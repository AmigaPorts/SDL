---
title: dos.library/SetMode
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setmode-2
functions: [SetMode]
libraries: [dos.library]
---

# dos.library/SetMode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetMode - Set the current behavior of a handler (V36)

   SYNOPSIS
	success = SetMode(fh, mode)
	D0                D1  D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetMode(BPTR, LONG)

   FUNCTION
	SetMode() sends an ACTION_SCREEN_MODE packet to the handler in
	question, normally for changing a CON: handler to raw mode or
	vice-versa.  For CON:, use 1 to go to RAW: mode, 0 for CON: mode.

   INPUTS
	fh   - filehandle
	mode - The new mode you want

   RESULT
	success - Boolean

   SEE ALSO

---

## See Also

- [SetMode — dos.library](../autodocs/dos.library.md#setmode)
