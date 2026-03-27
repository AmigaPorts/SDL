---
title: 6 / About Menus / The Menu System
manual: libraries
chapter: libraries
section: 6-about-menus-the-menu-system
functions: []
libraries: []
---

# 6 / About Menus / The Menu System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To activate the menu system, the user presses the menu button (the right
mouse button).  This displays the menu bar in the screen's title area.
The menu bar displays a list of topics (called menus) that have menu items
associated with them (see figure).  The menu bar and menu items only
remain visible while the menu button is held down.


```c
     [Figure 6-1: Screen with Menu Bar Displayed](libraries/lib-pics-6-1-pic.md) 
```
When the mouse pointer is moved onto one of the menus in the menu bar, a
list of menu items appears below the menu.  The user can move the pointer
within the list of menu items while holding down the menu button.  A menu
item will highlight when the pointer is over it and, if the item has a
sub-item list, that list will be displayed.

The specific menu that is displayed belongs to the active window. Changing
the active window will change the menu bar and the choices available to
the user.

Unlike some other systems, the Amiga has no "standard menu" that appears
in every menu bar.  In fact, a window need not have any menus at all, thus
holding down the mouse menu button does not guarantee the appearance of a
menu bar.  Although there is no "standard menu", Amiga, Inc. does have a
well-defined set of standards for menu design.  These standards are
covered in The Amiga User Interface Style Guide (also from Addison-Wesley).

 [Selecting Menu Items](libraries/6-the-menu-system-selecting-menu-items.md)    [Menu Item Imagery](libraries/6-the-menu-system-menu-item-imagery.md) 

