---
title: 6 / About Menus / Menu Limitations
manual: libraries
chapter: libraries
section: 6-about-menus-menu-limitations
functions: []
libraries: []
---

# 6 / About Menus / Menu Limitations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menus are not layered so they lock the screen while they are displayed.
While the screen is locked, applications cannot render graphics into that
screen--any rendering will be suspended until the menus are no longer
displayed.

Menus can only display a limited number of choices.  Each window may have
up to 31 menus, each menu may have up to 63 items, and each item may have
up to 31 sub-items.

Menus always appear at the top of the screen and cannot be repositioned or
sized by the user.  Moving the pointer to the menu bar may be inconvenient
or time consuming for the user.  (This is why it is generally a good idea
to provide keyboard alternatives for menu items.)  If some application has
a function that the user will be performing repeatedly, it may be better
to use a series of gadgets in the window (or a separate window) rather
than a menu item.

 [Alternatives to Menus](libraries/6-menu-limitations-alternatives-to-menus.md) 

