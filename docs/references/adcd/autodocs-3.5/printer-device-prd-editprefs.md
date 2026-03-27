---
title: printer.device/PRD_EDITPREFS
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-editprefs
functions: [DoIO]
libraries: [exec.library]
---

# printer.device/PRD_EDITPREFS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_EDITPREFS - open the driver preferences window (V44)

   FUNCTION
	New drivers can have own preferences. This commands ask the driver
	to open a window to allow the user to change the prefs. Typically
	this is done with an [DoIO()](autodocs-3.5/exec-library-doio-2.md) call.

	Every application should have a button "Driver Options..." (that
	calls PRD_EDITPREFS) in its printer dialog.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible.
	io_Command	PRD_EDITPREFS
	io_Flags	IOB_QUICK set if quick I/O is possible.
	io_TagList	a list of tags to specify more parameters

	The following tags are currently defined:

	PPRA_Window (struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *)	a pointer to a window. This prefs
		window will open on the same screen and lock the window from
		user input.
	PPRA_Screen (struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *)	a pointer to a screen. That can be
		used if no window is open.
	PPRA_PubScreen (STRPTR)	a name of a public screen that will be used
		to open the window. This can be NULL to use the default
		public screen.

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
