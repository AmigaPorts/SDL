---
title: intuition.library/OffMenu
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-offmenu-2
functions: [OnMenu, ResetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/OffMenu

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OffMenu -- [Disable](autodocs-3.5/exec-library-disable-2.md) the given menu or menu item.

    SYNOPSIS
	OffMenu( [Window](autodocs-3.5/include-intuition-intuition-h.md), MenuNumber )
		 A0      D0

	VOID OffMenu( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	This command disables a sub-item, an item, or a whole menu.
	This depends on the contents of the data packed into MenuNumber,
	which is described in the Intuition Reference Manual.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window
	MenuNumber = the menu piece to be disabled

    RESULT
	None

    BUGS

    SEE ALSO
	[OnMenu()](autodocs-3.5/intuition-library-onmenu-2.md), [ResetMenuStrip()](autodocs-3.5/intuition-library-resetmenustrip-2.md)

---

## See Also

- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
