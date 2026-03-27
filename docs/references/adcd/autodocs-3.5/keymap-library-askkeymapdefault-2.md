---
title: keymap.library/AskKeyMapDefault
manual: autodocs-3.5
chapter: autodocs-3.5
section: keymap-library-askkeymapdefault-2
functions: [AskKeyMapDefault, SetKeyMapDefault]
libraries: [keymap.library]
---

# keymap.library/AskKeyMapDefault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AskKeyMapDefault -- Ask for a pointer to the current default
	                    keymap. (V36)

   SYNOPSIS
	keyMap = AskKeyMapDefault()

	struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *AskKeyMapDefault( VOID );

   FUNCTION
	Return a pointer to the keymap used by the keymap library for
	[MapRawKey](autodocs-3.5/keymap-library-maprawkey-2.md) and [MapANSI](autodocs-3.5/keymap-library-mapansi-2.md) when a keymap is not specified.

   RESULTS
	keyMap - a pointer to a keyMap structure.  This key map is
	    guaranteed to be permanently allocated: it will remain in
	    memory till the machine is reset.

   BUGS
	The keymap.h include file should be in the libraries/ or perhaps
	resources/ directory, but is in the devices/ directory for
	compatibility reasons.

   SEE ALSO
	[devices/keymap.h](autodocs-3.5/include-devices-keymap-h.md), [keymap.library/SetKeyMapDefault()](autodocs-3.5/keymap-library-setkeymapdefault-2.md),
	console.device ...KEYMAP functions

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
- [SetKeyMapDefault — keymap.library](../autodocs/keymap.library.md#setkeymapdefault)
