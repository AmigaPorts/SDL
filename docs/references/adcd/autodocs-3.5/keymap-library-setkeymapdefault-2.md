---
title: keymap.library/SetKeyMapDefault
manual: autodocs-3.5
chapter: autodocs-3.5
section: keymap-library-setkeymapdefault-2
functions: [AskKeyMapDefault]
libraries: [keymap.library]
---

# keymap.library/SetKeyMapDefault

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetKeyMapDefault -- Set the current default keymap. (V36)

   SYNOPSIS
	SetKeyMapDefault(keyMap)

	void SetKeyMapDefault( struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) * );

   FUNCTION
	A pointer to key map specified is cached by the keymap library
	for use by [MapRawKey](autodocs-3.5/keymap-library-maprawkey-2.md) and [MapANSI](autodocs-3.5/keymap-library-mapansi-2.md) when a keymap is not specified.

   INPUTS
	keyMap - a pointer to a keyMap structure.  This key map must be
	    permanently allocated: it must remain in memory till the
	    machine is reset.  It is appropriate that this keyMap be a
	    node on the keymap.resource list.

   BUGS
	The keymap.h include file should be in the libraries/ or perhaps
	resources/ directory, but is in the devices/ directory for
	compatability reasons.

   SEE ALSO
	[devices/keymap.h](autodocs-3.5/include-devices-keymap-h.md), [keymap.library/AskKeyMapDefault()](autodocs-3.5/keymap-library-askkeymapdefault-2.md),
	console.device ...KEYMAP functions

---

## See Also

- [AskKeyMapDefault — keymap.library](../autodocs/keymap.library.md#askkeymapdefault)
