---
title: 15 / GadTools Menus / Restrictions on GadTools Menus
manual: libraries
chapter: libraries
section: 15-gadtools-menus-restrictions-on-gadtools-menus
functions: [ClearMenuStrip, OffMenu, OnMenu, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 15 / GadTools Menus / Restrictions on GadTools Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GadTools menus are regular Intuition menus.  Once the menus have been laid
out, the program may do anything with them, including attaching them or
removing them from windows, enabling or disabling items, checking or
unchecking checkmarked menu items, etc.  See the documentation for
[SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md), [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md), [ResetMenuStrip()](libraries/6-setting-up-menus-changing-menu-strips.md), [OnMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md) and [OffMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md)
in the "Intuition Menus" chapter for full details.

If a GadTools-created menu strip is not currently attached to any window,
the program may change the text in the menu headers ([Menu->MenuName](libraries/6-menu-data-structures-menu-structure.md)), the
command-key equivalents ([MenuItem->Command](libraries/6-menu-data-structures-menuitem-structure.md)) or the text or imagery of menu
items and sub-items, which can be reached as:

```c
    ((struct IntuiText *)MenuItem->ItemFill)->IText
```
or

```c
    ((struct Image *)MenuItem->ItemFill)
```
The application may also link in or unlink menus, menu items or sub-items.
However, do not add sub-items to a menu item that was not created with
sub-items and do not remove all the sub-items from an item that was
created with some.

Any of these changes may be made, provided the program subsequently calls
[LayoutMenus()](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md) or [LayoutMenuItems()](libraries/15-functions-for-gadtools-menus-layout-for-individual-menus.md) as appropriate.  Then, reattach the
menu strip using [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

Some of these manipulations require walking the menu strip using the usual
Intuition-specified linkages.  Beginning with the first [Menu](libraries/6-menu-data-structures-menu-structure.md) structure,
simply follow its [FirstItem](libraries/6-menu-data-structures-menu-structure.md) pointer to get to the first [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md).  The
[MenuItem->SubItem](libraries/6-menu-data-structures-menuitem-structure.md) pointer will lead to the sub-menus.  MenuItems are
connected via the [MenuItem->NextItem](libraries/6-menu-data-structures-menuitem-structure.md) field.  Successive menus are linked
together with the [Menu->NextMenu](libraries/6-menu-data-structures-menu-structure.md) pointer.  Again, see the chapter
"[Intuition Menus](libraries/6-setting-up-menus-menu-numbers.md)" for details.

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
