---
title: 6 / Setting Up Menus / Enabling and Disabling Menus and Menu Items
manual: libraries
chapter: libraries
section: 6-setting-up-menus-enabling-and-disabling-menus-and-menu
functions: [ClearMenuStrip, OffMenu, OnMenu, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Enabling and Disabling Menus and Menu Items

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Disabling menu items makes them unavailable for selection by the user.

Disabled menus and menu items are displayed in a ghosted fashion; that is,
their imagery is overlaid with a faint pattern of dots, making it less
distinct.

Enabling or disabling a menu or menu item is always a safe procedure,
whether or not the user is currently using the menus.  Of course, by the
time you have disabled the item, the user may have already selected it.
Thus, the program may receive a [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message for that item, even
though it considers the item disabled.  The program should be prepared to
handle this case and ignore items that it knows are already disabled.
This implies that the program must track internally which items are
enabled and which are disabled.

The [OffMenu()](autodocs-2.0/intuition-library-offmenu.md) and [OnMenu()](autodocs-2.0/intuition-library-onmenu.md) functions may be used to enable or disable
items while a menu strip is attached to the window.


```c
    void OffMenu( struct Window *window, unsigned long menuNumber );
    void OnMenu( struct Window *window, unsigned long menuNumber );
```
These routines check if the user is currently using the menus and whether
the menus need to be redrawn to reflect the new states.  If the menus are
currently in use, these routines wait for the user to finish before
proceeding.

If the item component referenced by menuNumber equals [NOITEM](libraries/6-setting-up-menus-menu-numbers.md), the entire
menu will be disabled or enabled.  If the item component equates to an
actual component number, then that item will be disabled or enabled.  Use
the macros defined below for the construction of menu numbers from their
component parts.

The program can enable or disable whole menus, just the menu items, or
just single sub-items.

  * To enable or disable a whole menu, set the item component of the menu

```c
    number to [NOITEM](libraries/6-setting-up-menus-menu-numbers.md).  This will enable or disable all items and any
    sub-items for that menu.
```
  * To enable or disable a single item and all sub-items attached to that

```c
    item, set the item component of the menu number to the item's ordinal
    number.  If the item has a sub-item list, set the sub-item component
    of the menu number to [NOSUB](libraries/6-setting-up-menus-menu-numbers.md).  If the item has no sub-item list, the
    sub-item component of the menu number is ignored.
```
  * To enable or disable a single sub-item, set the item and sub-item

    components appropriately.
It is also legal to remove the menu strip from each window that it is
attached to (with [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) ) change the [ITEMENABLED](libraries/6-menu-data-structures-menuitem-flags.md) or [MENUENABLED](libraries/6-menu-data-structures-menu-structure.md)
flag of one or more [Menu](libraries/6-menu-data-structures-menu-structure.md) or [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures and add the menu back
using [ResetMenuStrip()](libraries/6-setting-up-menus-changing-menu-strips.md) (in V36 or higher) or [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) (in any
version of the OS).

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
