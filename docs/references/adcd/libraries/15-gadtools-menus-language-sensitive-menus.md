---
title: 15 / GadTools Menus / Language-Sensitive Menus
manual: libraries
chapter: libraries
section: 15-gadtools-menus-language-sensitive-menus
functions: [SetMenuStrip]
libraries: [intuition.library]
---

# 15 / GadTools Menus / Language-Sensitive Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Allowing the application to switch the language displayed in the menus,
can be done quite easily.  Simply detach the menu strip and replace the
strings in the [IntuiText](libraries/8-creating-text-intuitext-structure.md) structures as described above.  It may be
convenient to store some kind of index number in the [Menu](libraries/6-menu-data-structures-menu-structure.md) and [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md)
[UserData](libraries/15-gadtools-menus-the-newmenu-structure.md) which can be used to retrieve the appropriate string for the
desired language.  After all the strings have been installed, call
[LayoutMenus()](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md) and [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

If the application has the localized strings when the menus are being
created, it simply places the pointers to the strings and command
shortcuts into the appropriate fields of the [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) structure.  The menus
may then be processed in the normal way.

---

## See Also

- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
