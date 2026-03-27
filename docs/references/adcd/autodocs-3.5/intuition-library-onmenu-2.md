---
title: intuition.library/OnMenu
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-onmenu-2
functions: [OffMenu, ResetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/OnMenu

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OnMenu -- [Enable](autodocs-3.5/exec-library-enable-2.md) the given menu or menu item.

    SYNOPSIS
	OnMenu( [Window](autodocs-3.5/include-intuition-intuition-h.md), MenuNumber )
	        A0      D0

	VOID OnMenu( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	This command enables a sub-item, an item, or a whole menu.
	This depends on the contents of the data packed into MenuNumber,
	which is described in the Intuition Reference Manual.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window
	MenuNumber = the menu piece to be enables

    RESULT
	None

    BUGS

    SEE ALSO
	[OffMenu()](autodocs-3.5/intuition-library-offmenu-2.md), [ResetMenuStrip()](autodocs-3.5/intuition-library-resetmenustrip-2.md)

---

## See Also

- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
