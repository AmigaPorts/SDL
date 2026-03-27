---
title: commodities.library/InvertKeyMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-invertkeymap-2
functions: [MapANSI]
libraries: [keymap.library]
---

# commodities.library/InvertKeyMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InvertKeyMap -- generate an input event from an ANSI code. (V36)

   SYNOPSIS
	success = InvertKeyMap(ansiCode,event,km)
	D0	 	       D0       A0    A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) InvertKeyMap(ULONG,struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *,struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *);

   FUNCTION
	This function uses the system call [MapANSI()](autodocs-3.5/keymap-library-mapansi-2.md) to figure out what
	[InputEvent](autodocs-3.5/include-devices-inputevent-h.md) translates to an ANSI character code 'ansiCode'. The
	[InputEvent](autodocs-3.5/include-devices-inputevent-h.md) pointed to by 'event' is filled in with that information.
	The [KeyMap](autodocs-3.5/include-devices-keymap-h.md) 'km' is used for the translation, unless it is NULL, in
	which case the current system default keymap is used.

   INPUTS
	ansiCode - the ANSI code to convert to an input event
	event - the [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) to fill-in
	km - the keymap to use for the translation, or NULL to use the
	     current system default keymap.

   RESULTS
	success - TRUE if the translation worked, FALSE otherwise.

   BUGS
	This function currently handles one-deep dead keys (such as
	<alt f>o ). It does not look up the high key map (keystrokes
	with scan codes greater than 0x40).

	Prior to V40, this function was not initializing the ie_SubClass
	and ie_TimeStamp fields of the [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) structure. A simple work
	around to the problem is to clear these values to 0 before making
	a call to this function:

		struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) ie;

		    ie.ie_SubClass           = 0;
		    ie.ie_TimeStamp.tv_secs  = 0;
		    ie.ie_TimeStamp.tv_micro = 0;
		    if (InvertKeyMap(ansiCode,&ie,NULL))
		    ...

   SEE ALSO
	[cx_lib/InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md)

---

## See Also

- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
