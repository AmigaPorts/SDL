---
title: lowlevel.library/GetKey
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-getkey
functions: []
libraries: []
---

# lowlevel.library/GetKey

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetKey -- returns the currently pressed rawkey code and qualifiers.
		  (V40)

   SYNOPSIS
	key = GetKey();
	D0

	ULONG GetKey(VOID);

   FUNCTION
	This function returns the currently pressed non-qualifier key and
	all pressed qualifiers.

	This function is safe within an interrupt.

	This is a low level function that does not fit the normal Amiga
	multitasking model. The values returned by this function are
	not modified by which window/screen currently has input focus.

   RESULT
	key - key code for the last non-qualifier key pressed in the low
	      order word. If no key is pressed this word will be FF. The
	      upper order word contains the qualifiers which can be found
	      within the long word as follows:
	                Qualifier               Key
	                LLKB_LSHIFT             Left Shift
	                LLKB_RSHIFT             Rigt Shift
	                LLKB_CAPSLOCK           Caps [Lock](autodocs-3.5/dos-library-lock-2.md)
	                LLKB_CONTROL            Control
	                LLKB_LALT               Left Alt
	                LLKB_RALT               Right Alt
	                LLKB_LAMIGA             Left Amiga
	                LLKB_RAMIGA             Right Amiga

   SEE ALSO
	[<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md)

