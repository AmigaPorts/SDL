---
title: 10 / The Keyboard / Menu Shortcuts
manual: libraries
chapter: libraries
section: 10-the-keyboard-menu-shortcuts
functions: []
libraries: []
---

# 10 / The Keyboard / Menu Shortcuts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menu items and sub-items may be paired with command key sequences to
associate certain characters with specific menu item selections. This
gives the user a shortcut method to select frequently used menu
operations, such as Undo, Cut, and Paste. Whenever the user presses the
right Amiga key with an alphanumeric key, the menu strip of the active
window is scanned to see if there are any command key sequences in the
list that match the sequence entered by the user. If there is a match,
Intuition translates the key combination into the appropriate menu item
number and transmits the menu number to the application program.


```c
    Menu Shortcuts Look Like the Real Thing.
    ----------------------------------------
    To the application it looks as if the user had selected a given
    menu item with the mouse. The program will receive a menu event, not
    a key event. For more information on menu item selection, see the
    "[Intuition Menus](libraries/6-setting-up-menus-menu-selection-messages.md)" chapter.
```
