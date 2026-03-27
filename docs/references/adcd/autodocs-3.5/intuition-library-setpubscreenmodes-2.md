---
title: intuition.library/SetPubScreenModes
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setpubscreenmodes-2
functions: [OpenScreen]
libraries: [intuition.library]
---

# intuition.library/SetPubScreenModes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetPubScreenModes -- Establish global public screen behavior. (V36)

    SYNOPSIS
	OldModes = SetPubScreenModes( Modes )
	D0                            D0

	[UWORD](autodocs-3.5/include-exec-types-h.md) SetPubScreenModes( [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
    	Sets GLOBAL Intuition public screen modes.	

    INPUTS
	Modes = new global modes flags.  Values for flag bits are:
	  SHANGHAI: workbench windows are to be opened on the
		default public screen
	  POPPUBSCREEN: when a visitor window is opened, the public
		screen it opens on is to be brought to the front.

    RESULT
	OldModes = previous global mode settings

    BUGS

    SEE ALSO
	[OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
