---
title: intuition.library/MoveWindowInFrontOf
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-movewindowinfrontof-2
functions: [MoveLayerInFrontOf, WindowToBack, WindowToFront]
libraries: [intuition.library, layers.library]
---

# intuition.library/MoveWindowInFrontOf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	MoveWindowInFrontOf -- Arrange the relative depth of a window. (V36)

    SYNOPSIS
	MoveWindowInFrontOf( [Window](autodocs-3.5/include-intuition-intuition-h.md), BehindWindow )
			     A0      A1

	VOID MoveWindowInFrontOf( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Depth-arranges a window in front of an another window.
	Brings out the layers.library [MoveLayerInFrontOf()](autodocs-3.5/layers-library-movelayerinfrontof-2.md) to the
	Intuition user.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) =  window to re-position in front of another window
	BehindWindow =  window to re-position in front of

    RESULT
	Repositions window.

    BUGS
	Doesn't respect backdrop windows.

    SEE ALSO
	[WindowToFront()](autodocs-3.5/intuition-library-windowtofront-2.md), [WindowToBack()](autodocs-3.5/intuition-library-windowtoback-2.md), [layers.library/MoveLayerInFrontOf()](autodocs-3.5/layers-library-movelayerinfrontof-2.md)

---

## See Also

- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
