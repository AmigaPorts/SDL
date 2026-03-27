---
title: intuition.library/WindowLimits
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-windowlimits-2
functions: [LockPubScreen, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/WindowLimits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	WindowLimits -- Set the minimum and maximum limits of a window.

    SYNOPSIS
	Success = WindowLimits( [Window](autodocs-3.5/include-intuition-intuition-h.md), MinWidth, MinHeight, MaxWidth,
	D0		        A0      D0        D1         D2
	                        MaxHeight )
	                        D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) WindowLimits( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, WORD, WORD, [UWORD](autodocs-3.5/include-exec-types-h.md), [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Sets the minimum and maximum limits of the window's size.  Until this
	routine is called, the window's size limits are equal to the initial
	values established in the [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) function.

	After a call to this routine, the [Window](autodocs-3.5/include-intuition-intuition-h.md) will be able to be sized
	to any dimensions within the specified limits.

	If you don't want to change any one of the dimensions, set the limit
	argument for that dimension to zero.  If any of the limit arguments
	is equal to zero, that argument is ignored and the initial setting
	of that parameter remains undisturbed.

	If any of the arguments is out of range (minimums greater than the
	current size, maximums less than the current size), that limit
	will be ignored, though the others will still take effect if they
	are in range.  If any are out of range, the return value from this
	procedure will be FALSE.  If all arguments are valid, the return
	value will be TRUE.

	If you want your window to be able to become "as large as possible"
	you may put -1 (i.e. ~0) in either or both Max arguments.  But
	please note: screen sizes may vary for several reasons, and you
	must be able to handle any possible size of window you might end
	up with if you use this method.  Note that you can use the function
	[LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md) to find out how big the screen your window will
	appear in is.  You may also refer to the WScreen field in your
	window structure, providing that your window remains open,
	which will ensure that the screen remains open, and thus the
	pointer remains valid.

	If the user is currently sizing this window, the new limits will
	not take effect until after the sizing is completed.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure
	MinWidth, MinHeight, MaxWidth, MaxHeight = the new limits for the size
            of this window.  If any of these is set to zero, it will
            be ignored and that setting will be unchanged.

    RESULT
	Returns TRUE if everything was in order.  If any of the parameters was
	out of range (minimums greater than current size, maximums less than
	current size), FALSE is returned and the errant limit request is
	not fulfilled (though the valid ones will be).

    BUGS

    SEE ALSO
	[LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md)

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
