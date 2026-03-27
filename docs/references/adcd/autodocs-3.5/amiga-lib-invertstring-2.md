---
title: amiga.lib/InvertString
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-invertstring-2
functions: [ParseIX]
libraries: [commodities.library]
---

# amiga.lib/InvertString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InvertString -- produce input events that would generate the
			given string. (V36)

   SYNOPSIS
	events = InvertString(str,km)

	struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *InvertString(STRPTR,struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *);

   FUNCTION
	This function returns a linked list of input events which would
	translate into the string using the supplied keymap (or the system
	default keymap if 'km' is NULL).

	'str' is null-terminated and may contain:
	   - ANSI character codes
	   - backslash escaped characters:
		n   -   CR
		r   -   CR
		t   -   TAB
		0   -   illegal, do not use!
		\   -   backslash
	   - a text description of an input event as used by [ParseIX()](autodocs-3.5/commodities-library-parseix-2.md),
	     enclosed in angle brackets.

	An example is:

          abc<alt f1>nhi there.
   INPUTS
	str - null-terminated string to convert to input events
	km - keymap to use for the conversion, or NULL to use the default
	     keymap.

   RESULTS
	events - a chain of input events, or NULL if there was a problem. The
		 most likely cause of failure is an illegal description
		 enclosed in angled brackets.

		 This chain should eventually be freed using [FreeIEvents()](autodocs-3.5/amiga-lib-freeievents-2.md).

   SEE ALSO
	[commodities.library/ParseIX()](autodocs-3.5/commodities-library-parseix-2.md), [FreeIEvents()](autodocs-3.5/amiga-lib-freeievents-2.md)

---

## See Also

- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
