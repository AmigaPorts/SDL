---
title: 6 / / The Menu System / Selecting Menu Items
manual: libraries
chapter: libraries
section: 6-the-menu-system-selecting-menu-items
functions: []
libraries: []
---

# 6 / / The Menu System / Selecting Menu Items

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To select a single menu item, the user releases the menu button when the
pointer is over the desired item.  Intuition can notify your program
whenever the user makes a menu selection by sending an IDCMP message to
your window's [UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md).  Your application is then responsible for carrying
out the action associated with the menu item selected.  Action items lead
to actions taken by the program while attribute items set values in the
program for later reference.

Menu selection is restricted to the most subordinate item.  Top level
menus are never selected.  A menu item can be selected as long as it has
no sub-items, and a sub-item may always be selected.  (Of course, disabled
menu items and sub-items cannot be selected.) Intuition menus allow the
user to select multiple items by:

  * Pressing and releasing the select button (left mouse button) without

    releasing the menu button.  This selects the item and keeps the menus
    active so that other items may be selected.
  * Holding down both mouse buttons and sliding the pointer over several

    items.  This is called drag selecting.  All items highlighted while
    dragging are selected.
Drag selection, single selection with the select button and releasing the
mouse button over an item can all be combined in a single operation.  Any
technique used to select a menu item is also available to select a menu
sub-item.

