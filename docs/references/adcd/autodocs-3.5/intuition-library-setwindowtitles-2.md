---
title: intuition.library/SetWindowTitles
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setwindowtitles-2
functions: [OpenScreen, OpenWindow, RefreshWindowFrame, SetWindowTitles]
libraries: [intuition.library]
---

# intuition.library/SetWindowTitles

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetWindowTitles -- Set the window's titles for both window and screen.

    SYNOPSIS
	SetWindowTitles( [Window](autodocs-3.5/include-intuition-intuition-h.md), WindowTitle, ScreenTitle )
			 A0      A1           A2

	VOID SetWindowTitles( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) * );

    FUNCTION
	Allows you to set the text which appears in the [Window](autodocs-3.5/include-intuition-intuition-h.md) and/or [Screen](autodocs-3.5/include-intuition-screens-h.md)
	title bars.

	The window title appears at all times along the window title bar.
	The window's screen title appears at the screen title bar whenever
	this window is the active one.

	When this routine is called, your window title will be changed
	immediately.  If your window is the active one when this routine is
	called, the screen title will be changed immediately.

	You can specify a value of -1 (i.e. (UBYTE *) ~0) for either of
	the title pointers.  This designates that you want Intuition to leave
	the current setting of that particular title alone, and modify
	only the other one.  Of course, you could set both to -1.

	Furthermore, you can set a value of 0 (zero) for either of the
	title pointers.  Doing so specifies that you want no title to
	appear (the title bar will be blank).

	Both of the titles are rendered in the default font of the window's
	screen, as set using [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md).

	In setting the window's title, Intuition may do some other rendering
	in the top border of your window.  If your own rendering sometimes
	appears in your window border areas, you may want to restore the entire
	window border frame.  The function SetWindowTitles() does not do this
	in the newer versions.  The function [RefreshWindowFrame()](autodocs-3.5/intuition-library-refreshwindowframe-2.md) is provided
	to do this kind of thing for you.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to your window structure
	WindowTitle = pointer to a null-terminated text string, or set to
```c
           either the value of -1 (negative one) or 0 (zero)
```
	ScreenTitle = pointer to a null-terminated text string, or set to
```c
           either the value of -1 (negative one) or 0 (zero)

    RESULT
```
	None

    BUGS

    SEE ALSO
	[OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md), [RefreshWindowFrame()](autodocs-3.5/intuition-library-refreshwindowframe-2.md), [OpenScreen()](autodocs-3.5/intuition-library-openscreen-2.md)

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [RefreshWindowFrame — intuition.library](../autodocs/intuition.library.md#refreshwindowframe)
- [SetWindowTitles — intuition.library](../autodocs/intuition.library.md#setwindowtitles)
