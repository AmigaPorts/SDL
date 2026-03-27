---
title: 6 Intuition Menus / Other Menu Macros
manual: libraries
chapter: libraries
section: 6-intuition-menus-other-menu-macros
functions: []
libraries: []
---

# 6 Intuition Menus / Other Menu Macros

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [MENUNEM()](libraries/6-setting-up-menus-menu-numbers.md), [ITEMNUM()](libraries/6-setting-up-menus-menu-numbers.md) and [SUBNUM()](libraries/6-setting-up-menus-menu-numbers.md) macros let an application break a
menu number down into its component parts--the specific menu number, the
item number and the sub-item number.  (See the section on "[Menu Numbers](libraries/6-setting-up-menus-menu-numbers.md)"
earlier in this chapter for details.)  Intuition also supplies macros that
allow an application to construct a menu number given its components:

SHIFTMENU(n)

    Create a properly masked and shifted specific menu number.
SHIFTITEM(n)

    Create a properly masked and shifted item number.
SHIFTSUB(n)

    Create a properly masked and shifted sub-item number.
FULLMENUNUM( menu, item, sub )

    Create a complete composite menu number from its components.
