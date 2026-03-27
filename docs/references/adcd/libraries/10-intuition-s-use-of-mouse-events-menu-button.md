---
title: 10 / / Intuition's Use of Mouse Events / Menu Button
manual: libraries
chapter: libraries
section: 10-intuition-s-use-of-mouse-events-menu-button
functions: []
libraries: []
---

# 10 / / Intuition's Use of Mouse Events / Menu Button

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The right mouse button is used to initiate and control information
gathering processes.  Intuition uses this button most often for menu
operations.

For most active windows, pressing the menu button will display the
window's menu bar at the top of the screen.  Dragging the mouse with the
menu button depressed allows the user to browse through the available
menus.  Releasing the right mouse button over a menu item will select that
item, if it is a valid choice.  Additionally, the user can select multiple
items by repeatedly pressing the select button while the menu button is
held down.

Drag selection is also available in menu operations.  When the menu system
is activated, and the user has the menu button pressed, the select button
may be pressed and the mouse dragged over all items to be selected.  This
only works if the select button is pressed after the menu button, and all
items that the pointer travels over will be selected.

Double clicking the right mouse button can bring up a special requester
for extended exchange of information.  This requester is called the
double-menu requester, because a double click of the menu button is
required to reveal it, and because this requester acts like a super menu
through which a complex exchange of information can take place. Because
the requester is used for the transfer of information, it is appropriate
that this mechanism is called up by using the right button.

The programmer should consult the Amiga User Interface Style Guide for
more information on the standard uses of the mouse and its buttons.

Button activation and mouse movements can be combined to create compound
instructions.  For example, Intuition combines multiple mouse events when
displaying the menu system.  While the right button is pressed to reveal
the menu items of the active window, the user can move the mouse to
position the pointer and display different menu items and sub-items.
Additionally, multiple presses of the left button can be used to select
more than one option from the menus.

Dragging can have different effects, depending on the object being
dragged.  Dragging a window by the drag gadget will change the position of
the window.  Dragging a window by the sizing gadget will change the size
of the window.  Dragging a range in a Workbench window will select all of
the icons in the rectangular range.

