---
title: intuition.library/SetDefaultPubScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setdefaultpubscreen-2
functions: [OpenScreen, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/SetDefaultPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetDefaultPubScreen -- Choose a new default public screen. (V36)

    SYNOPSIS
	SetDefaultPubScreen( Name )
			     A0

	VOID SetDefaultPubScreen( [UBYTE](autodocs-3.5/include-exec-types-h.md) * );

    FUNCTION
	Establishes a new default public screen for visitor windows.

	This screen is used by windows asking for a named public screen
	that doesn't exist and the FALLBACK option is selected, and for
	windows asking for the default public screen directly.

    INPUTS
	Name = name of chosen public screen to be the new default.
	A value of NULL means that the Workbench screen is to
	be the default public screen.

    RESULT
	None

    BUGS

    SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md), Intuition V36 update documentation

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
