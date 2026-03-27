---
title: 6 / Setting Up Menus / Toggle Selection
manual: libraries
chapter: libraries
section: 6-setting-up-menus-toggle-selection
functions: []
libraries: []
---

# 6 / Setting Up Menus / Toggle Selection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some of the checkmarked menu items may be of the toggle select type.  Each
time the user accesses such an item, it changes state, selected or
unselected.  To make an attribute item toggle select, set both the [CHECKIT](libraries/6-menu-data-structures-menuitem-flags.md)
and the [MENUTOGGLE](libraries/6-menu-data-structures-menuitem-flags.md) flags for that menu item.  Of course, the [CHECKED](libraries/6-menu-data-structures-menuitem-flags.md) flag
may be preset to the desired initial state.

