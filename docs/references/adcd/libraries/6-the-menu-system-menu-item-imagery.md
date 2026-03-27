---
title: 6 / / The Menu System / Menu Item Imagery
manual: libraries
chapter: libraries
section: 6-the-menu-system-menu-item-imagery
functions: []
libraries: []
---

# 6 / / The Menu System / Menu Item Imagery

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menu items can be graphic images or text.  There is no conceptual
difference between menus that display text and menus that display images,
in fact, the two techniques may be used together.  The examples in this
chapter use text based menus to avoid the extra code required to define
images.

When the user positions the pointer over an item, the item can be
highlighted through a variety of techniques.  These techniques include a
highlighted box around the selected item, complementing the entire item
and replacing the item with an alternate image or alternate text.

Attribute items can have an image rendered next to them, usually a
checkmark, to indicate whether they are in effect or not.  The checkmark
is positioned to the left of the item.  If the checkmark is present, the
attribute is on.  If not, the attribute is off.

On the right side of menu items, command key alternatives may be
displayed.  Command key alternatives allow the user to make menu
selections with the keyboard instead of the mouse.  This is done by
holding down the right Amiga key and then pressing the single character
command key alternative listed next to the menu item.  Command key
alternatives appear as a reverse video, fancy "A", followed by the single
character command key.

Menu items or whole menus may be enabled or disabled.  Disabling an item
prevents the user from selecting it.  Disabled items are ghosted
(overwritten with a pattern of dots making the image less distinct) in
order to distinguish them from enabled items. Menu help, a new feature of
Release 2, allows the application to be notified when the user presses the
help key at the same time the menu system is activated.  This allows
applications to provide a help feature for every item in its menus.  Menu
help may be requested on any level of a menu.

