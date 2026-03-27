---
title: intuition.library/OffMenu
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-offmenu
functions: [OnMenu, ResetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/OffMenu

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OffMenu -- Disable the given menu or menu item.
SYNOPSIS

```c
    OffMenu( [Window](autodocs-2.0/includes-intuition-intuition-h.md), MenuNumber )
             A0      D0

    VOID OffMenu( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, UWORD );
```
FUNCTION

    This command disables a sub-item, an item, or a whole menu.
    This depends on the contents of the data packed into MenuNumber,
    which is described in the Intuition Reference Manual.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window
    MenuNumber = the menu piece to be disabled
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OnMenu()](autodocs-2.0/intuition-library-onmenu.md), [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md)
```

---

## See Also

- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
