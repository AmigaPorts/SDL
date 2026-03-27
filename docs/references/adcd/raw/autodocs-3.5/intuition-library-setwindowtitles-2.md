# intuition.library/SetWindowTitles



    NAME
	SetWindowTitles -- Set the window's titles for both window and screen.

    SYNOPSIS
	SetWindowTitles( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), WindowTitle, ScreenTitle )
			 A0      A1           A2

	VOID SetWindowTitles( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) * );

    FUNCTION
	Allows you to set the text which appears in the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) and/or [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132)
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
	screen, as set using [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html).

	In setting the window's title, Intuition may do some other rendering
	in the top border of your window.  If your own rendering sometimes
	appears in your window border areas, you may want to restore the entire
	window border frame.  The function SetWindowTitles() does not do this
	in the newer versions.  The function [RefreshWindowFrame()](../Includes_and_Autodocs_3._guide/node03DE.html) is provided
	to do this kind of thing for you.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to your window structure
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
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html), [RefreshWindowFrame()](../Includes_and_Autodocs_3._guide/node03DE.html), [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html)

