---
title: intuition.library/OnMenu
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-onmenu
functions: [OffMenu, ResetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/OnMenu

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OnMenu -- Enable the given menu or menu item.
SYNOPSIS

```c
    OnMenu( [Window](autodocs-2.0/includes-intuition-intuition-h.md), MenuNumber )
            A0      D0

    VOID OnMenu( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD );
```
FUNCTION

    This command enables a sub-item, an item, or a whole menu.
    This depends on the contents of the data packed into MenuNumber,
    which is described in the Intuition Reference Manual.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window
    MenuNumber = the menu piece to be enables
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OffMenu()](autodocs-2.0/intuition-library-offmenu.md), [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md)
```

---

## See Also

- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
