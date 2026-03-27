---
title: intuition.library/LockPubScreen
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-lockpubscreen-2
functions: [CloseWindow, GetScreenData, LockPubScreen, OpenWindow, UnlockPubScreen]
libraries: [intuition.library]
---

# intuition.library/LockPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LockPubScreen -- Prevent a public screen from closing. (V36)

    SYNOPSIS
	screen = LockPubScreen( Name )
	D0                      A0

	struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *LockPubScreen( [UBYTE](autodocs-3.5/include-exec-types-h.md) * );

    FUNCTION
	Prevents a public screen (or the Workbench) from closing
	while you examine it in preparation of opening a visitor window.

	The sequence you use to open a visitor window that needs to
	examine fields in the screen it is about to open on is:
		LockPubScreen()
		... examine fields ...
		[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) on public screen
		[UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md)
		... use your window ...
		[CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)

    NOTE 
	You needn't hold the "pubscreen lock" for the duration that
	your window is opened.  LockPubScreen() basically has the
	same effect as an open visitor window: it prevents the
	screen from being closed.

	If you pass the string "Workbench" or you pass NULL and there
	is no default public screen, the Workbench screen will
	be automatically opened if it is not already present.

    INPUTS
	Name = name string for public screen or NULL for default public
	screen.  The string "Workbench" indicates the Workbench
	screen.

    RESULT
	Returns pointer to a screen, if successful, else NULL.
	The call can fail for reasons including that the named
	public screen doesn't exist or is in private state.

    BUGS

    SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), [UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md), [GetScreenData()](autodocs-3.5/intuition-library-getscreendata-2.md)

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
